#ifndef _Queue_h

#include "BinTree.h"

struct QueueRecord;
typedef struct QueueRecord *Queue;
typedef PtrToNode ElementType;

int IsQueueEmpty(Queue Q);
int IsQueueFull(Queue Q);
Queue CreateQueue(int MaxElements);
void DisposeQueue(Queue Q);
void MakeEmpty(Queue Q);
void Enqueue(ElementType X, Queue Q);
ElementType Front(Queue Q);
void Dequeue(Queue Q);
ElementType FrontAndDequeue(Queue Q);

#endif

//place in implementation file
//Queue implementation is a dynamically allocated array
#define MinQueueSize (50)

struct QueueRecord{
    int Capacity;
    int Front;
    int Rear;
    int Size;
    ElementType *Array;
};