FROM alpine:3.12.0

RUN apk update
RUN apk add supervisor --no-cache
RUN apk add openssl vsftpd --no-cache
RUN	apk add telegraf --repository http://dl-cdn.alpinelinux.org/alpine/edge/community/ --allow-untrusted --no-cache

COPY ./srcs/vsftpd.conf /etc/vsftpd/
COPY ./srcs/start.sh .
COPY ./srcs/supervisord.conf /etc/
COPY ./srcs/telegraf.conf /etc/telegraf/

EXPOSE 21 50021

CMD sh start.sh