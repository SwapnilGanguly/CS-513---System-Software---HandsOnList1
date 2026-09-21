/*2. Write a simple program to execute in an infinite loop at the background. Go to /proc directory and
identify all the process related information in the corresponding proc directory*/

#include <stdio.h>
#include <unistd.h>

int main() {

    while (1) {
        sleep(5);
    }
    return 0;
}

/*Output: 

swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P2$ gcc 2.c
swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P2$ ./a.out &
[1] 22310
swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P2$ cat /proc/22310/status
Name:	a.out
Umask:	0002
State:	S (sleeping)
Tgid:	22310
Ngid:	0
Pid:	22310
PPid:	15323
TracerPid:	0
Uid:	1000	1000	1000	1000
Gid:	1000	1000	1000	1000
FDSize:	256
Groups:	4 24 27 30 46 100 111 114 1000 
NStgid:	22310
NSpid:	22310
NSpgid:	22310
NSsid:	15323
Kthread:	0
VmPeak:	    2700 kB
VmSize:	    2636 kB
VmLck:	       0 kB
VmPin:	       0 kB
VmHWM:	    1620 kB
VmRSS:	    1620 kB
RssAnon:	      92 kB
RssFile:	    1528 kB
RssShmem:	       0 kB
VmData:	      92 kB
VmStk:	     132 kB
VmExe:	       4 kB
VmLib:	    1828 kB
VmPTE:	      44 kB
VmSwap:	       0 kB
HugetlbPages:	       0 kB
CoreDumping:	0
THP_enabled:	1
untag_mask:	0xffffffffffffffff
Threads:	1
SigQ:	0/61107
SigPnd:	0000000000000000
ShdPnd:	0000000000000000
SigBlk:	0000000000000000
SigIgn:	0000000000000000
SigCgt:	0000000000000000
CapInh:	0000000800000000
CapPrm:	0000000000000000
CapEff:	0000000000000000
CapBnd:	000001ffffffffff
CapAmb:	0000000000000000
NoNewPrivs:	0
Seccomp:	0
Seccomp_filters:	0
Speculation_Store_Bypass:	thread vulnerable
SpeculationIndirectBranch:	conditional enabled
Cpus_allowed:	ff
Cpus_allowed_list:	0-7
Mems_allowed:	00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000001
Mems_allowed_list:	0
voluntary_ctxt_switches:	8
nonvoluntary_ctxt_switches:	0
x86_Thread_features:	
x86_Thread_features_locked:*/
