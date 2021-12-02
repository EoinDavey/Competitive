FROM gcc
RUN apt update && \
    apt install -y tk tcl && \
    cd /tmp && \
    curl http://www.bertnase.de/npiet/npiet-1.3e.tar.gz -LO && \
    tar xzf npiet-1.3e.tar.gz && \
    cd npiet-1.3e && \
    ./configure && \
    make npiet && \
    mv npiet npietedit /bin/.

CMD ["npiet"]
