#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>


int puts(const char *s)
{    

    char s1[] = "\n";
    char s2[strlen(s)+1];
    strcpy(s2,s);
    strcat(s2,s1);

    // syscall(__NR_write,1,s,strlen(s));
    // return syscall(__NR_write,1,"\n",1);
    
    return syscall(__NR_write,1,s2,strlen(s2));
}