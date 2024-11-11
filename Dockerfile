FROM ubuntu:22.04 as base_image

RUN apt-get update && apt-get install -y \
    build-essential \
    gcc \
    git \
    make \
    && rm -rf /var/lib/apt/lists/*

RUN mkdir /build
COPY ./*.c /build/
COPY ./*.h /build/
COPY Makefile /build
WORKDIR /build
RUN make all