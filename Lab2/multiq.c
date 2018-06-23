#include "multiq.h"

MultiQ newMQ(int num){
	MultiQ mq = (MultiQ)malloc(sizeof(struct multiq));
	mq->num = num;
	mq->arr = (Queue*)malloc(sizeof(Queue)*num);
	int i;	
	for(i = 0;i <num; i++){
		(mq->arr)[i] = newQ();
	}
	return mq;
}

MultiQ addMQ(MultiQ mq, Task t){
	Element e = (Element)malloc(sizeof(struct Node));
	e->key = t.id;
	e->next = NULL;
	//printf("%d\n",(mq->arr)[t.priority -1]->count);
	addQ((mq->arr)[t.priority -1],e);
	return mq;
}

Task nextMQ(MultiQ mq){
	Key k;
	Priority p;
	int i;	
	for(i = 0; i < mq->num; i++){
		if(!isEmptyQ((mq->arr)[i])){
			k = front((mq->arr)[i])->key;
			p = i+1;
			break; 
		}
	}
	Task t;
	t.id = k;
	t.priority = p;
	return t;
}

MultiQ delNextMQ(MultiQ mq){
	int i;
	for(i = 0; i < mq->num; i++){
		if(!isEmptyQ((mq->arr)[i])){
			(mq->arr)[i] = delQ((mq->arr)[i]);
			break;
		}
	}
	return mq;

}

bool isEmptyMQ(MultiQ mq){
	int i;
	bool flag = true;
	for(i = 0;i<mq->num;i++){
		if(!isEmptyQ((mq->arr)[i])){
			flag = false;		
		}	
	}
	return flag;
}

int sizeMQ(MultiQ mq){
	int size = 0;
	int i;	
	for(i=0; i< mq->num;i++){
		size += lengthQ((mq->arr)[i]);	
	}
	return size;
}
int sizeMQbyPriority(MultiQ mq, Priority p){
	return lengthQ((mq->arr)[p-1]);
}

