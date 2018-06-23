#include <stdio.h>
#include <stdlib.h>
#include "que.h"

typedef int Priority;
struct multiq{
	Queue* arr;
	int num;
};

struct Tasks{
	Key id;
	Priority priority;
};

typedef struct Tasks Task;

typedef struct multiq* MultiQ;

MultiQ newMQ(int num);

MultiQ addMQ(MultiQ mq, Task t);

Task nextMQ(MultiQ mq);

MultiQ delNextMQ(MultiQ mq);

bool isEmptyMQ(MultiQ mq);

int sizeMQ(MultiQ mq);

int sizeMQbyPriority(MultiQ mq, Priority p);

Queue getQueueFromMQ(MultiQ mp, Priority p);





