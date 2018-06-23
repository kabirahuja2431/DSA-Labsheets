#include "MS.h"

void merge_sort(Element* ls, int n){
	if(n == 1 || n <= 0) return;
	merge_sort(ls,n/2);
	merge_sort(ls+n/2,n- n/2);
	Element* merged = (Element*)malloc(sizeof(Element)*n);
	merge(ls,n/2,ls+n/2,n-n/2,merged);
	copy(ls,n,merged);
}
