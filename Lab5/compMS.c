#include"MS.h"
void merge(Element* ls1,int n1,Element* ls2, int n2, Element* ls){
	int i = 0;
	int j = 0;
	int k = 0;
	while(i<n1&&j<n2){
		if(ls1[i].cgpa > ls2[j].cgpa){
			ls[k] = ls2[j];
			j++;
		}
		else{
			ls[k] = ls1[i];
			i++;
		}
		k++;
	}
	if(i < n1){
		for(;i<n1;i++){
			ls[k] = ls1[i];
			k++;
		}
	}
	else if(j < n2){
		for(;j<n2;j++){
			ls[k] = ls2[j];
			k++;
		}
	}
}


void copy(Element* ls, int n, Element* merged){
	for(int i = 0; i <n; i++){
		ls[i] = merged[i];
	}
}



void merge_sort_iterative(Element* ls, int n){
	int maxslsz;
	for(maxslsz = 1; maxslsz < n;maxslsz = maxslsz*2);
	maxslsz /= 2;
	for(int slsz = 1; slsz <= maxslsz;slsz *= 2){
		for(int s1 = 0; s1 < n; s1+=2*slsz){

			int s2 = s1+slsz;
			int e2;
			if(s2 > n-1){
				//continue;					
				e2 = n;
				s2 = (e2 + s1)/2;
				/*if(s2-1 > n-1){
					s2 = n;

				}*/
			}
			else{
				e2 = s2+slsz;
				if(e2 > n) e2 = n;

			}
			Element* merged = (Element*)malloc(sizeof(Element)*(2*slsz));

			merge(ls+s1,s2-s1,ls+s2,e2-s2,merged);
			copy(ls+s1,e2-s1,merged);
			free(merged);

		}
	}

}
