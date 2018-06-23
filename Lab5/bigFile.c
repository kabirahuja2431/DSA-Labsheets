
#include<stdio.h>
#include<stdlib.h>

int main(){
	FILE* fp = fopen("big.txt","a");
	long big = 0;
	long target = 4.3e8;
	while(big < target){
		fprintf(fp,"%ld",rand()%target);
		big++;
	}

}
