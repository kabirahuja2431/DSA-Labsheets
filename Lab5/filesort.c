#include<stdio.h>
#include<stdlib.h>
#include "MS.h"

void merge_files(char* f1, char* f2, char* f,int n){
	FILE* fl1 = fopen(f1,"r");
	FILE* fl2 = fopen(f2,"r");
	
	FILE* w1 = fopen(f,"w");
	int i = 1;
	int j = 1;
	float cg1;
	float cg2;
	char name[50]; 
	fscanf(fl1,"%[^,],%f\n",name,&cg1);
	fscanf(fl2,"%[^,],%f\n",name,&cg2);
	printf("%f %f\n",cg1,cg2);
	while(i<n+1 && j <n+1){
		if(cg1 < cg2){
		if(cg1==9.990000) printf("hello!\n");
			fprintf(w1,"%f\n",cg1);
			if(!feof(fl1)) fscanf(fl1,"%[^,],%f\n",name,&cg1);
			i+= 1;
		}
		else{
		if(cg2==9.99) printf("hello!\n");
			fprintf(w1,"%f\n",cg2);
			if(!feof(fl2)) fscanf(fl2,"%[^,],%f\n",name,&cg2);
			j+=1;
		}
	}
	/*if(cg1 > cg2){
		fprintf(w1,"%f\n",cg1);
		fprintf(w1,"%f\n",cg2);
	}
	else{
		fprintf(w1,"%f\n",cg2);
		fprintf(w1,"%f\n",cg1);
	}*/
	printf("%d %d\n",i,j);
	printf("%f %f\n",cg1,cg2);
	if(i<n){
		printf("%d",i);
		fprintf(w1,"%f\n",cg1);
		while(i<n){
		if(cg1==9.99) printf("hello!\n");
			fscanf(fl1,"%[^,],%f\n",name,&cg1);
			fprintf(w1,"%f\n",cg1);
			i++;
		}
	}
	if(j<n){
		printf("hi\n");
		fprintf(w1,"%f\n",cg2);
		while(j<n){
		if(cg2==9.99) printf("hello!\n");
			fscanf(fl2,"%[^,],%f\n",name,&cg2);
			fprintf(w1,"%f\n",cg2);
			j++;
		}
	}

}

int main(){
	FILE *fp = fopen("10240.txt","r");
	//Splitting the big file into 2 small files
	FILE *wp1 = fopen("p1.txt","w");
	FILE *wp2 = fopen("p2.txt","w");
	float cgpa;
	char name[50];
	for(int i = 0; i< 10240/2;i++){
		fscanf(fp,"%[^,],%f\n",name,&(cgpa));
		fprintf(wp1,"%s,%f\n",name,cgpa);
	}
	
	for(int i = 0; i< 10240/2;i++){
		fscanf(fp,"%[^,],%f\n",name,&(cgpa));
		fprintf(wp2,"%s,%f\n",name,cgpa);
	}
	
	fclose(fp);
	fclose(wp1);
	fclose(wp2);
	//runRecMS("p1.txt","p1_sorted.txt",10240/2);
	//runRecMS("p2.txt","p2_sorted.txt",10240/2);
	
	merge_files("p1_sorted.txt","p2_sorted.txt","sorted_file.txt",10240/2);	
	
}
