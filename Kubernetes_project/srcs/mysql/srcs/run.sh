# openrc
echo "FLUSH PRIVILEGES;" | mysql -u root
# rc-service mariadb restart
/usr/bin/mysqld_safe --datadir="/var/lib/mysql"