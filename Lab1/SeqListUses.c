#include<stdio.h>
#include<stdlib.h>

SeqList* merge(SeqList* sl1, SeqList* sl2){
    SeqList* sl = newList();
    Node* temp1 = sl1->head;
    Node* temp2 = sl2->head;
    while(temp1!=NULL&&temp2!=NULL){
        if(temp1->key < temp2->key){
                sl = insertAtEnd(sl,temp1->element,temp1->key);
                temp1 = temp1->next;
        }
        else{
            sl = insertAtEnd(sl, temp2->element,temp2->key);
            temp2 = temp2->next;
        }
    }
    if(temp1==NULL){
        sl->tail->next = temp2;
        sl->tail = temp2;
    }
    else{
        sl->tail->next = temp1;
        sl->tail = temp1;
    }
    sl->size = sl1->size+sl2->size;

    return sl;
}

SeqList* insertionSort(SeqList* sl){
    SeqList* sl1 = newList();
    Node* temp = sl->head;
    while(temp!=NULL){
        insertInOrder(sl1,temp->element,temp->key);
        temp = temp->next;
    }
    return sl1;
}
