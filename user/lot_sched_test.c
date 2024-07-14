#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

#define MAX_WAIT 9999999

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Signature: lot_sched_test t1 t2 t3\n");
        exit(1);
    }

    int tickets1 = atoi(argv[1]);
    int tickets2 = atoi(argv[2]);
    int tickets3 = atoi(argv[3]);

    int pid1 = fork();
    if (pid1 == 0) {
        settickets(tickets1);
        while (1) {
            for(int i = 0; i < MAX_WAIT; i++){
            }
        }
    }

    int pid2 = fork();
    if (pid2 == 0) {
        settickets(tickets2);
        while (1) {
            for(int i = 0; i < MAX_WAIT; i++){
            }
        }
    }

    int pid3 = fork();
    if (pid3 == 0) {
        settickets(tickets3);
        while (1) {
            for(int i = 0; i < MAX_WAIT; i++){
            }
        }
    }

    struct pstat pinfo;
    printf("step,pid,tickets,ticks\n");
    for(int t = 0; t<100; t++){
        sleep(60);

        getpinfo(&pinfo);
        for (int i = 0; i < NPROC; i++) {
            if (pinfo.inuse[i] && pinfo.tickets[i] > 1) {
                printf("%d,%d,%d,%d\n", t, pinfo.pid[i], pinfo.tickets[i], pinfo.ticks[i]);
            }
        }
    }

    // Kill child processes
    kill(pid1);
    kill(pid2);
    kill(pid3);
    
    // Wait for children to exit
    wait(0);
    wait(0);
    wait(0);

    exit(0);

    return 0;
}