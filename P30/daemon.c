// 30. Write a program to run a script at a specific time using a Daemon process.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    pid_t pid;
    time_t now;
    struct tm *current_time;

    // Create a child process. The parent exits so that the child can run in background.
    pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    }

    if (pid > 0) {
        // Parent exits.
        return 0;
    }

    // Create a new session. This detaches the daemon from the terminal.
    if (setsid() == -1) {
        perror("setsid");
        return 1;
    }

    // Change working directory so the daemon does not keep the original directory busy.
    chdir("/");

    // Close standard file descriptors because a daemon does not need terminal input/output.
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    // Continuously check the current time.
    while (1) {
        now = time(NULL);
        current_time = localtime(&now);

        // Example: execute the script at 00:54. Change these values to your required time.
        if (current_time->tm_hour == 0 &&
            current_time->tm_min == 54 &&
            current_time->tm_sec == 0) {

            // Execute the shell script.
            execl("/bin/bash", "bash",
                  "/home/swapnil/SoftwareSystems/P30/myscript.sh",
                  (char *)NULL);

            // This executes only if execl() fails.
            _exit(1);
        }

        // Check the time once every second.
        sleep(1);
    }

    return 0;
}

/*
Output:

swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P30$ gcc daemon.c -o daemon
swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P30$ ./daemon
swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P30$ ps -ef | grep daemon
avahi       1231       1  5 Sep17 ?        00:20:40 avahi-daemon: running [swapnil-Latitude-5400.local]
message+    1240       1  0 Sep17 ?        00:00:15 @dbus-daemon --system --address=systemd: --nofork --nopidfile --systemd-activation --syslog-only
root        1312       1  0 Sep17 ?        00:00:00 /usr/libexec/accounts-daemon
avahi       1386    1231  0 Sep17 ?        00:00:00 avahi-daemon: chroot helper
root        1452       1  0 Sep17 ?        00:00:12 /usr/sbin/NetworkManager --no-daemon
rtkit       1744       1  0 Sep17 ?        00:00:00 /usr/libexec/rtkit-daemon
root        2872       1  0 Sep17 ?        00:00:00 /usr/libexec/power-profiles-daemon
swapnil     3107    3071  0 Sep17 ?        00:00:08 /usr/bin/dbus-daemon --session --address=systemd: --nofork --nopidfile --systemd-activation --syslog-only
swapnil     3112    3071  0 Sep17 ?        00:00:00 /usr/bin/gnome-keyring-daemon --foreground --components=pkcs11,secrets --control-directory=/run/user/1000/keyring
swapnil     3616    3609  0 Sep17 ?        00:00:01 /usr/bin/dbus-daemon --config-file=/usr/share/defaults/at-spi2/accessibility.conf --nofork --print-address 11 --address=unix:path=/run/user/1000/at-spi/bus
swapnil     3687    3071  0 Sep17 ?        00:01:11 /usr/bin/ibus-daemon --panel disable
swapnil     3695    3071  0 Sep17 ?        00:00:00 /usr/libexec/goa-daemon
swapnil    42760    3071  0 00:50 ?        00:00:00 ./daemon
swapnil    42860    3071  0 00:52 ?        00:00:00 ./daemon
swapnil    43004    3071  0 00:53 ?        00:00:00 ./daemon
swapnil    43007   15323  0 00:53 pts/0    00:00:00 grep --color=auto daemon
swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P30$ cat /tmp/daemon_output.txt
Script executed at Fri Sep 18 12:54:00 AM IST 2026

*/
