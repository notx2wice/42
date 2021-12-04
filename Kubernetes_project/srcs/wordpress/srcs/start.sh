#give access right to root folder.
adduser -G www-data -D www-data
chown -R www-data:www-data /var/www/wordpress
chmod -R 755 /var/www/wordpress
supervisord -c /etc/supervisord.conf	& tail -f /dev/null