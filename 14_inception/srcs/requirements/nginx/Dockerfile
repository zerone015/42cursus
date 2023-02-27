FROM		alpine:3.16

RUN			apk update && \
			apk add nginx openssl && \
			wget -O /usr/bin/dumb-init https://github.com/Yelp/dumb-init/releases/download/v1.2.5/dumb-init_1.2.5_x86_64 && \
			chmod +x /usr/bin/dumb-init && \
			mkdir -p /etc/nginx/tls /var/run/nginx && \
			openssl req -newkey rsa:4096 -x509 -days 365 -nodes -out /etc/nginx/ssl/yoson.42.fr.crt -keyout /etc/nginx/ssl/yoson.42.fr.key -subj "/C=KR/ST=Seoul/L=Gaepo/O=42Seoul/OU=Lee/CN=yoson.42.fr"

COPY		conf/nginx.conf /etc/nginx/conf.d

EXPOSE      443

ENTRYPOINT  [ "/usr/bin/dumb-init", "--"]

CMD         ["nginx", "-g", "daemon off"]