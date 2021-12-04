# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ukim <ukim@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/02 19:59:41 by ukim              #+#    #+#              #
#    Updated: 2021/01/16 03:06:45 by ukim             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian:buster
LABEL maintainer="ukim@student.42seoul.kr"

COPY srcs tmp

#download requirements
RUN apt-get update
RUN apt-get -y install nginx php7.3-fpm php7.3-mysql mariadb-server openssl wget

#nginx ssl certificate
RUN openssl req -newkey rsa:4096 -days 365 -nodes -x509 \
	-subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=ekim/CN=localhost" \
	-keyout localhost.dev.key -out localhost.dev.crt
RUN mv localhost.dev.crt etc/ssl/certs/
RUN mv localhost.dev.key etc/ssl/private/

#wget run
RUN wget https://wordpress.org/latest.tar.gz && \
	tar -xvf latest.tar.gz && \
	mv wordpress/ var/www/html/ && \
	rm latest.tar.gz

RUN wget https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-all-languages.tar.gz && \
	tar -xvf phpMyAdmin-5.0.2-all-languages.tar.gz && \
	mv phpMyAdmin-5.0.2-all-languages phpmyadmin && \
	mv phpmyadmin /var/www/html/ && \
	rm phpMyAdmin-5.0.2-all-languages.tar.gz

#move conf files from tmp
RUN mv tmp/default etc/nginx/sites-available/
RUN mv tmp/wp-config.php var/www/html/wordpress/
RUN mv tmp/config.inc.php var/www/html/phpmyadmin/

#remove unused html
RUN rm /var/www/html/index.nginx-debian.html

ENTRYPOINT ["/bin/bash", "tmp/setsql.sh"]