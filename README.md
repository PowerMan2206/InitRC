# InitRC
A minimal Linux init system, made in C.

## Compiling and installation
To compile InitRC from source and install it, first make sure you have a C compiler and the Linux kernel headers. Then run either

``` sh
make
sudo make install
``` 

to do it with `make` 

or

``` sh
sudo mv /bin/init /bin/init.old
sudo cc initrc.c -o /bin/init -O3
```

if you want to compile it manually.

## Bootup

On bootup, initrc will first mount the pseudofilesystems, then run `/etc/initrc/rc`, then `/etc/initrc/networkrc`, then run `/etc/initrc/user`. After killing TTY1, InitRC will run `/etc/initrc/shutdown` and then poweroff the machine.

`initrc/rc` is meant to start essenial services, such as the dbus, set the time, hostname, etc.

`initrc/networkrc` is meant to, well, start the network.

`initrc/user` is meant to run user-created scripts in the `initrc` directory that arent essential to the system bootup, so it gets ran as last.

`initrc/shutdown` is for stopping processes and preparing to shutdown. As an example, you can use this script to stop sshd before shutting down.

InitRC doesnt have default rc files, you have to make those yourself. 

## User Scripts

User scripts are a new feature in initrc v0.5. First, create your userscripts in `/etc/initrc/`, then in `/etc/initrc/user` add a line that starts it, for example:

``` sh
#!/bin/bash
sh -c "/etc/initrc/userscipt-X" # you dont have to call it userscript-X but this is an example
exit
```

