#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>
#include <linux/reboot.h>

int main() {
    int selfpid=getpid();
    if (selfpid != 1) {
        printf("Not running as PID 1, dying...\n");
        return 1;
    } else { 
        printf("InitRC v0.3.1 -- Booting up!\n");
        printf("Mounting filesystems... ");
        system("/usr/bin/mount -t procfs proc /proc");
        system("/usr/bin/mount -t devtmpfs dev /dev");
        system("/usr/bin/mount -t sysfs sys /sys");
        system("/usr/bin/mount -t tmpfs tmp /tmp");
        printf("done!\n");
        printf("Running mainrc... ");
        system("/usr/bin/sh -c /etc/initrc/rc");
        printf("Running networkrc... ");
        system("/usr/bin/sh -c /etc/initrc/networkrc");
        printf("Running user scripts... ");
        system("/usr/bin/sh -c /etc/initrc/user");
        printf("done!\n");
        printf("TTY1 killed, shutting down...\n");
    system("/usr/bin/sh -c /etc/initrc/shutdown");
	sync();
	reboot(LINUX_REBOOT_MAGIC1,
	       LINUX_REBOOT_MAGIC2,
	       LINUX_REBOOT_CMD_POWER_OFF, 0);
    }
}

    
