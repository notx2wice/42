#!/bin/bash

service mysql start

#allow access
chown -R www-data:www-data var/www/*
chmod -R 755 var/www/*

#create Database "wordpress"
echo "CREATE DATABASE wordpress;" | mysql -u root --skip-password
echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'root'@'localhost' WITH GRANT OPTION;" | mysql -u root --skip-password
echo "update mysql.user set plugin='mysql_native_password' where user='root';" | mysql -u root --skip-password
echo "FLUSH PRIVILEGES;" | mysql -u root --skip-password

service mysql restart
service nginx start
service php7.3-fpm start

bash