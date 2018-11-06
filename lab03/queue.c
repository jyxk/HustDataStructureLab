#include "queue.h"

int IsEmpty(Queue Q){
    return Q->Size == 0;
}

int IsFull(Queue Q) {
    return Q->Capacity == Q->Size;
}

Queue CreateQueue(int MaxElements) {
    Queue Q;

    if(MaxElements < MinQueueSize)
        Error("Queue size is too small!\n");
    
    Q = malloc(sizeof(struct QueueRecord));
    if(Q == NULL)
        FatalError("Out of space!\n");
    
    Q->Array = malloc(sizeof(ElementType) * MaxElements);
    if(Q->Array == NULL)
        FatalError("Out of space!\n");
    Q->Capacity = MaxElements;
    MakeEmpty(Q);

    return Q;
}

void DisposeQueue(Queue Q) {
    if(Q != NULL) {
        free(Q->Array);
        free(Q);
    }
}

void MakeEmpty(Queue Q){
    Q->Size = 0;
    Q->Front = 1;
    Q->Rear = 0;
}

static int Succ(int Value, Queue Q){
    if(++Value == Q->Capacity)
        Value = 0;
    return Value;
}

void Enqueue(ElementType X, Queue Q){
    if(IsFull(Q))
        Error("Full queue");
    else{
        Q->Size++;
        Q->Rear = Succ(Q->Rear, Q);
        Q->Array[Q->Rear] = X;
    }
}

ElementType Front(Queue Q) {
    return Q->Array[Q->Front];
}

void Dequeue(Queue Q) {
    if(IsEmpty(Q))
        Error("Empty queue");
    else {
        Q->Size--;
        Q->Front = Succ(Q->Front, Q);
    }
}

ElementType FrontAndDequeue(Queue Q) {
    ElementType front = Front(Q);
    Dequeue(Q);
    return front;
}