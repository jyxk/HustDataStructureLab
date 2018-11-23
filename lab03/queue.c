/*
 * @Author: Xiuxu Jin(jyxk)
 * @Date: 2018-11-16 23:29:40
 * @LastEditors: Xiuxu Jin
 * @LastEditTime: 2018-11-18 09:39:21
 * @Description: file content
 * @Email: jyxking007@gmail.com
 */

#include "queue.h"
/**
 * @brief Is the queue empty
 * 
 * @param Q 
 * @return int 
 */
int IsQueueEmpty(Queue Q){
    return Q->Size == 0;
}

/**
 * @brief Is the queue full
 * 
 * @param Q 
 * @return int 
 */
int IsQueueFull(Queue Q) {
    return Q->Capacity == Q->Size;
}

/**
 * @brief Create a Queue object
 * 
 * @param MaxElements 
 * @return Queue 
 */
Queue CreateQueue(int MaxElements) {
    Queue Q;

    if(MaxElements < MinQueueSize) {
        printf("Queue size is too small!\n");
        return NULL;
    }
    
    Q = malloc(sizeof(struct QueueRecord));
    if(Q == NULL) {
        printf("Out of space!\n");
        return NULL;
    }
    
    Q->Array = malloc(sizeof(ElemType) * MaxElements);

    if(Q->Array == NULL) {
        printf("Out of space!\n");
        return NULL;
    }
    Q->Capacity = MaxElements;
    MakeEmpty(Q);

    return Q;
}

/**
 * @brief dispose the queue Q
 * 
 * @param Q 
 */
void DisposeQueue(Queue Q) {
    if(Q != NULL) {
        free(Q->Array);
        free(Q);
    }
}

/**
 * @brief make the queue Q empty
 * 
 * @param Q 
 */
void MakeEmpty(Queue Q){
    Q->Size = 0;
    Q->Front = 1;
    Q->Rear = 0;
}

/**
 * @brief 
 * 
 * @param Value 
 * @param Q 
 * @return int 
 */
static int Succ(int Value, Queue Q){
    if(++Value == Q->Capacity)
        Value = 0;
    return Value;
}

/**
 * @brief enqueue
 * 
 * @param X 
 * @param Q 
 */
void Enqueue(ElemType X, Queue Q){
    if(IsQueueFull(Q)) {
        printf("Full queue");
        return ;
    }
    else{
        Q->Size++;
        Q->Rear = Succ(Q->Rear, Q);
        Q->Array[Q->Rear] = X;
    }
}

/**
 * @brief get the front of the Q
 * 
 * @param Q 
 * @return ElemType
 */
ElemType Front(Queue Q) {
    return Q->Array[Q->Front];
}

/**
 * @brief dequeue
 * 
 * @param Q 
 */
void Dequeue(Queue Q) {
    if(IsQueueEmpty(Q))
        printf("Empty queue!\n");
    else {
        Q->Size--;
        Q->Front = Succ(Q->Front, Q);
    }
}

/**
 * @brief get the front and dequeue
 * 
 * @param Q 
 * @return ElemType
 */
ElemType FrontAndDequeue(Queue Q) {
    ElemType front = Front(Q);
    Dequeue(Q);
    return front;
}