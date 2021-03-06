FROM alpine:3.12.0

RUN apk add nginx 
RUN apk add openssh openssl supervisor openrc
RUN apk add telegraf --repository http://dl-cdn.alpinelinux.org/alpine/edge/community/ --allow-untrusted --no-cache

RUN mkdir -p /run/nginx && \
    mkdir -p /run/sshd

#nginx ssl certificate
RUN openssl req -x509 -nodes -days 365 \
	-newkey rsa:2048 -subj  "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=ekim/CN=127.0.0.1" \
	-keyout /etc/ssl/private/nginx.key -out /etc/ssl/certs/nginx.crt && \
	openssl dhparam -dsaparam -out /etc/ssl/certs/dhparam.pem 2048

RUN mkdir -p /var/www

COPY ./srcs/index.html /var/www/
COPY ./srcs/ssl_params.conf /etc/nginx/
COPY ./srcs/nginx.conf /etc/nginx/
COPY ./srcs/sshd_config /etc/ssh/
COPY ./srcs/start.sh /tmp/
COPY ./srcs/sshd.sh /tmp/
COPY ./srcs/telegraf.conf /etc/telegraf/
COPY ./srcs/supervisord.conf /etc/

EXPOSE 80 443 22

CMD sh /tmp/start.sh