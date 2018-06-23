#include<stdio.h>
#include "multiq.h"
#include<sys/time.h>

MultiQ loadData(FILE *f){
	MultiQ mq = newMQ(10);
	Key k;
	Priority p;
	while(fscanf(f,"%d",&k) &&!feof(f)){
		fgetc(f);
		fscanf(f,"%d",&p);
		Task t;
		t.id = k;
		t.priority = p;
		//printf("%d %d\n",k,p);
		mq = addMQ(mq,t);
	
	}
	return mq;
}

MultiQ testDel(MultiQ mq,int num){
	int i;
	for(i = 0; i<num; i++){
		mq = delNextMQ(mq);
	}
	return mq;
}
int main(){
	FILE *f;
        if((f=fopen("input100.txt","r"))==NULL)
        {
                printf("cannot open the file");
                exit(1);
    }
	struct timeval t1,t2;
	double elapsed_time;
	gettimeofday(&t1,NULL);
	MultiQ mq = loadData(f);
	gettimeofday(&t2,NULL);
	elapsed_time = (t2.tv_sec - t1.tv_sec)*1000;
	elapsed_time += (t2.tv_usec - t1.tv_usec)*1000;
	printf("%lf\n",elapsed_time);
	gettimeofday(&t1,NULL);
	mq = testDel(mq,100);
	gettimeofday(&t2,NULL);
	elapsed_time = (t2.tv_sec - t1.tv_sec)*1000;
	elapsed_time += (t2.tv_usec - t1.tv_usec)*1000;
	printf("%lf\n",elapsed_time);

	return 0;
}
