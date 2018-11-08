/*
 * AUTHOR: Xiuxu Jin
 * GITHUB: jyxk
 * E_MAIL: jyxking007@gmail.com
 */

#include "ArrayList.h"


Status InitaList(SqList *L) {

    memset(L, 0, sizeof(SqList));
    L->data = (ElementType *) malloc(LIST_INIT_SIZE * sizeof(ElementType));

    if (L->data == NULL)
        exit(EXIT_FAILURE);
    
    L->length = 0;
    L->listsize = LIST_INIT_SIZE;
    
    return OK;

}
/*
 * Function Name: InitaList
 * Parameter: SqList *L
 * Return: Status(int)
 * Use: initial the linear list
 */


Status DestroyList(SqList *L) {

    if (L->data != NULL)
        free(L->data);
    else 
        return ERROR;
    //L = NULL;
    // / = NULL;
    memset(L, 0, sizeof(SqList));

    return OK;
}
/*
 * Function Name: DestroyList
 * Parameter: SqList *L
 * Return: Status(int)
 * Use: destroy the list
 */


Status ClearList(SqList *L) {

    if (L->data == NULL)
        return ERROR;
    
    memset(L->data, 0, sizeof(int) * L->listsize);
    L->length = 0;
    L->listsize = LIST_INIT_SIZE;
    return OK;
}
/*
 * Function Name: ClearList
 * Parameter: SqList *L
 * Return: Status(int)
 * Use: clear the list (all 0)
 */


Status IsListEmpty(SqList L) {
    if (L.length == 0)
        return TRUE;
    else
        return FALSE;
}
/*
 * Function Name: IsListEmpty
 * Parameter: SqList L
 * Return: Status(int) 
 * Use: to know the list is empty or not
 */

int ListLength(SqList L) {
    return L.length;
}
/*
 * Function Name: ListLength
 * Parameter: SqList L
 * Return: length of the list(int)
 * Use: get the length of the list
 */


Status GetElem(SqList *L, int index, ElementType *e) {

    if (L->data == NULL || L->length == 0 || index <= 0 || index > L->length)
        return ERROR;

    *e = L->data[index];
    return OK;
}
/*
 * Function Name: GetElem
 * Parameter: SqList *L, int index, ElementType *e
 * Return: Status(int)
 * Use: get L->data[index] return it from *e
 */


int LocateElem(SqList *L, ElementType e) {
    int index = 0;
    for (index = 0; index < L->length; index++) 
        if (L->data[index] == e)
            break;
    
    if (index == L->length)
        return 0;
    else
        return index + 1;
    
}
/*
 * Function Name: LocateElem
 * Parameter: SqList *L, ElementType e
 * Return: the index of e or 0 if e isn't exist
 * Use: get the index of e
 */


Status PriorElem(SqList *L, ElementType cur_e, ElementType *pre_e) {
    int index = 0;
    for (index = 0; index < L->length; index++)
        if (L->data[index] == cur_e)
            break;
    
    if (index == L->length)
        return ERROR;
    else {
        if (index == 0)
            return -1;
        *pre_e = L->data[index-1];
        return index;
    }
}
/*
 * Function Name: PriorElem
 * Parameter: SqList *L, ElementType cur_e, ElementType pre_e
 * Return: Status(int)
 * Use: get the prior element of cur_e
 */


Status NextElem(SqList *L, ElementType cur_e, ElementType *next_e) {
    int index = 0;
    for (index = 0; index < L->length; index++)
        if (L->data[index] == cur_e)
            break;
    
    if (index == L->length-1)
        return ERROR;
    else {
        *next_e = L->data[index+1];
        return index;
    }
}
/*
 * Function Name: NextElem
 * Parameter: SqList *L, ElementType cur_e, ElementType *next_e
 * Return: Status(int)
 * Use: get the next element of next_e
 */


Status ListInsert(SqList *L, int index, ElementType e) {
    if (L->data == NULL || L->listsize == 0 || index <= 0 || index > L->listsize)
        return ERROR;
    
    if (L->length == L->listsize+1) {
        ElementType *new_list = (ElementType *) realloc(L->data, (L->listsize + LISTINCREMENT) * sizeof(int));
        if (new_list == NULL)
            return ERROR;
        L->data = new_list;
        L->listsize += LISTINCREMENT;
    }

    int i;

    for (i = L->listsize+1; i >= index; i--)
        L->data[i] = L->data[i-1];
    
    L->data[index-1] = e;
    L->length++;
    return OK;
}
/* 
 * Function Name: ListInsert
 * Parameter: SqList *l, int index, ElementType e
 * Return: Status(int)
 * Use: insert e in front of data[index]
 */


Status ListDelete(SqList *L, int index, ElementType *e) {

    if (L->data == NULL || L->listsize == 0 || index <= 0 || index > L->listsize)
        return ERROR;

    int i;
    *e = L->data[index-1];
    for (i = index-1; index < L->length-1; i++)
        L->data[i] = L->data[i+1];
    
    L->length--;
    return OK;

}
/* 
 * Function Name: ListDelete
 * Parameter: SqList *L, int index, ElementType *e
 * Return: Status(int)
 * Use: delete data[index] and return its value from e
 */


Status ListTraverse(SqList *L) {
    for (int i = 0; i < L->length; i++)
        printf("Index: %d, Data: %d\n", i+1, L->data[i]);

    return OK;
}
/*
 * Function Name: ListTraverse
 * Parameter: SqList *L
 * return: Status(int)
 * Use: traverse L
 */