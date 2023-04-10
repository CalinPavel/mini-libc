// SPDX-License-Identifier: BSD-3-Clause

#include <sys/mman.h>
#include <errno.h>
#include <internal/syscall.h>

void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)
{
	/* TODO: Implement mmap(). */
	long out;


	out = syscall(__NR_mmap , addr , length , prot , flags , fd , offset);

	if(fd > 0){
		errno=-out;
		return MAP_FAILED;
	}


	if(flags == MAP_ANONYMOUS){
		errno=EINVAL;
		return MAP_FAILED;
	}
	
	return out;
}

void *mremap(void *old_address, size_t old_size, size_t new_size, int flags)
{
	/* TODO: Implement mremap(). */
	syscall(__NR_mremap , old_address , old_size , new_size , flags);
}

int munmap(void *addr, size_t length)
{
	/* TODO: Implement munmap(). */
	long out;

	out = syscall(__NR_munmap , addr , length);
	return out;
}
