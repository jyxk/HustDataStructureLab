/*
 * AUTHOR: Xiuxu Jin
 * GITHUB: jyxk
 * E_MAIL: jyxking007@gmail.com
 */

#ifndef _ARRAYLIST_H
#define _ARRAYLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

#define OK 0
#define ERROR 1

#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10

//the struct of linear list
typedef int ElementType;
typedef int Status;

typedef struct SqList {
    int ListID;
    ElementType *data;
    int length;
    int listsize;
    
    struct SqList *next;
} SqList;

typedef struct ListSet {
    int num;
    struct SqList *head;
} ListSet;

typedef struct ListSet *PtrToSet;

//the function prototype
Status InitaList(SqList *L);
/*
 * Function Name: InitaList
 * Parameter: SqList *L
 * Return: Status(int)
 * Use: initial the linear list
 */


Status DestroyList(SqList *L);
/*
 * Function Name: DestroyList
 * Parameter: SqList *L
 * Return: Status(int)
 * Use: destroy the list
 */


Status ClearList(SqList *L);
/*
 * Function Name: ClearList
 * Parameter: SqList *L
 * Return: Status(int)
 * Use: clear the list
 */


Status IsListEmpty(SqList L);
/*
 * Function Name: IsListEmpty
 * Parameter: SqList L
 * Return: Status(int) 
 * Use: to know the list is empty or not
 */

int ListLength(SqList L);
/*
 * Function Name: ListLength
 * Parameter: SqList L
 * Return: length of the list(int)
 * Use: get the length of the list
 */


Status GetElem(SqList *L, int index, ElementType *e);
/*
 * Function Name: GetElem
 * Parameter: SqList *L, int index, ElementType *e
 * Return: Status(int)
 * Use: get L->data[index] return it from *e
 */


int LocateElem(SqList *L, ElementType e);
/*
 * Function Name: LocateElem
 * Parameter: SqList *L, ElementType e
 * Return: the index of e or 0 if e isn't exist
 * Use: get the index of e
 */


Status PriorElem(SqList *L, ElementType cur_e, ElementType *pre_e);
/*
 * Function Name: PriorElem
 * Parameter: SqList *L, ElementType cur_e, ElementType *pre_e
 * Return: Status(int)
 * Use: get the prior element of cur_e
 */


Status NextElem(SqList *L, ElementType cur_e, ElementType *next_e);
/*
 * Function Name: NextElem
 * Parameter: SqList *L, ElementType cur_e, ElementType *next_e
 * Return: Status(int)
 * Use: get the next element of next_e
 */


Status ListInsert(SqList *L, int index, ElementType e);
/* 
 * Function Name: ListInsert
 * Parameter: SqList *l, int index, ElementType e
 * Return: Status(int)
 * Use: insert e in front of data[index]
 */


Status ListDelete(SqList *L, int index, ElementType *e);
/* 
 * Function Name: ListDelete
 * Parameter: SqList *L, int index, ElementType *e
 * Return: Status(int)
 * Use: delete data[index] and return its value from e
 */


Status ListTraverse(SqList *L);
/*
 * Function Name: ListTraverse
 * Parameter: SqList *L
 * return: Status(int)
 * Use: traverse L
 */


#endif