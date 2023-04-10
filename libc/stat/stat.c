// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

int stat(const char *restrict path, struct stat *restrict buf)
{
	/* TODO: Implement stat(). */
	int fd;

	fd=open(path, O_RDONLY);

	if(fd < 0){
		return -1;
	}

	return fstatat(fd , "" , buf , AT_EMPTY_PATH);
}
