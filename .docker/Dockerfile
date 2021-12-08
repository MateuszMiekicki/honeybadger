FROM alpine:3.15

RUN apk update && \
    apk add cmake=3.21.3-r0 && \
    #note: the latest ninja version is 1.9.0 as of this writing.
    # The repository as of 3.15 does not have ninja.
    apk add ninja && \ 
    apk add g++=10.3.1_git20211027-r0 && \
    apk add doxygen=1.9.2-r1 && \
    apk add git && \
    apk add linux-headers

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
ARG opencv_test_tag=4.5.4
ARG opencv_test_repo=https://github.com/opencv/opencv.git
ARG opencv_dir=opencv
RUN git clone --depth 1 \
    --branch $opencv_test_tag \
    $opencv_test_repo && \
    cd $opencv_dir && \
    cmake -Bbuild -G $cmake_generator -DCMAKE_BUILD_TYPE=Release && \
    cmake --build build --target install --config Release
#install sonar scanner
COPY install-sonar-scanner.sh /install-sonar-scanner.sh
RUN chmod +x install-sonar-scanner.sh
RUN ./install-sonar-scanner.sh
#Clear
RUN rm -r $googletest_dir && \
    rm -r $google_benchmark_dir && \
    rm -r $opencv_dir