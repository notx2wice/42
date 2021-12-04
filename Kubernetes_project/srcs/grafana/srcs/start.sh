# telegraf & /usr/sbin/grafana-server --config=/etc/grafana/grafana.ini --homepath=/usr/share/grafana
supervisord -c /etc/supervisord.conf & tail -f /dev/null