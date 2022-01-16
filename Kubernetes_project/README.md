## virtualbox업데이트로 인한 오류가 mac os에 존재하고 있습니다. 2022/01/15
https://medium.com/dtlpub/minikube-drama-in-mac-os-331a6dc54670

이번 면접 준비를 하며 이전에 수행했던 이 프로젝트를 실행하니 손볼곳이 많더군요...
우선 vm을 hyperkit으로 변경하였습니다. 외부 아이피로 접속이 다시 가능해졌습니다.

접속 주소 검색법
~~~
minikube service [service name] 
을 수행하여 url을 알아냅니다. 알아낸 url로 접속 하시면 됩니다.
~~~

목표
쿠버네티스의 구조와 원리를 이해합니다.
쿠버네티스에 적용할 yaml 파일 작성법을 숙지합니다.
쿠버네티스 클러스터에 배포될 다양한 서비스들(Nginx, Wordpress, phpMyAdmin, MySQL, Grafana, InfluxDB, FTPS)의 설치 및 배포 방법을 숙지합니다.
기술 스택
Kubernetes, Docker, Nginx, MySQL

# 프로젝트 구성도
<img src="https://user-images.githubusercontent.com/53321189/99756721-1a537100-2b31-11eb-94a1-0cec379337bd.png" width="1000px" height="700px" title="Logo"/>
동그라미는 유저가 접근할 수 있는 것들이고, 네모는 유저는 불가, 관리자만 접근 가능합니다.

## 소개
클러스터 관리 및 Kubernetes를 사용한 배포를 학습하였습니다.
네트워크를 가상화하고 “클러스터링”을 수행 하였습니다.

## 구성 설명
서버 구성에 필요한 모든 파일을 srcs 폴더에 넣어 두었습니다..
setup.sh 파일은 저장소의 루트에 있고. 이 스크립트는 모든 응용 프로그램을 셋업합니다.

## 필수 파트
이 프로젝트는 다양한 서비스의 인프라 스트럭쳐를 설정하는 것으로 구성됩니다. 
이걸 하려면 하기 위해 Kubernetes를 사용하였고 다중 서비스 클러스터를 설정하였습니다.
각 서비스는 전용 컨테이너에서 실행됩니다.
각 컨테이너는 관련 서비스와 성능을 위해  동일한 이름을 가집니다. 
Alpine Linux를 사용하여 컨테이너를 빌드하였습니다.
또한 setup.sh에서 호출되는 Dockerfile을 작성하였습니다.
사용할 이미지를 직접 빌드했습니다.

❗이미 빌드된 이미지를 사용하거나 DockerHub와 같은 서비스를 사용하지 않았습니다.

# 클러스테에서 돌아가는 다중 서비스들 

## Kubernetes
dashboard에서 클러스터 관리를 하는 것을 쉽게 볼 수 있습니다.

## 로드 밸런서
서비스의 외부 액세스를 관리하는 로드 밸런서가 클러스터의 유일한 엔트리포인트가 될 것입니다.
반드시 서비스에 맞는 포트를 유지해야합니다(Grafana는 IP:3000처럼).
로드 밸런서는 단일 IP를 갖습니다.

## 워드프레스
워드프레스 웹 사이트는 5050 포트를 수신
워드프레스는 MySQL 데이터베이스랑 같이 작동
두 서비스 모두 별도의 컨테이너에서 실행되어야합니다.
워드프레스 웹 사이트에는 여러 사용자와 관리자를 갖습니다.
워드프레스 자체 nginx 서버가 필요합니다.
로드 밸런서는 이 서비스로 직접 리디렉션 할 수 있어야 합니다.

## phpMyAdmin
phpMyAdmin은 포트 5000 수신
phpMyAdmin은 MySQL 데이터베이스와 연결됩니다.
PhpMyAdmin에는 자체 nginx 서버가 필요합니다.
로드 밸런서는 이 서비스로 직접 리디렉션 할 수 있어야 합니다.

## nginx
nginx 서버가 있는 컨테이너는 포트 80과 443을 리스닝합니다.
포트 80은 http이고, https인 443으로의 시스템적인 리디렉션(301)이어야합니다.
표시되는 페이지는 http 오류만 아니면 중요하지 않습니다.(=오류만 아니면 맘대로)
이 컨테이너는 /wordpress 경로에 대한 접근을 허용합니다. IP:WPPORT로 리디렉션(307)하는 접근을.
또한 /phpmyadmin로의 접근을 허용해야합니다. 리버스 프록시로 IP:PMAPORT로.

## FTPS
FTPS 서버는 포트 21을 리스닝(수신 대기).

## Grafana
Grafana 플랫폼은 포트 3000을 리스닝.
Grafana 플랫폼은 InfluxDB 데이터베이스와 연결됨
Grafana는 모든 컨테이너를 모니터링합니다.
서비스 하나 당 대시 보드를 하나 만들어야합니다.
InﬂuxDB와 Grafana는 두 개의 별개 컨테이너에 있어야합니다.
data persist
두 데이터베이스 컨테이너 중 하나가 터지거나 중지되는 경우에, 데이터가 지속되는지 확인해야합니다.

## SSH
SSH에 로그인하여 nginx 컨테이너에 액세스 할 수 있어야합니다.

## restart
모든 컨테이너는 컴포넌트 중 하나가 터지거나 중지되는 경우에, 반드시 restart해야 합니다.

개발 환경 구축
brew install minikube : minikube 설치
minikube start --driver=virtualbox : virtualbox기반으로 minikube 실행
MetalLB 설치
MetalLB는 BareMetalLoadBalancer의 약자로서, 클라우드 벤더의 ip제공 없이 Loadbalancer type의 서비스를 제공할 수 있습니다.
A. Nginx 설치
Nginx란?
Nginx는 동시접속 처리에 특화된 웹 서버 프로그램입니다.
프로세스를 늘리지 않기 때문에 컴퓨터 자원을 상대적으로 적게 사용하고, 빠른 처리가 가능합니다.
Nginx 설치
Container로 배포할 Nginx의 image를 생성합니다.

Nginx 패키지를 설치합니다.
https로의 redirection기능 추가를 위해 Openssl을 활용하여 인증서를 생성합니다.
Nginx 서버 설정 파일인 default.conf 파일에 location 제어문을 추가하여 /wordpress redirection 기능과 /phpmyadmin reverse proxy 기능을 추가합니다.
Container 내부의 프로세스 상태 확인을 위해 Supervisor를 설치하여 실행합니다.
pod의 다양한 데이터를 받아서 InfluxDB에 저장하기 위해 telegraf를 설치하여 실행합니다.
Nginx는 기본적으로 background로 실행되기 때문에 foreground로 설정하여 실행합니다.
(background로 실행 시에 Container는 Nginx 프로세스를 인지하지 못함)
B. Wordpress 설치
Wordpress란?
Wordpress는 세계 최대의 오픈소스 저작물 관리 시스템입니다. 우리나라의 서울특별시 홈페이지가 Wordpress기반으로 만들어졌습니다.
Wordpress 설치
Container로 배포할 Wordpress의 image를 생성합니다.

alpine에서 Wordpress 설치를 위해 제공되는 패키지가 없기 때문에 https://wordpress.org/latest.tar.gz링크에서 직접 다운로드 받습니다.
Wordpress 구동에 필요한 php 모듈을 설치합니다.
Nginx 설정 파일인 default.conf 파일에 location 제어문을 추가하여 php-fpm으로의 redirection 기능을 넣어줍니다.
(동적 웹사이트로의 요청을 처리하기 위함)
Container 내부의 프로세스 상태 확인을 위해 Supervisor를 설치하여 실행합니다.
pod의 다양한 데이터를 받아서 InfluxDB에 저장하기 위해 telegraf를 설치하여 실행합니다.
wordpress.yaml 파일 내에서 configmap을 추가하여 데이터베이스와의 연동을 위한 wp-config.php 파일을 만듭니다.
C. phpMyAdmin 설치
phpMyAdmin이란?
phpMyAdmin은 MySQL 데이터베이스를 월드 와이드 웹 상에서 관리할 목적으로 PHP로 작성한 오픈 소스 도구입니다.
phpMyAdmin 설치
Container로 배포할 phpMyAdmin의 image를 생성합니다.

alpine에서 phpMyAdmin 설치를 위해 제공되는 패키지가 없기 때문에https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-all-languages.tar.gz링크에서 직접 다운로드 받습니다.
phpMyAdmin 구동에 필요한 php 모듈을 설치합니다.
Nginx 설정 파일인 default.conf 파일에 location 제어문을 추가하여 php-fpm으로의 redirection 기능을 넣어줍니다.
(동적 웹사이트로의 요청을 처리하기 위함)
Container 내부의 프로세스 상태 확인을 위해 Supervisor를 설치하여 실행합니다.
pod의 다양한 데이터를 받아서 InfluxDB에 저장하기 위해 telegraf를 설치하여 실행합니다.
MySQL 서버와의 연동을 위해 config.inc.php 파일을 수정합니다.
D. MySQL 설치
MySQL이란?
MySQL은 오픈 소스의 관계형 데이터베이스 관리 시스템(RDBMS)입니다.
MySQL 설치
Container로 배포할 MySQL의 image를 생성합니다.

이번 과제에서는 MySQL 서버와 클라이언트가 같은 pod내에서 관리되기 때문에 서버와 클라이언트를 모두 설치합니다.
MySQL 서버 설정을 위해 my.cnf 디렉토리에 있는 server.conf 파일을 수정합니다.
pod의 다양한 데이터를 받아서 InfluxDB에 저장하기 위해 telegraf를 설치하여 실행합니다.
Container 내부의 프로세스 상태 확인을 위해 mysql.yaml파일에 livenessProbe 기능을 추가합니다.
pod가 재생성되어도 데이터베이스의 데이터 유지를 위해 mysql.yaml파일에 PVC(Persistent Volume Claim)를 선언합니다.
E. Grafana 설치
Grafana란?
Grafana는 메트릭 데이터를 시각화하는데 가장 최적화된 대시보드를 제공하는 오픈소스 메트릭 데이터 시각화 도구입니다.
Grafana 설치
Container로 배포할 Grafana의 image를 생성합니다.

Grafana 패키지를 설치합니다.
Container 내부의 프로세스 상태 확인을 위해 Supervisor를 설치하여 실행합니다.
pod의 다양한 데이터를 받아서 InfluxDB에 저장하기 위해 telegraf를 설치하여 실행합니다.
F. InfluxDB 설치
InfluxDB란?
InfluxDB는 인플럭스데이터가 개발한 오픈 소스 시계열 데이터베이스(TSDB)입니다.
InfluxDB 설치
Container로 배포할 InfluxDB의 image를 생성합니다.

InfluxDB 패키지를 설치합니다.
Container 내부의 프로세스 상태 확인을 위해 Supervisor를 설치하여 실행합니다.
pod의 다양한 데이터를 받아서 InfluxDB에 저장하기 위해 telegraf를 설치하여 실행합니다.(host는 localhost로 설정)
pod가 재생성되어도 데이터베이스의 데이터 유지를 위해 influxdb.yaml파일에 PVC(Persistent Volume Claim)를 선언합니다.
G. FTPS 설치
FTPS란?
FTP(File Transfer Protocol)는 TCP/IP 프로토콜을 가지고 서버와 클라이언트 사이의 파일 전송을 하기 위한 프로토콜입니다.
FTPS는 기존의 FTP에 전송 계층 보안(TLS)과 보안 소켓 계층(SSL) 암호화 프로토콜에 대한 지원이 추가된 프로토콜입니다.
FTPS 설치
Container로 배포할 FTPS의 image를 생성합니다.

FTPS 서버 프로그램인 vsftpd 패키지를 설치합니다.
pod의 다양한 데이터를 받아서 InfluxDB에 저장하기 위해 telegraf를 설치하여 실행합니다.
Openssl을 활용하여 인증서를 생성합니다.
