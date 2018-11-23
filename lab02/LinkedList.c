/**
 * @file LinkedList.c
 * @author Xiuxu Jin(jyxk) (jyxking007@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2018-11-18
 * 
 * @copyleft CopyLeft (c) 2018
 * 
 */
#include "LinkedList.h"

Status InitaList(LinkedList *L) {
/*
 * Function Name: InitaList
 * Parameter: LinkedList *L
 * Return: Status(int)
 * Use: initial the linear list
 */
    L->Length = 0;
    L->head = NULL;
    return OK;
}


Status DestroyList(LinkedList *L) {
/*
 * Function Name: DestroyList
 * Parameter: LinkedList *L
 * Return: Status(int)
 * Use: destroy the list
 */
    PtrToNode node = L->head;

    while (node != NULL) {
        PtrToNode tmp = node;
        node = node->next;
        free(tmp);
    }

    free(L);
    return OK;
}


Status ClearList(LinkedList *L) {
/*
 * Function Name: ClearList
 * Parameter: LinkedList *L
 * Return: Status(int)
 * Use: clear the list
 */
    if (L->head == NULL)
        return ERROR;

    PtrToNode node = L->head;
    while (node != NULL) {
        PtrToNode tmp = node;
        node = node->next;
        free(tmp);
    }

    L->Length = 0;
    L->head = NULL;
    return OK;
}


Status IsListEmpty(LinkedList L) {
/*
 * Function Name: IsListEmpty
 * Parameter: LinkedList L
 * Return: Status(int) 
 * Use: to know the list is empty or not
 */
    return L.Length == 0;
}

int ListLength(LinkedList L) {
/*
 * Function Name: ListLength
 * Parameter: LinkedList L
 * Return: length of the list(int)
 * Use: get the length of the list
 */
    return L.Length;
}


Status GetElem(LinkedList *L, int index, ElementType *e) {
/*
 * Function Name: GetElem
 * Parameter: LinkedList *L, int index, ElementType *e
 * Return: Status(int)
 * Use: get L->data[index] return it from *e
 */

    int node_index = 0;
    PtrToNode node = L->head;

    while (node != NULL) {
        node_index++;
        if (node_index == index) {
            *e = node->data;
            break;
        }
            node = node ->next;
    }
    if (node == NULL)
        return ERROR;
    else
        return OK;
    
}


int LocateElem(LinkedList *L, ElementType e) {
/*
 * Function Name: LocateElem
 * Parameter: LinkedList *L, ElementType e
 * Return: the index of e or 0 if e isn't exist
 * Use: get the index of e
 */
    int index = 0;
    PtrToNode node = L->head;

    while (node != NULL) {
        index++;
        if (node->data == e)
            break;
        node = node->next;
    }
    if (node != NULL)
        return index;
    else
        return 0;
}


Status PriorElem(LinkedList *L, ElementType cur_e, ElementType *pre_e) {
/*
 * Function Name: PriorElem
 * Parameter: LinkedList *L, ElementType cur_e, ElementType *pre_e
 * Return: Status(int)
 * Use: get the prior element of cur_e
 */
    PtrToNode prior_node = L->head;
    PtrToNode node = prior_node->next;
    *pre_e = INT_MAX;
    while (node != NULL) {
        if (node->data == cur_e) {
            *pre_e = prior_node->data;
            break;
        }
        prior_node = prior_node->next;
        node = node->next;
    }
    if (node != NULL)
        return OK;
    else 
        return ERROR;
}


Status NextElem(LinkedList *L, ElementType cur_e, ElementType *next_e) {
/*
 * Function Name: NextElem
 * Parameter: LinkedList *L, ElementType cur_e, ElementType *next_e
 * Return: Status(int)
 * Use: get the next element of next_e
 */
    PtrToNode node = L->head;
    PtrToNode next_node = node->next;
    *next_e = INT_MAX;
    while (next_node != NULL) {
        if (node->data == cur_e) {
            *next_e = next_node->data;
            break;
        }
        node = node->next;
        next_node = node->next;
    }
    if (next_node != NULL)
        return OK;
    else 
        return ERROR;

}

Status ListInsert(LinkedList *L, int index, ElementType e) {
/* 
 * Function Name: ListInsert
 * Parameter: LinkedList *l, int index, ElementType e
 * Return: Status(int)
 * Use: insert e in front of data[index]
 */
    PtrToNode node = L->head;
    int node_index = 0;

    if (index == 1) {
        PtrToNode new_node = (PtrToNode) malloc(sizeof(ListNode));
        new_node->data = e;
        new_node->next = L->head;
        L->head = new_node;
        L->Length++;
        return OK;
    }

    while (node != NULL) {
        node_index++;
        if (node_index == index-1) {
            PtrToNode new_node = (PtrToNode) malloc(sizeof(ListNode));
            new_node->data = e;
            new_node->next = node->next;
            node->next = new_node;
            L->Length++;
            break;
        }
        node = node->next;
    }
    if (node != NULL)
        return OK;
    else
        return ERROR;
}


Status ListDelete(LinkedList *L, int index, ElementType *e) {
/* 
 * Function Name: ListDelete
 * Parameter: LinkedList *L, int index, ElementType *e
 * Return: Status(int)
 * Use: delete data[index] and return its value from e
 */

    if (L->Length == 0 || L->head == NULL)
        return ERROR;
    int node_index = 0;
    PtrToNode node = L->head;

    if (index == 1) {
        L->head = node->next;
        free(node);
        L->Length--;
        return OK;
    }
    
    while (node != NULL) {
        node_index++;
        if (node_index == index-1) {
            PtrToNode tmp = node->next;
            *e = tmp->data;
            node->next = node->next->next;
            free(tmp);
            L->Length--;
            break;
        }
        node = node->next;
    }
    if (node != NULL) 
        return OK;
    else
        return ERROR;
}


Status ListTraverse(LinkedList *L) {
/*
 * Function Name: ListTraverse
 * Parameter: LinkedList *L
 * return: Status(int)
 * Use: traverse L
 */
    int i = 0;
    PtrToNode node = L->head;
    while (node!=NULL) {
        i++;
        printf("Index: %d, Data: %d \n", i, node->data);
        node = node->next;
    }
}