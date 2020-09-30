#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>

int main() {
    int selfpid=getpid();
    if (selfpid != 1) {
        printf("Not running as PID 1, dying...\n");
        return 1;
    } else { 
        printf("InitRC v0.1 -- Booting up!\n");
        printf("Mounting filesystems... ");
        system("/usr/bin/mount -t procfs proc /proc");
        system("/usr/bin/mount -t devtmpfs dev /dev");
        system("/usr/bin/mount -t sysfs sys /sys");
        system("/usr/bin/mount -t tmpfs tmp /tmp");
        printf("done!\n");
        printf("Running /etc/rc... ");
        system("/usr/bin/sh -c /etc/rc");
        printf("Done!\n");
        sleep(0xFFFFFF);
    }
}
    
