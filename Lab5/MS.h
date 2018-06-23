#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Record{
	char name[24];
	float cgpa;
};

typedef struct Record Element;
void runMS(char* input_file,char* output_file, int n);
void runRecMS(char* input_file,char* output_file, int n);
void merge(Element* ls1,int n1,Element* ls2, int n2, Element* ls);
void copy(Element* ls, int n, Element* merged);
void merge_sort_iterative(Element* ls, int n);
void merge_sort(Element* ls, int n);
