FROM alpine:3.16

RUN apk update && \
    apk add --no-cache wget && \
    wget https://github.com/google/cadvisor/releases/download/v0.37.0/cadvisor && \
    chmod +x cadvisor && \
    wget -O /usr/bin/dumb-init https://github.com/Yelp/dumb-init/releases/download/v1.2.5/dumb-init_1.2.5_x86_64 && \
    chmod +x /usr/bin/dumb-init

ENTRYPOINT [ "/usr/bin/dumb-init", "--" ]

CMD ["./cadvisor"]
