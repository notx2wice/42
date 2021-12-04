FROM alpine:3.12.0

RUN apk update
RUN apk add grafana --repository http://dl-cdn.alpinelinux.org/alpine/edge/community/ --allow-untrusted --no-cache
RUN apk add telegraf --repository http://dl-cdn.alpinelinux.org/alpine/edge/community/ --allow-untrusted --no-cache
RUN apk add supervisor

COPY ./srcs/start.sh /tmp/
COPY ./srcs/dashboards /var/lib/grafana/dashboards
COPY ./srcs/provisioning/dashboards/dashboards.yaml /usr/share/grafana/conf/provisioning/dashboards/
COPY ./srcs/provisioning/datasources/influxdb.yaml /usr/share/grafana/conf/provisioning/datasources/
# COPY ./srcs/grafana.ini /etc/grafana/grafana.ini
COPY ./srcs/telegraf.conf /etc/telegraf/
COPY ./srcs/supervisord.conf /etc/

# WORKDIR	/usr/share/grafana

EXPOSE 3000

CMD sh /tmp/start.sh