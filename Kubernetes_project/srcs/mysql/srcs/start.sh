#!/bin/sh
if [ ! -d /run/mysqld ]; then
	mkdir -p /run/mysqld
fi

# Install mysql database(mariadb-install-db is a symlink to mysql_install_db).
mysql_install_db --user=root --datadir=/var/lib/mysql

#database settings
openrc
rc-service mariadb start

# echo "FLUSH PRIVILEGES;" | mysql -u root

echo "CREATE DATABASE IF NOT EXISTS wordpress;" | mysql -u root
echo "CREATE USER 'ekim'@'%' IDENTIFIED BY 'password';" | mysql -u root
echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'ekim'@'%' WITH GRANT OPTION;" | mysql -u root
echo "USE wordpress;" | mysql -u root

mysql -u root wordpress < /tmp/wordpress.sql

echo "FLUSH PRIVILEGES;" | mysql -u root

supervisord -c /etc/supervisord.conf  & tail -f /dev/null