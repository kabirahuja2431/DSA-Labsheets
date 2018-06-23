#include "MS.h"

void runRecMS(char* input_file,char* output_file, int n){

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
	FILE *fp = fopen(input_file,"r");
	
	if(fp == NULL){
		printf("Error in loading file. Shame on you.\n");
		return;
	}
	
	Element* ls = (Element*)malloc(sizeof(Element)*n);
	for(int i = 0; i < n;i++){		
		fscanf(fp,"%[^,],%f\n",ls[i].name,&(ls[i].cgpa));
		//printf("%s, %f\n",ls[i].name,ls[i].cgpa);
	}
	
	merge_sort(ls,n);
	
	FILE *wp = fopen(output_file,"w");
	
	for(int i = 0; i<n;i++){
		fprintf(wp,"%s, ",ls[i].name);
		fprintf(wp,"%f\n",ls[i].cgpa);
	}
	 

}
