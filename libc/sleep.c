#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

#include <sys/stat.h>
#include <internal/types.h>
#include <unistd.h>
#include <internal/syscall.h>
#include <fcntl.h>
#include <time.h>

unsigned sleep(unsigned seconds)
{
    struct timespec time ;
	time.tv_nsec = 0;
	time.tv_sec= seconds;
	if (nanosleep(&time, &time)){
		return seconds;
	}
	return 0;
}