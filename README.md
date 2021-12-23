# myopl-c++

## Version 2.8.0

Note - the version is in the form `episode.minutes.seconds` (seconds approximate) as how far I have gotten
on the YouTube playlist

A translation of David Callanan/[CodePulse](https://www.youtube.com/c/CodePulse/)'s
project and YouTube Series [Make YOUR OWN Programming Language in Python]
(https://www.youtube.com/playlist?list=PLZQftyCk7_SdoVexSmwy_tBgs7P0b97yD) into C++.
The Python code is at https://github.com/davidcallanan/py-myopl-code

Thanks to the `{fmt}` library for string formatting

Note - If you are on a nix repl with the correct dependencies (see `replit.nix`)
then you count as having `{fmt}` installed

Also note - `$` denotes a shell command (e.g `$ make` means run the command
`make` in a shell)

Compiling / Running
--
If you have `{fmt}` installed,
then to compile run `$ make CXXFLAGS=-DHAVE_SYS_FMT LDFLAGS=-lfmt`.

This instructs it to include the system `{fmt}` headers and the system `libfmt.so`.
Then to run, it's just `$ ./run/myopl`

---
If you do not have `{fmt}` installed then you can just do `$ make` which includes
the `{fmt}` headers that are in `libs/fmt` and links with `libs/fmt/bin/libfmt.so`
Then, to run you need to tell the runtime linker/loader
where `libfmt.so` is before running the binary by adding the directory
with `libfmt.so` to `$LD_LIBRARY_PATH` (e.g `$ export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:libs/fmt/bin`)
before doing `$ ./run/myopl`

---

If you do not have `{fmt}` installed and don't want to or can't link against 
`libs/fmt/bin/libfmt.so`, then you can use `{fmt}` with header-only mode by
running `$ make CXXFLAGS=-DFMT_HEADER_ONLY`, but
be aware this may take longer to compile.

---
If you are on Windows or a Mac, then good luck as I have no idea what you would do,
but I would start by either trying it with header-only mode or building `{fmt}` yourself
(see https://fmt.dev/latest/usage.html#building-the-library)

---
Lastly, by default it will make a debug build, to disable this run `$ make DEBUG=`
as well as the other flags for make that hopefully you figured out above.

---
Other stuff
--
To extract the `.tar.gz` file - `$ tar xzvf myopl.tar.gz`

To extract the `.tar.xz` file - `$ tar xJvf myopl.tar.xz`

`{fmt}`
--
* https://github.com/fmtlib/fmt
* https://fmt.dev/latest/index.html
