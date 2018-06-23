#include <stdio.h>
#include <stdlib.h>
#include "que.h"

Queue newQ(){
	Queue q = (Queue)malloc(sizeof(struct queue));
	q->count = 0;
	q->head = NULL;
	q->tail = NULL;
	return q;
}

bool isEmptyQ(Queue q){
	if(q->count == 0){
		return true;
	}
	return false;
}

Queue addQ(Queue q, Element e){
	if(isEmptyQ(q)){
		q->head = e;
		q->tail = e;
		q->count++;
		return q;
	}
	q->tail->next = e;
	q->tail = e;
	q->count++;
	return q;
}

Queue delQ(Queue q){
	
	if(isEmptyQ(q)){
		return q;
	}
	Element e = q->head;
	q->head = q->head->next;
	q->count--;
	free(e);
	if(q->head == NULL){
		q->tail = NULL;
	}
	return q;
}

Element front(Queue q){
	return q->head;
}

int lengthQ(Queue q){
	return q->count;
}




