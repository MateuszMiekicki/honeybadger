FROM ubuntu:22.04
ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && \
    apt-get install -y ninja-build && \
    apt-get install -y g++-11 && \
    update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-11 11 && \
    apt-get install -y gcc-11 && \
    update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-11 11 && \
    update-alternatives --install /usr/bin/gcov gcov /usr/bin/gcov-11 11 && \
    apt-get install -y doxygen && \
    apt-get install -y git && \
    apt-get install -y wget && \
    apt-get install -y unzip && \
    apt-get install -y lcov && \
    apt-get install -y python3 pip && \
    apt-get install -y ruby-dev

RUN pip install gcovr
RUN gem install coveralls-lcov

#install CMake
COPY install-cmake.sh /install-cmake.sh
RUN chmod +x install-cmake.sh
RUN ./install-cmake.sh

ARG cmake_generator=Ninja

#Downloading, building and installing google test.
ARG google_test_tag=release-1.11.0
ARG google_test_repo=https://github.com/google/googletest.git
ARG googletest_dir=googletest
RUN git clone --depth 1 \
    --branch $google_test_tag \
    $google_test_repo && \
    cd $googletest_dir && \
    cmake -Bbuild -G $cmake_generator && \
    cmake --build build --target install

#Downloading, building and installing google benchmark.
#note: The google benchamrk tag will be up for change
# when the next version is released.
# The reason is incompatibility of branchy names
# in dependencies(google test moved from master to main).
ARG google_benchmark_tag=main
ARG google_benchmark_repo=https://github.com/google/benchmark.git
ARG google_benchmark_dir=benchmark
RUN git clone --depth 1 \
    --branch $google_benchmark_tag \
    $google_benchmark_repo && \
    cd $google_benchmark_dir && \
    cmake -Bbuild -G $cmake_generator \
    -DBENCHMARK_DOWNLOAD_DEPENDENCIES=on \
    -DCMAKE_BUILD_TYPE=Release && \
    cmake --build build --target install --config Release

#Downloading, building and installing opencv.
ARG opencv_tag=4.5.4
ARG opencv_repo=https://github.com/opencv/opencv.git
ARG opencv_dir=opencv
RUN git clone --depth 1 \
    --branch $opencv_tag \
    $opencv_repo && \
    cd $opencv_dir && \
    cmake -Bbuild -G $cmake_generator -DCMAKE_BUILD_TYPE=Release && \
    cmake --build build --target install --config Release

#install sonar scanner
COPY install-sonar-scanner.sh /install-sonar-scanner.sh
RUN chmod +x install-sonar-scanner.sh
RUN ./install-sonar-scanner.sh

#Clean
RUN rm -r $googletest_dir && \
    rm -r $google_benchmark_dir && \
    rm -r $opencv_dir && \
    apt-get autoremove && \
    apt-get autoclean && \
    apt-get clean