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

typedef struct {
    ElementType *data;
    int length;
    int listsize;
} SqList;


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


Status ListEmpty(SqList *L);
/*
 * Function Name: ListEmpty
 * Parameter: SqList *L
 * Return: Status(int) 
 * Use: to know the list is empty or not
 */

int ListLength(SqList *L);
/*
 * Function Name: ListLength
 * Parameter: SqList *L
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


Status PriorElem(SqList *L, ElementType cur_e, ElementType pre_e);
/*
 * 
 */


Status NextElem(SqList *L, ElementType cur_e, ElementType next_e);
Status ListInsert(SqList *L, int index, ElementType e);
Status ListDelete(SqList *L, int index, ElementType e);
Status ListTraverse(SqList *L);


#endif