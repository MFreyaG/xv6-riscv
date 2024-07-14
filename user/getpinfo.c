#include "kernel/types.h"
#include "kernel/stat.h"
#include "kernel/pstat.h"
#include "user/user.h"

int main(int argc, char *argv[]) {
    struct pstat pstat;
    getpinfo(&pstat);

    for(int i = 0; i < NPROC; i++){
        printf("Process %d:\n inuse(%d) tickets(%d) ticks(%d) pid(%d)\n", i, pstat.inuse, pstat.tickets, pstat.ticks, pstat.pid);
    }

    exit(0);
}