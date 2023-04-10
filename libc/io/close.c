// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int close(int fd)
{
	/* TODO: Implement close(). */
	int out= syscall(__NR_close , fd);

	if(out<0){
		errno=-out;
		return -1;
	}
	return 0;
}
