FROM jenkins/jenkins:lts-jdk11
USER root
RUN apt-get -y update && \
    apt-get -y upgrade && \
    apt-get -y wget && \
    apt-get -y unzip && \
    rm -rf /var/lib/apt/lists/*
# COPY plugins.txt /usr/share/jenkins/plugins.txt
# RUN jenkins-plugin-cli -f /usr/share/jenkins/plugins.txt