typedef int Key;
enum boolean{false,true};
typedef enum boolean bool;
struct Node{
	Key key;
	struct Node* next;
};
typedef struct Node* Element;

struct queue{
	Element head;
	Element tail;
	int count;
};

typedef struct queue* Queue;

Queue newQ();

bool isEmptyQ(Queue q);

Queue addQ(Queue q, Element e);

Queue delQ(Queue q);

Element front(Queue q);

int lengthQ(Queue q);
