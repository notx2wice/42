FROM alpine:3.12.0

#install all necessary packages
RUN apk update
RUN apk add wget nginx php7 php7-fpm php7-opcache php7-gd php7-mysqli php7-zlib php7-curl php7-mbstring php7-json php7-session --no-cache
RUN	apk add telegraf --repository http://dl-cdn.alpinelinux.org/alpine/edge/community/ --allow-untrusted --no-cache

RUN wget https://files.phpmyadmin.net/phpMyAdmin/4.9.5/phpMyAdmin-4.9.5-all-languages.tar.gz
RUN tar -xvf phpMyAdmin-4.9.5-all-languages.tar.gz
RUN rm phpMyAdmin-4.9.5-all-languages.tar.gz
RUN	mv phpMyAdmin-4.9.5-all-languages /var/www/phpmyadmin

RUN apk add supervisor --no-cache
RUN	rm -rf /var/cache/apk/*

RUN mkdir -p /run/nginx

COPY ./srcs/config.inc.php /var/www/phpmyadmin/
RUN chmod 755 /var/www/phpmyadmin
COPY ./srcs/telegraf.conf /etc/telegraf/
COPY ./srcs/nginx.conf /etc/nginx/
COPY ./srcs/supervisord.conf /etc/
COPY ./srcs/start.sh /tmp/

EXPOSE 5000

CMD sh /tmp/start.sh