FROM ubuntu:16.04
RUN apt-get update 
RUN apt-get install -y build-essential git libpcap-dev libssl-dev cmake
copy scripts/build-libtins.sh .
RUN bash build-libtins.sh
copy scripts/build-googletest.sh .
RUN bash build-googletest.sh
