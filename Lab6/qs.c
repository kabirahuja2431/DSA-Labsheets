#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/time.h>
struct index_pair{
	int i;
	int j;
};
typedef struct index_pair pair;

struct times{
	double IStime;
	double QStime;
};

typedef struct times Times;

struct stack{
	pair* arr;
	int length;
};

typedef struct stack Stack;

struct record{
	char name[15];
	unsigned long id;
};
typedef struct record Record;

Stack* create_stack(int size){
	Stack* s = (Stack*)malloc(sizeof(Stack));
	s->arr = (pair*)malloc(sizeof(pair)*size);
	s->length = 0;
}

Stack* push(Stack* s, pair ele){
	s->arr[s->length] = ele;
	s->length += 1;
	return s;
}

Stack* pop(Stack* s){
	s->length -= 1;
	return s;
}

pair top(Stack* s){
	return s->arr[s->length-1];
}

int is_empty(Stack* s){
	if(s->length == 0) return 1;
	else return 0;
}

void swap(Record* n1, Record* n2){
	char* temp1 = (char*)malloc(sizeof(char)*strlen(n1->name));
	unsigned long temp2;
	strcpy(temp1,n1->name);
	temp2 = n1->id;	
	strcpy(n1->name,n2->name);
	n1->id = n2->id;
	strcpy(n2->name,temp1);
	n2->id = temp2;
	/*Record temp;
	temp = *n1;
	*n1 = *n2;
	*n2 = temp;*/
}

int part(Record* A, int lo, int hi, int p){
	if(lo >= hi) return p;
	int start = lo;
	swap(&A[lo],&A[p]);
	unsigned long pivot = A[lo].id;
	while(lo < hi){
		for(;A[lo].id <= pivot;lo++);
		for(;A[hi].id>pivot; hi--);
		if(lo < hi) swap(&A[lo],&A[hi]);
	}
	int pindex;
	if(lo == hi) pindex = lo;
	else pindex = lo-1;
	swap(&A[pindex],&A[start]);
	return pindex; 
}

void insert_order(Record* A, int lo, int hi, Record ele){
	for(int i = lo; i<=hi;i++){
		if(ele.id < A[i].id){
			for(int j = hi; j >= i; j--){
				strcpy(A[j+1].name,A[j].name);
				A[j+1].id = A[j].id;			
			}
			strcpy(A[i].name,ele.name);
			A[i].id = ele.id;
			break;
		}
	}
}

void insertion_sort(Record* A, int lo, int hi){
	for(int i = 1; i <= hi; i++){
		insert_order(A,lo,i-1,A[i]);
	}	
		
}

void qs_iter(Record* A, int lo, int hi,int cutoff){
	Stack* s = create_stack(100);
	int pindex;	
	pair p;
	p.i = lo;
	p.j = hi;
	push(s,p);	
	while(!is_empty(s)){
		p = top(s);
		lo = p.i;
		hi = p.j;
		pop(s);
		while(lo < hi){
			if((hi-lo+1) > cutoff){
				insertion_sort(A,lo,hi);
				break;
			}
			pindex = rand()%(hi-lo+1) + lo;
			pindex = part(A,lo,hi,pindex);
			p.i = lo;
			p.j = pindex-1;			
			push(s,p);
			lo = pindex +1;				
		}
	}
	
}

Times* test_run(Record* A, int size){
	Record* copy = (Record*)malloc(sizeof(Record)*size);
	for(int i = 0; i <size; i++){
		copy[i] = A[i];
	}
	struct timeval t1,t2;
	double QStime;
	gettimeofday(&t1,NULL);
	qs_iter(A,0,size-1,0);
	gettimeofday(&t2,NULL);
	QStime = (t2.tv_sec-t1.tv_sec)*1000000;
	QStime += (t2.tv_usec - t1.tv_usec);
	double IStime;
	gettimeofday(&t1,NULL);
	insertion_sort(A,0,size-1);
	gettimeofday(&t2,NULL);
	IStime = (t2.tv_sec-t1.tv_sec)*1000000;
	IStime += (t2.tv_usec - t1.tv_usec);
	
	Times* t = (Times*)malloc(sizeof(Times));
	t->QStime = QStime;
	t->IStime = IStime;
	return t;
}	

int getCutoff(Record* A, int size){
	int min = 0;
	int max = size-1;
	Times t;
	int mid;
	while(min < max){
		mid = (min+max)/2;
		t = test_run(A,mid-min+1);
		if(t.IStime < t.QStime){
			min = mid+1;		
		}
		else{
			max = mid - 1;		
		}
	}
}

int main(int arc, char** argv){

	FILE* fp = fopen(argv[1],"r");
	if(fp == NULL){
		printf("Error\n");
		return 1;
	}
	int n;
	int init_size = 1000;
	Record* A = (Record*)malloc(sizeof(Record)*init_size);
	char* name;
	unsigned long id;
	int i = 0;
	while(!feof(fp)){
		if(i >= init_size){
			init_size = 2*init_size;
			A = (Record*)realloc(A,sizeof(Record)*init_size);
		}
		fscanf(fp,"%s %ld",A[i].name,&(A[i].id));
		//printf("%s %ld\n",A[i].name,A[i].id);
		i++;
	}
	n = i;
	printf("%d\n",i);
	/*qs_iter(A,0,n-1,0);
	FILE* wp = fopen("output.txt","w");
	for(int i = 0; i < n; i++){
		fprintf(wp,"%s %ld\n",A[i].name,A[i].id);
	}*/

	Times* t = test_run(A,2000);
	printf("%f %f\n",t->IStime,t->QStime);	
	
}


