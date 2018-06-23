#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Record{
	char name[24];
	float cgpa;
};

typedef struct Record Element;

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

void merge_sort(Element* ls, int n){
	if(n == 1 || n <= 0) return;
	merge_sort(ls,n/2);
	merge_sort(ls+n/2,n- n/2);
	Element* merged = (Element*)malloc(sizeof(Element)*n);
	merge(ls,n/2,ls+n/2,n-n/2,merged);
	copy(ls,n,merged);
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

int main(){

	/*Element* ls1 = (Element*)malloc(sizeof(Element)*4);
	strcpy(ls1[0].name,"kabir");
	ls1[0].cgpa = 9.5;
	strcpy(ls1[1].name,"raj");
	ls1[1].cgpa = 7.8;
	strcpy(ls1[2].name,"karan");
	ls1[2].cgpa = 6.5;
	strcpy(ls1[3].name,"rahul");
	ls1[3].cgpa = 8;
	strcpy(ls1[4].name,"anup");
	ls1[4].cgpa = 10;
	*/
	FILE *fp = fopen("10240.txt","r");
	
	if(fp == NULL){
		printf("Error in loading file. Shame on you.\n");
		return 1;
	}
	
	int n = 10240;
	Element* ls = (Element*)malloc(sizeof(Element)*n);
	for(int i = 0; i < n;i++){		
		fscanf(fp,"%[^,],%f\n",ls[i].name,&(ls[i].cgpa));
		//printf("%s, %f\n",ls[i].name,ls[i].cgpa);
	}
	
	merge_sort_iterative(ls,n);
	
	FILE *wp = fopen("sorted_10240.txt","w");
	
	for(int i = 0; i<n;i++){
		fprintf(wp,"%s, ",ls[i].name);
		fprintf(wp,"%f\n",ls[i].cgpa);
	}
	 

}
