// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	/* TODO: Implement malloc(). */
	void *p = NULL;

	int to_alloc =1;
	while(to_alloc < (int) size){
		to_alloc*=4096;
	}

	p = mmap(NULL, to_alloc, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);

	mem_list_add(p,to_alloc);

	return p;
}

void *calloc(size_t nmemb, size_t size)
{
	/* TODO: Implement calloc(). */
	void *p = NULL;

	p = mmap(NULL, 4096, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	memset(p, '0', nmemb);

	mem_list_add(p,nmemb);

	return p;
}

void free(void *ptr)
{
	/* TODO: Implement free(). */

	if(!ptr) return;
	
	struct mem_list *data;

	data=mem_list_find(ptr);

	int to_alloc =1;
		while(to_alloc < (int) data->len){
			to_alloc*=4096;
		}


	mem_list_del(ptr);
	munmap(ptr ,to_alloc);
}

void *realloc(void *ptr, size_t size)
{
	/* TODO: Implement realloc(). */
	struct mem_list *data;
	data=mem_list_find(ptr);


	size_t old_size = data->len;
	void *old_address = data->start;

	// munmap(old_address , 4096);
	mem_list_del(old_address);

	void *p= NULL;

	p = mremap(old_address, old_size, size , MREMAP_MAYMOVE);

	mem_list_add(p,size);

	return p;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	/* TODO: Implement reallocarray(). */
	
	if (nmemb && size > -1 / nmemb) {
		return 0;
	}

	return realloc(ptr, size * nmemb);
}
