adduser -G www-data -D www-data
chown -R www-data:www-data /var/www/phpmyadmin

mkdir -p /var/www/phpmyadmin/tmp
chgrp www-data /var/www/phpmyadmin/tmp
chmod 774 /var/www/phpmyadmin/tmp

# chmod -R 755 /var/www/phpmyadmin

# chmod 755 /var/www/phpmyadmin
# chmod 644 /var/www/phpmyadmin/*

# mkdir -p /run/openrc
# touch /run/openrc/softlevel

supervisord -c /etc/supervisord.conf	& tail -f /dev/null