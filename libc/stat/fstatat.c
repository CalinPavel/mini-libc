// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <internal/types.h>
#include <unistd.h>
#include <internal/syscall.h>
#include <fcntl.h>
#include <errno.h>

#define makedev(x, y) ( \
		(((x)&0xfffff000ULL) << 32) | \
	(((x)&0x00000fffULL) << 8) | \
		(((y)&0xffffff00ULL) << 12) | \
	(((y)&0x000000ffULL)) \
	)

/* Structure describing file characteristics as defined in linux/stat.h */
struct statx {
	uint32_t stx_mask;
	uint32_t stx_blksize;
	uint64_t stx_attributes;
	uint32_t stx_nlink;
	uint32_t stx_uid;
	uint32_t stx_gid;
	uint16_t stx_mode;
	uint16_t pad1;
	uint64_t stx_ino;
	uint64_t stx_size;
	uint64_t stx_blocks;
	uint64_t stx_attributes_mask;
	struct {
		int64_t tv_sec;
		uint32_t tv_nsec;
		int32_t pad;
	} stx_atime, stx_btime, stx_ctime, stx_mtime;
	uint32_t stx_rdev_major;
	uint32_t stx_rdev_minor;
	uint32_t stx_dev_major;
	uint32_t stx_dev_minor;
	uint64_t spare[14];
};

int fstatat_statx(int fd, const char *restrict path, struct stat *restrict st, int flag)
{
	/* TODO: Implement fstatat_statx(). Use statx and makedev above. */
	// struct statx sys_struct;

	// int out;
	// out=syscall(__NR_statx , fd , path , flag , 0x7ff ,&sys_struct );
	// if(out<0)
	// {
	// 	errno=-out;
	// 	return -1;
	// }
	// st->st_atime = sys_struct.stx_atime.tv_sec;
	// st->st_atimensec;
	// st->st_blksize=sys_struct.stx_blksize;
	// st->st_blocks=sys_struct.stx_blocks;
	// st->st_ctime=sys_struct.stx_ctime.pad;
	// st->st_ctimensec;
	// st->st_dev=makedev(sys_struct.stx_dev_major , sys_struct.stx_dev_minor);
	// st->st_gid=sys_struct.stx_gid;
	// st->st_ino=sys_struct.stx_ino;
	// st->st_mode=sys_struct.stx_mode;
	// st->st_mtime=sys_struct.stx_mtime.pad;
	// st->st_atimensec=sys_struct.stx_mtime.tv_nsec;
	// st->st_nlink=sys_struct.stx_nlink;
	// st->st_rdev=makedev(sys_struct.stx_rdev_major,sys_struct.stx_rdev_minor);
	// st->st_size=sys_struct.stx_size;
	// st->st_uid=sys_struct.stx_uid;
	// st->__glibc_reserved=sys_struct;
	// st->__pad0=sys_struct.pad1;

	return 0;
}

int fstatat(int fd, const char *restrict path, struct stat *restrict st, int flag)
{
	/* TODO: Implement fstatat(). Use fstatat_statx(). */
	struct stat sys_struct;

	int out;

	out=syscall(__NR_newfstatat, fd , path ,st , flag);

	if(out){
		errno=-out;
		return -1;
	}

	return 0;
}
