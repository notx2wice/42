FROM alpine:3.12.0

RUN apk update
RUN apk add influxdb
RUN apk add supervisor --no-cache
RUN apk add telegraf --repository http://dl-cdn.alpinelinux.org/alpine/edge/community/ --allow-untrusted --no-cache

COPY ./srcs/supervisord.conf /etc/supervisord.conf
COPY ./srcs/telegraf.conf /etc/telegraf/
COPY ./srcs/run.sh .

EXPOSE 8086 8088

CMD sh run.sh
