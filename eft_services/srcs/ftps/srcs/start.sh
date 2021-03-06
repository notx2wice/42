mkdir -p /ftps/ekim
adduser --home=/ftps/ekim -D ekim
echo "ekim:password" | chpasswd
echo "ekim" >> /etc/vsftpd/userlist.conf

touch /var/log/vsftpd.log

openssl req -x509 -nodes -days 365 -newkey rsa:4096 -subj  "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=ekim/CN=127.0.0.1" \
	-keyout /etc/ssl/private/vsftpd.key -out /etc/ssl/certs/vsftpd.crt

supervisord -c /etc/supervisord.conf & tail -f /dev/null