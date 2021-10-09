FROM gcc:latest

RUN apt-get -y update && \
    apt-get -y upgrade && \
    apt-get install -y cmake && \
    apt-get install -y g++-11 && \
    apt-get install -y ninja-build && \
    rm -rf /var/lib/apt/lists/*

