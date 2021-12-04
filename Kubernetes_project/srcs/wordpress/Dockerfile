FROM alpine:3.12.0

RUN apk update
RUN	apk add nginx wget php7 php7-fpm php7-mysqli php7-mbstring php7-json php7-session
RUN	apk add telegraf --repository http://dl-cdn.alpinelinux.org/alpine/edge/community/ --allow-untrusted --no-cache && \
	wget https://wordpress.org/wordpress-5.6.tar.gz && \
	tar -xzvf wordpress-5.6.tar.gz && \
	rm wordpress-5.6.tar.gz

RUN apk add supervisor --no-cache && \
	rm -rf /var/cache/apk/*

RUN mkdir -p /run/nginx
RUN	mkdir -p /var/www && mv /wordpress /var/www/

COPY ./srcs/wp-config.php /var/www/wordpress/
COPY ./srcs/telegraf.conf /etc/telegraf/
COPY ./srcs/start.sh /tmp/
COPY ./srcs/nginx.conf /etc/nginx/
COPY ./srcs/supervisord.conf /etc/

EXPOSE 5050

CMD sh /tmp/start.sh