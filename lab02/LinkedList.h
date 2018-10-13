/*
 * AUTHOR: Xiuxu Jin
 * GITHUB: jyxk
 * E_MAIL: jyxking007@gmail.com
 */

#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

#define OK 0
#define ERROR 1

//the struct of linear list
typedef int ElementType;
typedef int Status;

typedef struct ListNode {
    ElementType data;
    ListNode *next;
} ListNode;

typedef struct LinkedList {
    int ID;
    int Length;
    struct ListNode *head;
    struct LinkedList *next;
} LinkedList;

typedef struct ListSet {
    int num;
    struct LinkedList *head;
} ListSet;

typedef struct ListSet *PtrToSet;
typedef struct LinkedList *PtrToList;
typedef struct ListNode *PtrToNode;
//the function prototype
Status InitaList(LinkedList *L);
/*
 * Function Name: InitaList
 * Parameter: LinkedList *L
 * Return: Status(int)
 * Use: initial the linear list
 */


Status DestroyList(LinkedList *L);
/*
 * Function Name: DestroyList
 * Parameter: LinkedList *L
 * Return: Status(int)
 * Use: destroy the list
 */


Status ClearList(LinkedList *L);
/*
 * Function Name: ClearList
 * Parameter: LinkedList *L
 * Return: Status(int)
 * Use: clear the list
 */


Status IsListEmpty(LinkedList L);
/*
 * Function Name: IsListEmpty
 * Parameter: LinkedList L
 * Return: Status(int) 
 * Use: to know the list is empty or not
 */

int ListLength(LinkedList L);
/*
 * Function Name: ListLength
 * Parameter: LinkedList L
 * Return: length of the list(int)
 * Use: get the length of the list
 */


Status GetElem(LinkedList *L, int index, ElementType *e);
/*
 * Function Name: GetElem
 * Parameter: LinkedList *L, int index, ElementType *e
 * Return: Status(int)
 * Use: get L->data[index] return it from *e
 */


int LocateElem(LinkedList *L, ElementType e);
/*
 * Function Name: LocateElem
 * Parameter: LinkedList *L, ElementType e
 * Return: the index of e or 0 if e isn't exist
 * Use: get the index of e
 */


Status PriorElem(LinkedList *L, ElementType cur_e, ElementType *pre_e);
/*
 * Function Name: PriorElem
 * Parameter: LinkedList *L, ElementType cur_e, ElementType *pre_e
 * Return: Status(int)
 * Use: get the prior element of cur_e
 */


Status NextElem(LinkedList *L, ElementType cur_e, ElementType *next_e);
/*
 * Function Name: NextElem
 * Parameter: LinkedList *L, ElementType cur_e, ElementType *next_e
 * Return: Status(int)
 * Use: get the next element of next_e
 */


Status ListInsert(LinkedList *L, int index, ElementType e);
/* 
 * Function Name: ListInsert
 * Parameter: LinkedList *l, int index, ElementType e
 * Return: Status(int)
 * Use: insert e in front of data[index]
 */


Status ListDelete(LinkedList *L, int index, ElementType *e);
/* 
 * Function Name: ListDelete
 * Parameter: LinkedList *L, int index, ElementType *e
 * Return: Status(int)
 * Use: delete data[index] and return its value from e
 */


Status ListTraverse(LinkedList *L);
/*
 * Function Name: ListTraverse
 * Parameter: LinkedList *L
 * return: Status(int)
 * Use: traverse L
 */


#endif