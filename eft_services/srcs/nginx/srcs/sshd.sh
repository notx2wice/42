mkdir -p /run/openrc
touch /run/openrc/softlevel
openrc
rc-update add sshd
adduser -D ekim
echo "ekim:password" | chpasswd
ssh-keygen -A
/usr/sbin/sshd -D