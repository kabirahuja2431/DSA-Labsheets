#include <stdio.h>
#include <stdlib.h>
#include "que.h"
#include "multiq.h"

int main(){
	
	Queue q = newQ();
	Element e = (Element)malloc(sizeof(struct Node));
	e->key = 5;
	e->next = NULL;
	
	q = addQ(q,e);
	
	Element e1 = (Element)malloc(sizeof(struct Node));
	e1->key = 10;
	e1->next = NULL;
	
	q = addQ(q,e1);
	
	while(!isEmptyQ(q)){
		printf("%d\n",front(q)->key);
		q = delQ(q);
	}
}
