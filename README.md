# InitRC
A minimal Linux init system, made in C

## Installation
To install InitRC, just compile it into /bin. The only depend is a C compiler and the linux kernel headers.
Also, make `/etc/rc`, as InitRC will execute that script when it boots.

Here's an example rc file:

``` sh
#!/bin/bash
# InitRC v0.3 RC file
/bin/sh
```

**Please make your own rc file, as this one doesnt setup anything other than a shell**
*and remember, when the RC script dies (aka tty1 kills itself), the system gets shutdown!*

## Compiling
To compile InitRC from source, just run these commands:

``` sh
cc initrc.c -o ./bin/init --verbose
# thats all lmao
```

## Configuring
To configure InitRC, you **dont.**

:wq
