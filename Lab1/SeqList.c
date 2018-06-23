#include<stdio.h>
#include<stdlib.h>

SeqList* newList(){

    SeqList* sl;
    sl = (SeqList*)malloc(sizeof(SeqList));
    sl->head = NULL;
    sl->size = 0;
    return sl;

}

SeqList* insertInOrder(SeqList* sl,Element e, Key k){

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->element = e;
    newNode->key = k;
    newNode->next = NULL;
    sl->size++;

    //Boundary cases
    if(sl->head == NULL){
        sl->head = newNode;
        sl->tail = newNode;
        return sl;
    }

    if(sl->head->next == NULL){
            if(k >= sl->head->key){
                sl->head->next = newNode;
                sl->tail = newNode;
            }
            else{
                Node* temp = sl->head;
                sl->head = newNode;
                newNode->next = temp;
            }
            return sl;

    }

    Node* temp1 = sl->head;
    Node* temp2 = sl->head;

    while(temp1!=NULL){

        if(temp1->key >= k) break;
        temp2 = temp1;
        temp1 = temp1->next;

    }

    temp2->next = newNode;
    newNode->next = temp1;
    if(temp2 == sl->tail) sl->tail = newNode;
    return sl;
}

SeqList* insertAtFront(SeqList* sl,Element e,Key k){

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->element = e;
    newNode->key = k;
    newNode->next = NULL;

    Node* temp = sl->head;
    sl->head = newNode;
    newNode->next = temp;
    if(sl->tail == NULL){
        sl->tail = newNode;
    }
    sl->size++;
    return sl;


}

SeqList* insertAtEnd(SeqList* sl, Element e,Key k){

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->element = e;
    newNode->key = k;
    newNode->next = NULL;
    sl->size++;
    if(sl->head == NULL){
            sl->head = newNode;
            sl->tail = newNode;
            return sl;
    }
    sl->tail->next = newNode;
    sl->tail = newNode;
    return sl;

}

SeqList* deleteAtFront(SeqList* sl){
    if(sl->size==0) return sl;
    sl->size--;
    if(sl->size==1){
        Node* temp = sl->head;
        sl->head = NULL;
        sl->tail = NULL;
        free(temp);
        return sl;
    }
    Node*temp = sl->head;
    sl->head = sl->head->next;
    free(temp);
    return sl;


}

SeqList* delete(SeqList* sl, Element e){
    if(sl->size == 0) return sl;

    Node* temp1 = sl->head;
    Node* temp2 = sl->head;

    while(temp1!=NULL){
        if(temp1->element == e){
            break;
        }
        temp2 = temp1;
        temp1 = temp1->next;
    }
    if(temp1==NULL) return sl;
    sl->size--;
    if(temp1 == temp2){
        Node* temp = sl->head;
        sl->head = NULL;
        sl->tail = NULL;
        free(temp);
        return sl;
    }
    temp2->next = temp1->next;
    return sl;

}

Element find(SeqList* sl,Key k){
    if(sl->size==0){
        return -1;
    }
    Node* temp = sl->head;
    Element e = -1;
    while(temp!=NULL){
        if(temp->key == k){
            e = temp->element;
            break;
        }
        temp = temp->next;
    }
    return e;
}

void print_list(SeqList* sl){

        Node* temp = sl->head;
        while(temp!=NULL){
            printf("%d\n",temp->element);
            temp = temp->next;
        }
}
