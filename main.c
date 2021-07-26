//
//  main.c
//  Heap
//
//  Created by duh8n on 2021/07/22.
//

#include <stdio.h>
#include <stdlib.h>

#define HEAP_LENGTH 100

typedef int Data;
typedef int (*PriorityComp)(Data d1, Data d2);

typedef struct _heap{
    PriorityComp * comp;
    Data harr[HEAP_LENGTH];
    int numofdata;
} Heap;

int getParentIdx(int idx){
    return idx / 2;
}

int getLChildIdx(int idx){
    return idx * 2;
}

int getRChildIdx(int idx){
    return idx * 2 + 1 ;
}

void HeapInit(Heap * ph){
    ph->comp = NULL;
    ph->numofdata = 0;
}

void InsertData(Heap * ph, Data data){
    int nidx = (ph->numofdata)+1;
    
    while(nidx != 1 && data < ph->harr[getParentIdx(nidx)]){
        ph->harr[nidx] = ph->harr[getParentIdx(nidx)];
        nidx = getParentIdx(nidx);
    }
    
    ph->harr[nidx] = data;
    ph->numofdata += 1;
    
}


int main(int argc, const char * argv[]) {
    
    Heap heap;
    HeapInit(&heap);
    InsertData(&heap, 5);
    InsertData(&heap, 9);
    InsertData(&heap, 6);
    InsertData(&heap, 8);
    InsertData(&heap, 7);
    InsertData(&heap, 3);
    
    return 0;
}
