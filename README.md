# InitRC
A minimal Linux init system, made in C

## Installation
To install InitRC, just clone this repo, place the `InitRCv0.1-<arch>.bin` file from the bin folder (with arch being your CPU Architecture) into /bin, or compile it yourself (see *Compiling*)

Also, make `/etc/rc`, as InitRC will execute that script when it boots.

Here's an example rc file:

``` sh
#!/bin/bash
# InitRC v0.1 RC file
/bin/sh
```

**Please make your own rc file, as this one doesnt setup anything other than a shell**

## Compiling
To compile InitRC from source, just run these commands:

``` sh
cc initrc.c -o ./bin/init --verbose
# thats all lmao
```

## Configuring
To configure InitRC, you **dont.**

:wq
