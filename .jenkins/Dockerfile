FROM jenkins/jenkins:lts
USER root
RUN apt-get -y update && apt-get -y upgrade && apt-get install -y nano && rm -rf /var/lib/apt/lists/*
COPY plugins.txt /usr/share/jenkins/plugins.txt
RUN /usr/local/bin/install-plugins.sh < /usr/share/jenkins/plugins.txt