#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[]) {
    
    int tickets = atoi(argv[1]);
    if (tickets < 1) {
        fprintf(2, "Error: ticket number must be at least 1\n");
        exit(1);
    }

    int result = settickets(tickets);
    if (result < 0) {
        fprintf(2, "Error setting tickets\n");
        exit(1);
    }

    exit(0);
}