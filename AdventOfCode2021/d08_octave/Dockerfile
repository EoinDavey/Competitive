FROM gcc

RUN git clone git://factorcode.org/git/factor.git && \
    cd factor/ && \
    ./build.sh update

RUN apt update && \
    apt --yes install libc6-dev libpango1.0-dev \
    libx11-dev xorg-dev libgtk2.0-dev gtk2-engines-pixbuf \
    libgtkglext1-dev wget git git-doc rlwrap gcc g++ make

CMD ["/bin/bash"]
