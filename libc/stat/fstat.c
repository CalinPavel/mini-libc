// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>

int fstat(int fd, struct stat *st)
{
	/* TODO: Implement fstat(). */
	return fstatat(fd , "" , st , AT_EMPTY_PATH);
}
