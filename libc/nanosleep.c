#include <internal/syscall.h>
#include <internal/types.h>
#include <time.h>
#include <errno.h>


#define CLOCK_REALTIME           0

int nanosleep(const struct timespec *req, struct timespec *rem){
    int out;

    out = syscall(__NR_clock_nanosleep, 0, 0 ,req ,rem);

    if(out < 0){
        errno=-out;
        return -1;
    }
    return out; 

}