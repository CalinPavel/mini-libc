#ifndef	_TIME_H
#define _TIME_H	1
#define CLOCK_REALTIME           0
# define __STD_TYPE		typedef

struct timespec
{
#ifdef __USE_TIME_BITS64
  __time64_t tv_sec;		/* Seconds.  */
#else
  long tv_sec;		/* Seconds.  */
#endif
#if __WORDSIZE == 64 \
  || (defined __SYSCALL_WORDSIZE && __SYSCALL_WORDSIZE == 64) \
  || (__TIMESIZE == 32 && !defined __USE_TIME_BITS64)
  __syscall_slong_t tv_nsec;	/* Nanoseconds.  */
#else
# if __BYTE_ORDER == __BIG_ENDIAN
  int: 32;           /* Padding.  */
  long int tv_nsec;  /* Nanoseconds.  */
# else
  long int tv_nsec;  /* Nanoseconds.  */
  int: 32;           /* Padding.  */
# endif
#endif
};

#endif /* time.h.  */
