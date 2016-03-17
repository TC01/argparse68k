# argparse68k v1.0

argparse68k is a small static library written to aid the development of C 
programs for Texas Instrument's line of graphing calculators powered by
Motorola 68000 CPUs; specifically, the TI-89, the TI-92 Plus, the Voyage 200,
and the TI-89 Titanium.

The standard toolchain for developing C programs for these calculators is
the community-produced [GCC4TI](https://github.com/debrouxl/gcc4ti/wiki) (a
fork of the older [TIGCC](http://tigcc.ticalc.org/). argparse68k was developed
and tested using GCC4TI, but should probably work with older versions of TIGCC
as well.

I wrote argparse68k because I was frustrated by the amount of code I was
probably going to need to reuse between projects to implement some higher level
argument processing than what is provided by the [args.h](https://debrouxl.github.io/gcc4ti/args.html)
header in the standard library. While the routines provided by args.h work well
enough, they require the user to have some (minimal) understanding of the expression
stack system used by the AMS (TI's operating system for these calcs). I've written
several small 68k programs in C, and frequently find myself writing very similar
_main() functions to do something as simple as try and process the first argument
into a string. This seemed like something that could be easily spun off into a
small library.

argparse68k does not (yet) support reading arguments of all types; for example,
there's no provided routine to read in a TI-BASIC list passed to a program. Futher
routines will likely be implemented only if I actually need them, so if you would
like to extend argparse68k with such code, feel free to do so and send me a patch.

Please note: this project has no relation to the Python standard library's
[argparse](https://docs.python.org/3/library/argparse.html), except that I liked
the name (and argparse, for that matter).

argparse68k is distributed under the MIT license; see LICENSE for the full text.

## Compiling

To build argparse68k from source, you can run ```tprbuilder argparse68k.tpr```,
or open this file in the GCC4TI IDE and compile it there.

This will produce the ```argparse68k.a``` function archive. A precompiled version
of this library is distributed in the release tarball and zip file available for
download from ticalc.org, github, etc.

## Linking against argparse68k

Building against argparse using GCC4TI is pretty simple. You just need to add
the ```argparse.h``` header file and the ```argparse68k.a``` function archive
(i.e. static library) to your projects. To actually link against it, put the following
at the top of your main program (*before* any other imports!):

```
#define ENABLE_ERROR_RETURN
#include "argparse.h"
```

The reason you need to put this define before importing the standard library is
discussed [here](https://debrouxl.github.io/gcc4ti/htretval.html#reterr), but
basically, because routines in argparse68k can throw ER_ARGUMENT (the operating
system's "invalid argument passed to function" error), you need to 

## Usage

The functions exposed in argparse68k are defined and documented in ```argparse.h```.

An example program is included, ```test.c```, along with the GCC4TI project file
```example.tpr``` (which you can compile either using ```tprbuilder``` or by
opening it in the IDE). 

## Credits

* Ben 'TC01' Rosser <rosser.bjr@gmail.com>: author

Thanks to the GCC4TI developers (and TIGCC developers before them) without whom
this would not be possible.

