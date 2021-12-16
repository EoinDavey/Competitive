# Running Piet

Build the Dockerfile if not built: `docker build -t npiet .`.

To run `npiet` command just run:
- `cat d01_piet/d01.txt - <<< "-1" | docker run --rm -i -v "$PWD:/code:ro" npiet npiet -q
  /code/d01_piet/d01-Piet.ppm`.
- `cat d01_piet/d01.txt | docker run --rm -i -v "$PWD:/code:ro" npiet npiet -q
  /code/d01/d01_piet/d01-Piet-Part2.ppm`.

To launch npietedit run `docker run --rm -e DISPLAY=$DISPLAY -v /tmp/.X11-unix:/tmp/.X11-unix -v
"$PWD:/code" npiet npietedit /code/d01_piet/d01-Piet.ppm`. The `DISPLAY` and `X11` stuff sets up X
so the GUI can render. You may need to run `xhost +` to enable docker user to connect to X server.

# Running Whitespace

Editor: https://naokikp.github.io/wsi/whitespace.html
Caveat: Editor crashes at end of input, so append any word that isn't ∈ {forward up down} to the end
of the input and it will detect the end and print the answer.

# Running Prolog

Docker image: `docker run --rm -it -v "$PWD:/code/" swipl`. Run `cd("code/d04_prolog/d04").` and
`[d04].` to get to the correct directory and then run `start(Part1, Part2)`.

# Running TCL

Cmd: `docker run --rm -it efrecon/tcl`
E.g `docker run --rm -i -v "$PWD:/opt/tcl" efrecon/tcl /opt/tcl/d05_tcl/d05.tcl < d05_tcl/d05.txt`

# Running Scratch

Go to https://scratch.mit.edu/projects/612506357 or load the raw `.sb3` file from the `d06_scratch`
directory.

# Running Octave

- Run script directly: `docker run --rm -v "$PWD:/code" gnuoctave/octave:6.4.0 octave
  /code/d08_octave/d08.m`. (Reads directly from the `d08.txt` file).
- Open octave interactively: `docker run --rm -it -v "$PWD:/code" gnuoctave/octave:6.4.0` and then
  run `run("/code/d08/d08.m")` to run the code.

# Running Factor

To start UI editor: `docker run --rm -e DISPLAY=$DISPLAY -v "/tmp/.X11-unix:/tmp/.X11-unix" -v
"$PWD:/factor/work" factor factor/factor`. Run `USE: d09_factor` in the editor to load the
`d09_factor/d09_factor.factor` file.

To run script w/o UI
- Day 9: `docker run --rm -v "$PWD:/factor/work" factor factor/factor -run=d09_factor` (Reads
  `d09/d09.txt` file directly).
- Day 8 (Part 1 only): `docker run --rm -i -v "$PWD:/factor/work" factor factor/factor
  -run=d08_octave < d08_octave/d08.txt`.

# Running LOGO

- Build the ubclogo docker image from `d10_logo/`. `docker build -t logo .`.
- The ubclogo binary runs only in a GUI mode so run `docker run --rm -e DISPLAY=$DISPLAY -v "/tmp/.X11-unix:/tmp/.X11-unix" -v "$PWD:/code" logo` to run this with X server connected. You may
  need to run `xhost +` to allow docker to auth with X server.
- In the LOGO console run `load "/code/d10_logo/d10.lgo` to load the file. **Note the intentional
  lack of a closing quote (LOGO weirdness)**.
- Now run `runProg` to run the program.

# Running Julia

- Run script: `docker run --rm -i -v "$PWD:/code" -w "/code" julia julia d11_julia/d11.jl <
  d11_julia/d11.txt`.
- Open Julia REPL: `docker run --rm -it julia`.

# Running Dart

- `docker run --rm -i -v "$PWD:/code" -w "/code" dart dart run d12_dart/d12.dart <
  d12_dart/d12.txt`.

# Running Haskell

- GHCI: `docker run --rm -it haskell`.
- Run script: `docker run --rm -i -v "$PWD:/code" -w "/code" haskell runhaskell d13_haskell/d13.hs <
  d13_haskell/d13.txt`.

# Running Kotlin

- REPL: `docker run --rm -it zenika/kotlin`
- Run `.kts` file as script: `docker run --rm -i -v "$PWD:/code" -w "/code" zenika/kotlin kotlinc
  -script d15_kotlin/d15.kts < d15_kotlin/d15.txt`
