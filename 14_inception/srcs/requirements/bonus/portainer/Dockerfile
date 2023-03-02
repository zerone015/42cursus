FROM alpine:3.16

RUN apk add --no-cache nodejs npm git wget && \
    wget -O /usr/bin/dumb-init https://github.com/Yelp/dumb-init/releases/download/v1.2.5/dumb-init_1.2.5_x86_64 && \
    chmod +x /usr/bin/dumb-init

RUN git clone --branch 2.11.1 https://github.com/portainer/portainer-ce.git /var/www

WORKDIR /var/www

RUN npm install && \
    npm run build:prod

ENTRYPOINT [ "/usr/bin/dumb-init", "--" ]

CMD ["node", "/var/www"]