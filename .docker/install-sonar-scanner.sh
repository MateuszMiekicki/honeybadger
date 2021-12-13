#!/bin/sh
set -eux

SONAR_SCANNER_VERSION=4.6.2.2472

# Only install java if not already present (to avoid conflicting Java version)
arg_java=""
if ! which java >/dev/null; then
  arg_java=default-jre
fi

apt-get install -y $arg_java

mkdir -p /opt
wget https://binaries.sonarsource.com/Distribution/sonar-scanner-cli/sonar-scanner-cli-${SONAR_SCANNER_VERSION}.zip -O /opt/sonar-scanner.zip
unzip /opt/sonar-scanner.zip -d /opt
rm /opt/sonar-scanner.zip
ln -s /opt/sonar-scanner-${SONAR_SCANNER_VERSION}/bin/sonar-scanner /usr/bin/sonar-scanner