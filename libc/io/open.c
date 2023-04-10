// SPDX-License-Identifier: BSD-3-Clause

#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int open(const char *filename, int flags, ...)
{
	/* TODO: Implement open system call. */
	va_list valist;
	mode_t mode = 0;

	int fd;

	if((flags & O_CREAT == O_CREAT) ||  (flags & O_TMPFILE == O_TMPFILE)){
		va_start(valist ,flags);
		fd = syscall(__NR_open,filename,flags,va_arg(valist,int));
		va_end(valist);
	}
	else{
		fd = syscall(__NR_open,filename,flags,mode);
	}
 
	if(fd<0){
		errno=-fd;
		return -1;
	}
	return fd;
}
