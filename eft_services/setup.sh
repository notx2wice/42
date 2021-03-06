#!/bin/bash

# export MINIKUBE_HOME=~/goinfre
export MINIKUBE_HOME=$HOME
# # SETUP_LOG=~/42cursus/ft_services/setup.log
SETUP_LOG=~/42cursus/ft_services/setup.log

minikube delete

#start minikube with docker.
minikube start --driver=virtualbox --hyperv-virtual-switch "Primary Virtual Switch"

minikube addons enable metrics-server
minikube addons enable dashboard
minikube addons enable metallb

kubectl apply -f srcs/metallb/metallb.yaml >> $SETUP_LOG

#use docker daemon from minikube.
eval $(minikube docker-env)

#build docker images.
echo "**********Docker images build**************"
echo "influxdb..."
docker build -t my_influxdb srcs/influxdb/ >> $SETUP_LOG
echo "nginx..."
docker build -t my_nginx srcs/nginx/ >> $SETUP_LOG
echo "mysql..."
docker build -t my_mysql srcs/mysql/ >> $SETUP_LOG
echo "phpmyadmin..."
docker build -t my_phpmyadmin srcs/phpmyadmin/ >> $SETUP_LOG
echo "wordpress..."
docker build -t my_wordpress srcs/wordpress/ >> $SETUP_LOG
echo "ftps..."
docker build -t my_ftps srcs/ftps/ >> $SETUP_LOG
echo "grafana..."
docker build -t my_grafana srcs/grafana/ >> $SETUP_LOG
echo "**********Docker build completed************"

echo "**********Deploy init***********************"
kubectl apply -f srcs/influxdb/influxdb.yaml >> $SETUP_LOG
kubectl apply -f srcs/ftps/ftps.yaml >> $SETUP_LOG
kubectl apply -f srcs/nginx/nginx.yaml >> $SETUP_LOG
kubectl apply -f srcs/mysql/mysql.yaml >> $SETUP_LOG
kubectl apply -f srcs/phpmyadmin/phpmyadmin.yaml >> $SETUP_LOG
kubectl apply -f srcs/wordpress/wordpress.yaml >> $SETUP_LOG
kubectl apply -f srcs/grafana/grafana.yaml >> $SETUP_LOG
echo "***********Deploy completed*****************"

minikube status
