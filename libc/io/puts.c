#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>


int puts(const char *s)
{
        write(-1,s,strlen(s));
}