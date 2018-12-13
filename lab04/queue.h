/*
 * @Author: Xiuxu Jin(jyxk)
 * @Date: 2018-11-16 23:28:12
 * @LastEditors: Xiuxu Jin
 * @LastEditTime: 2018-11-18 09:39:27
 * @Description: file content
 * @Email: jyxking007@gmail.com
 */

#ifndef _Queue_h

#include "Graph.h"

struct QueueRecord;
typedef struct QueueRecord *Queue;
typedef PtrToVertex ElemType;

int IsQueueEmpty(Queue Q);
int IsQueueFull(Queue Q);
Queue CreateQueue(int MaxElements);
void DisposeQueue(Queue Q);
void MakeEmpty(Queue Q);
void Enqueue(ElemType X, Queue Q);
ElemType Front(Queue Q);
void Dequeue(Queue Q);
ElemType FrontAndDequeue(Queue Q);

#endif

//place in implementation file
//Queue implementation is a dynamically allocated array
#define MinQueueSize (5)

struct QueueRecord{
    int Capacity;
    int Front;
    int Rear;
    int Size;
    ElemType *Array;
};

