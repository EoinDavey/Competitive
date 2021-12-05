# Running Piet

Build the Dockerfile if not built: `docker build -t npiet .`.

To run `npiet` command just run:
- `cat d01.txt - <<< "-1" | docker run --rm -i -v "$PWD:/code:ro"
  npiet npiet -q /code/d01-Piet.ppm`.
- `cat d01.txt | docker run --rm -i -v "$PWD:/code:ro"
  npiet npiet -q /code/d01-Piet-part2.ppm`.

To launch npietedit run `docker run --rm -e DISPLAY=$DISPLAY -v /tmp/.X11-unix:/tmp/.X11-unix -v
"$PWD:/code" npiet npietedit /code/d01-Piet.ppm`. The `DISPLAY` and `X11` stuff sets up X so the
GUI can render. You may need to run `xhost +` to enable docker user to connect to X server.

# Running Whitespace

Editor: https://naokikp.github.io/wsi/whitespace.html
Caveat: Editor crashes at end of input, so append any word that isn't ∈ {forward up down} to the end
of the input and it will detect the end and print the answer.

# Running TCL

Cmd: `docker run --rm -it  efrecon/tcl`
E.g `docker run --rm -i -v "$PWD:/opt/tcl" efrecon/tcl /opt/tcl/d05.tcl < d05.txt`
