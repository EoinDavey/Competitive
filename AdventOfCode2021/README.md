# Running Piet

Build the Dockerfile if not built: `docker build -t npiet .`.

To run `npiet` command just run:
- `cat d01/d01.txt - <<< "-1" | docker run --rm -i -v "$PWD:/code:ro" npiet npiet -q
  /code/d01/d01-Piet.ppm`.
- `cat d01/d01.txt | docker run --rm -i -v "$PWD:/code:ro" npiet npiet -q
  /code/d01/d01-Piet-Part2.ppm`.

To launch npietedit run `docker run --rm -e DISPLAY=$DISPLAY -v /tmp/.X11-unix:/tmp/.X11-unix -v
"$PWD:/code" npiet npietedit /code/d01/d01-Piet.ppm`. The `DISPLAY` and `X11` stuff sets up X so the
GUI can render. You may need to run `xhost +` to enable docker user to connect to X server.

# Running Whitespace

Editor: https://naokikp.github.io/wsi/whitespace.html
Caveat: Editor crashes at end of input, so append any word that isn't ∈ {forward up down} to the end
of the input and it will detect the end and print the answer.

# Running Prolog

Docker image: `docker run --rm -it -v "$PWD:/code/" swipl`. Run `cd("code/d04").` and `[d04].` to
get to the correct directory and then run `start(Part1, Part2)`.

# Running TCL

Cmd: `docker run --rm -it efrecon/tcl`
E.g `docker run --rm -i -v "$PWD:/opt/tcl" efrecon/tcl /opt/tcl/d05/d05.tcl < d05/d05.txt`

# Running Scratch

Go to https://scratch.mit.edu/projects/612506357 or load the raw `.sb3` file from the `d06`.
directory.

# Running Octave

- Run script directly: `docker run --rm -v "$PWD:/code" gnuoctave/octave:6.4.0 octave
  /code/d08/d08.m`. (Reads directly from the `d08.txt` file).
- Open octave interactively: `docker run --rm -it -v "$PWD:/code" gnuoctave/octave:6.4.0` and then
  run `run("/code/d08/d08.m")` to run the code.

# Running Factor

To start UI editor: `docker run --rm -e DISPLAY=$DISPLAY -v "/tmp/.X11-unix:/tmp/.X11-unix" -v
"$PWD:/factor/work" factor factor/factor`. Run `USE: d09` in the editor to load the `d09/d09.factor`
file.

To run script w/o UI
- Day 9: `docker run --rm -v "$PWD:/factor/work" factor factor/factor -run=d09` (Reads
 `d09/d09.txt` file directly).
- Day 8 (Part 1 only): `docker run --rm -i -v "$PWD:/factor/work" factor factor/factor -run=d08 <
  d08/d08.txt`.
