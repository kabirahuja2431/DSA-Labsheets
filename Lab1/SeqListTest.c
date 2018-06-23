#include<stdio.h>
#include<stdlib.h>
int main(){
    SeqList* sl = newList();
    sl = insertInOrder(sl,4,0);
    sl = insertInOrder(sl,5,10);
    sl = insertInOrder(sl,10,2);
    sl = insertInOrder(sl,13,9);
    sl = insertAtEnd(sl,2,6);
    sl = insertAtEnd(sl,7,17);
    sl = insertionSort(sl);
        print_list(sl);

    SeqList* sl1 = newList();
    sl1 = insertInOrder(sl1,1,1);
    sl1 = insertInOrder(sl1,6,11);
    sl1 = insertInOrder(sl1,3,5);
    //print_list(sl1);
    SeqList* sl2 = merge(sl,sl1);
    //printf("%d\n",sl2->size);
    //print_list(sl2);


}

