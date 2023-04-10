// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

int ftruncate(int fd, long length)
{
	/* TODO: Implement ftruncate(). */

	int out=syscall(__NR_ftruncate , fd , length);


	if (out < 0){
		errno=-out;
		return -1;
	}


	return 0;
}
