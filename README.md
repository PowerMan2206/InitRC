# InitRC
A minimal Linux init system, made in C.

## Compiling and installation
To compile InitRC from source and install it, first make sure you have a C compiler and the Linux kernel headers. Then run either

``` sh
make
sudo make install
``` 

or

```
sudo mv /bin/init /bin/init.old
sudo cc initrc.c -o /bin/init --verbose
```

if you want to compile it manually.

## Bootup script

Also, make `/etc/rc`, as InitRC will execute that script when it boots.

Here's an example rc file:

``` sh
#!/bin/bash
# InitRC v0.3 RC file
/bin/sh
```

**Please make your own rc file, as this one doesnt setup anything other than a shell.**

*And remember, when the RC script dies (aka tty1 kills itself), the system gets shutdown!*

## Configuring
To configure InitRC, you **don't.**

:wq
