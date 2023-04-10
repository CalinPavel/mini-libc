/* SPDX-License-Identifier: BSD-3-Clause */

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	/* TODO: Implement strcpy(). */
		for(int i=0;i<=(int) strlen(source);i++){
			destination[i]=source[i];
		}

	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncpy(). */
		for(int i=0;(int) i<=len;i++){
			destination[i]=source[i];
		}

	return destination;
}

char *strcat(char *destination, const char *source)
{
	/* TODO: Implement strcat(). */
	int j=0;
	for(int i = strlen(destination); i<=(int)(strlen(destination)+strlen(source)); i++){
		destination[i]=source[j];
		j++;
	}
	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncat(). */
   	int keep = strlen(destination) , i;

    for (i = 0; i < (int)len && source[i] != '\0'; i++){
        destination[keep + i] = source[i];
	}

    destination[keep + i] = '\0';

    return destination;
}

int strcmp(const char *str1, const char *str2)
{
	/* TODO: Implement strcmp(). */
	if(strlen(str1) > strlen(str2)){
		return 1;
	}

	if(strlen(str1) < strlen(str2)){
		return -1;
	}


	for(int i=0;i<=(int)strlen(str1);i++){
		if(((int)str1[i]) > ((int)str2[i])){
			return 1;
		}
		if(((int)str1[i]) < ((int)str2[i])){
			return -1;
		}
	}

	return 0;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	/* TODO: Implement strncmp(). */
	for(int i=0;i<=(int)len-1;i++){
		if(((int)str1[i]) > ((int)str2[i])){
			return 1;
		}
		if(((int)str1[i]) < ((int)str2[i])){
			return -1;
		}
	}

	return 0;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	/* TODO: Implement strchr(). */
	for(int i=0;i<=(int)strlen(str);i++){
		if((int)str[i] == c){
			return &str[i];
		}
	}

	return NULL;
}

char *strrchr(const char *str, int c)
{
	/* TODO: Implement strrchr(). */
	for(int i=strlen(str);i>=0;i--){
		if((int)str[i] == c){
			return &str[i];
		}
	}

	return NULL;
}

char *strstr(const char *str1, const char *str2)
{
	/* TODO: Implement strstr(). */
	for (int i = 0; i <=(int)strlen(str1); i++)
	{
		if((int)str1[i] == (int)str2[0]){
			int k=i,j;
			for(j=0;j<=(int)strlen(str2);j++){
				if((int) str1[k] != (int) str2[j]){
					break;
				}
				k++;
			}

			if(j == (int)strlen(str2)){
				return &str1[i];
			}
		}
	}
	return NULL;
}

char *strrstr(const char *str1, const char *str2)
{
	/* TODO: Implement strrstr(). */
	for (int i = (int)strlen(str1); i >= 0; i--)
	{
		if((int)str1[i] == (int)str2[strlen(str2)-1]){
			int k=i,j;
			for(j=strlen(str2)-1;j>=0;j--){
				if((int) str1[k] != (int) str2[j]){
					break;
				}
				k--;
			}
			if(j == -1){
				return &str1[k+1];
			}
		}
	}
	return NULL;
}

void *memcpy(void *destination, const void *source, size_t num)
{

	/* TODO: Implement memcpy(). */
	for(int i=0;i<=(int)num;i++){
		((char*)destination)[i]=((char*)source)[i];
	}

	return &destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memmove(). */
	for(int i=0;i<=(int)num;i++){
		((unsigned char*)destination)[i]=((unsigned char*)source)[i];
	}

	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	/* TODO: Implement memcmp(). */

	for(int i=0;i<=(int)num-1;i++){
		if(((unsigned char*)ptr1)[i] > ((unsigned char*)ptr2)[i]){
			return -1;
		}
		if(((unsigned char*)ptr1)[i] < ((unsigned char*)ptr2)[i]){
			return 1;
		}
	}
		return 0;
}

void *memset(void *source, int value, size_t num)
{
	/* TODO: Implement memset(). */
	for(int i=0;i<=(int)num;i++){
		((char*)source)[i]= value;
	}
		

	return source;
}
