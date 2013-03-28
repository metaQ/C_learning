#ifndef QSORT_H
#define QSORT_H 

void meta_qsort(void *base, size_t nmemb, size_t size, 
				int(*compar)(const void *, const void *));
#endif
