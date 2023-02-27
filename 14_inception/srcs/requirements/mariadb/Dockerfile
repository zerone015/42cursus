FROM    alpine:3.16

RUN     apk update && \
        apk add --no-cache mariadb mariadb-client && \
        wget -O /usr/bin/dumb-init https://github.com/Yelp/dumb-init/releases/download/v1.2.5/dumb-init_1.2.5_x86_64 && \
		chmod +x /usr/bin/dumb-init && \
        mkdir -p /var/run/mysqld

COPY    tools/script.sh /tmp/script.sh

RUN     chmod +x /tmp/script.sh

EXPOSE  3306

ENTRYPOINT  [ "/usr/bin/dumb-init", "--" ]

CMD         [ "sh", "-c", "/tmp/script.sh" ]