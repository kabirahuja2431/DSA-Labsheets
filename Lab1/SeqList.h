typedef int Element;
typedef int Key;

typedef struct Nodes{
    Element element;
    Key key;
    struct Node* next;

}Node;

typedef struct SeqLists{

    Node* head;
    Node* tail;
    int size;

}SeqList;

SeqList* newList();

SeqList* insertInOrder(SeqList* sl,Element e, Key k);

SeqList* insertAtFront(SeqList* sl,Element e,Key k);

SeqList* insertAtEnd(SeqList* sl, Element e,Key k);

SeqList* deleteAtFront(SeqList* sl);

SeqList* delete(SeqList* sl, Element e);

Element find(SeqList* sl,Key k);

void print_list(SeqList* sl);
