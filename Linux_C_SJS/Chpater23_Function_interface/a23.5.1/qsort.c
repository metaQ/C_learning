/*descending*
 how to dereference using void * type 
 this is a question*/
#include <stdlib.h>
void meta_qsort(void *base, size_t nmemb, size_t size,
			int(*compar)(const void *, const void *))
{
	size_t mid;
	void *b = base;
	for (i = 0; i < nmemb; i++) {
		for (j = i; j < nmemb; j++) {
			if(compar(base+i*size, base+(i+j)*size)) {
					mid = *(base+i*size);
					*(base+i*size) = *(base+(i+j)*size);
					*(base+(i+j)*size) = *(base+i*size);
			}						
		}
	}
}
