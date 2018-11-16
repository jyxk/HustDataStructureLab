#include "main.h"

void PrintMenu(void) {
    /*
     * Function Name: PrintMenu
     * Parameter: None
     * Return: None
     * Use: print the menu 
     */

    printf("\n+-----------------------------------------------------+\n");
    printf("|                jyxk's LinkedList demo               |\n");
    printf("|                                                     |\n");
    printf("|                   Function List:                    |\n");
    printf("|                                                     |\n");
    printf("|      1.InitalList             2.DestroyList         |\n");
    printf("|      3.ClearList              4.IsListEmpty         |\n");
    printf("|      5.ListLength             6.GetElem             |\n");
    printf("|      7.LocateElem             8.PriorElem           |\n");
    printf("|      9.NextElem              10.ListInsert          |\n");
    printf("|     11.ListDelete            12.ListTraverse        |\n");
    printf("|                                                     |\n");
    printf("| Enter the num of the function that you wanna see.   |\n");
    printf("| Enter 0 to exit this demo system.                   |\n");
    printf("|                                                     |\n");
    printf("|                                                     |\n");
    printf("| CopyLeft 2018 Xiuxu Jin                             |\n");
    printf("|                                    Power by:jyxk    |\n");
    printf("+-----------------------------------------------------+\n");
    printf("\n");
}

Status LoadData(PtrToSet list_set) {
/*
 * Function Name: LoadData
 * Parameter: PtrToSet 
 * Return Status(int)
 * Use: load data
 */
    FILE *fp = fopen("LinkedListDataBase", "rb");
    if (fp == NULL)
        return ERROR;

    int size = 0xffff;
    int count = 0;
    int index;
    LinkedList my_list, *L = &my_list;
    L->next = NULL;

    while (1) {
        PtrToList tmp = (PtrToList)malloc(sizeof(LinkedList));
        size = fread(tmp, sizeof(LinkedList), 1, fp);
        if (size == 0)
            break;
        ListNode my_node, *node = &my_node;
        node->next = NULL;

        for (index = 0; index < tmp->Length; index++) {
            PtrToNode tmp_node = (PtrToNode)malloc(sizeof(LinkedList));
            fread(tmp_node, sizeof(ListNode), 1, fp);
            node->next = tmp_node;
            node = node->next;
        }
        count++;
        tmp->head = my_node.next;
        L->next = tmp;
        L = L->next;
    }
    
    list_set->head = my_list.next;
    list_set->num = count;

    fclose(fp);
    return OK;
}

Status SaveData(PtrToSet list_set) {
/* 
 * Function Name: SaveData
 * Parameter: PtrToSet
 * Return: Status(int)
 * Use: save data
 */

    FILE *fp = fopen("LinkedListDataBase", "wb");
    if (fp == NULL)
        return ERROR;

    LinkedList *L = list_set->head;
    while (L != NULL) {
        fwrite(L, sizeof(LinkedList), 1, fp);
        PtrToNode node = L->head;
        for (int i = 0; i < L->Length; i++) {
            fwrite(node, sizeof(ListNode), 1, fp);
            node = node->next;
        }
        L = L->next;
    }

    fclose(fp);
    return OK;
}

int main(void) {
    //the flag variable of the state of the function
    int func_flag = -1;

    //the main loop 
    while(func_flag != 0) {

        //Init
        PrintMenu();
        scanf("%d", &func_flag);

        //Initial a list set
        ListSet list_set;
        list_set.head = NULL;
        list_set.num = 0;
        LoadData(&list_set);

        int list_id = 0, list_elem = 0, list_index = 0, elem_order = 0;
        PtrToList L = NULL;

        switch(func_flag) {
            case 1: 
                printf("/*\n");
                printf(" * Function Name: InitaList\n");
                printf(" * Parameter: LinkedList *L\n");
                printf(" * Return: Status(int)\n");
                printf(" * Use: initial the linear list\n"); 
                printf(" */\n");
                printf("\n please enter the id of the list: \n");

                scanf("%d", &list_id);
                L = list_set.head;
                while (L != NULL) {
                    if (L->ID == list_id)
                        break;
                    L = L->next;
                }
                if (L != NULL) {
                    printf("Error, the list %d already exist.\n", list_id);
                }
                else {
                    LinkedList new_list;
                    if (InitaList(&new_list) == OK) {
                        printf("Inital the list %d succeed.\n", list_id);
                        new_list.ID = list_id;
                        new_list.next = list_set.head;
                        list_set.head = &new_list;
                    }
                    else {
                        printf("ERROR, something wrong with the RAM\n");
                    }
                }
                printf("\n");
                break;

            case 2:
                printf("/*\n * Function Name: DestroyList\n * Parameter: LinkedList *L\n * Return: Status(int)\n * Use: destroy the list\n */\n");

                printf("\n please enter the id of the list: \n");

                scanf("%d", &list_id);
                L = list_set.head;
                if (L != NULL && L->ID == list_id) {
                    list_set.head = list_set.head->next;
                    DestroyList(L);
                    printf("List %d has been removed\n", list_id);
                    break;
                }
                else {
                    while (L != NULL && L->next != NULL) {
                        if (L->next->ID == list_id)
                            break;
                        L = L->next;
                    }
                }
                if (L==NULL || L->next == NULL) {
                    printf("The list is not exist\n");
                }
                else {
                    PtrToList waiting_for_delete = L->next;
                    L->next = L->next->next;
                    DestroyList(waiting_for_delete);
                    printf("List %d has been removed\n", list_id);
                }

                printf("\n");
                break;

            case 3:
                printf("/*\n * Function Name: ClearList\n * Parameter: LinkedList *L\n * Return: Status(int)\n * Use: clear the list\n */\n");
                printf("Then, enter the list id: ");
                
                scanf("%d", &list_id);

                L = list_set.head;
                while (L != NULL) {
                    if (L->ID == list_id) 
                        break;
                    L = L->next;
                }
                if (L == NULL) {
                    printf("ERROR List is not exist.\n");
                }
                else {
                    if (ClearList(L) == OK) {
                        printf("List %d has been cleared!\n", list_id);
                    }
                    else {
                        printf("Clear error, something wrong\n");
                    }
                }

                printf("\n");
                break;

            case 4:
                printf("/*\n * Function Name: IsListEmpty\n * Parameter: LinkedList L\n * Return: Status(int) \n * Use: to know the list is empty or not\n */\n");

                printf("Then, enter the list id: ");
                
                scanf("%d", &list_id);

                L = list_set.head;
                while (L != NULL) {
                    if (L->ID == list_id) 
                        break;
                    L = L->next;
                }
                if (L == NULL) {
                    printf("ERROR List is not exist.\n");
                }
                else {
                    if (IsListEmpty(*L) == TRUE) {
                        printf("List %d is empty!\n", list_id);
                    }
                    else {
                        printf("List %d is not empty!\n", list_id);
                    }
                }

                printf("\n");
                break;

            case 5:
                printf("/*\n * Function Name: ListLength\n * Parameter: LinkedList L\n * Return: length of the list(int)\n * Use: get the length of the list\n */\n");

                printf("Then, enter the list id: ");
                
                scanf("%d", &list_id);

                L = list_set.head;
                while (L != NULL) {
                    if (L->ID == list_id) 
                        break;
                    L = L->next;
                }
                if (L == NULL) {
                    printf("ERROR List is not exist.\n");
                }
                else {
                    printf("The length of the list %d is %d.\n", list_id, ListLength(*L));
                }

                printf("\n");
                break;

            case 6:
                printf("/*\n * Function Name: GetElem\n * Parameter: LinkedList *L, int index, ElementType *e\n * Return: Status(int)\n * Use: get L->data[index] return it from *e\n */\n");

                printf("Then, enter the list id and the index: ");
                
                scanf("%d %d", &list_id, &elem_order);

                L = list_set.head;
                while (L != NULL) {
                    if (L->ID == list_id) 
                        break;
                    L = L->next;
                }
                if (L == NULL) {
                    printf("ERROR List is not exist.\n");
                }
                else {
                    if (GetElem(L, elem_order, &list_elem) == OK) {
                        printf("The element is %d.\n", list_elem);
                    }
                    else {
                        printf("Index crosses the border!\n");
                    }
                }

                printf("\n");
                break;

            case 7:
                printf("/*\n * Function Name: LocateElem\n * Parameter: LinkedList *L, ElementType e\n * Return: the index of e or 0 if e isn't exist\n * Use: get the index of e\n */\n");

                printf("Then, enter the list id and the element value: ");
                
                scanf("%d %d", &list_id, &list_elem);

                L = list_set.head;
                while (L != NULL) {
                    if (L->ID == list_id) 
                        break;
                    L = L->next;
                }
                if (L == NULL) {
                    printf("ERROR List is not exist.\n");
                }
                else {
                    list_index = LocateElem(L, list_elem);
                    if (list_index == 0)
                        printf("The %d is not in the list %d", list_elem, L->ID);
                    else
                        printf("The index of the %d is %d.", list_elem, list_index);
                }

                printf("\n");
                break;

            case 8:
                printf("/*\n * Function Name: PriorElem\n * Parameter: LinkedList *L, ElementType cur_e, ElementType *pre_e\n * Return: Status(int)\n * Use: get the prior element of cur_e\n */\n");

                printf("Then, enter the list id and the element value");
                
                scanf("%d %d", &list_id, &list_elem);

                L = list_set.head;
                while (L != NULL) {
                    if (L->ID == list_id) 
                        break;
                    L = L->next;
                }
                if (L == NULL) {
                    printf("ERROR List is not exist.\n");
                }
                else {
                    int elem_pre;
                    if (PriorElem(L, list_elem, &elem_pre) == OK) {
                        printf("The piror element of %d is %d.\n", list_elem, elem_pre);
                    }
                    else {
                        if (elem_pre != INT_MAX)
                            printf("ERROR piror is not exist~\n");
                        else
                            printf("The element %d is not in the list %d", list_elem, L->ID);

                    }
                }

                printf("\n");
                break;

            case 9:
                printf("/*\n * Function Name: NextElem\n * Parameter: LinkedList *L, ElementType cur_e, ElementType *next_e\n * Return: Status(int)\n * Use: get the next element of next_e\n */\n");

                printf("Then, enter the list id and the element value: \n");
                
                scanf("%d %d", &list_id, &list_elem);

                L = list_set.head;
                while (L != NULL) {
                    if (L->ID == list_id) 
                        break;
                    L = L->next;
                }
                if (L == NULL) {
                    printf("ERROR List is not exist.\n");
                }
                else {
                    int elem_next;
                    if (NextElem(L, list_elem, &elem_next) == OK) {
                        printf("The next element of %d is %d.\n", list_elem, elem_next);
                    }
                    else {
                        if (elem_next != INT_MAX)
                            printf("ERROR next is not exist~\n");
                        else
                            printf("The element %d is not in the list %d", list_elem, L->ID);
                    }
                }

                printf("\n");
                break;

            case 10:
                printf("/* \n * Function Name: ListInsert\n * Parameter: LinkedList *l, int index, ElementType e\n * Return: Status(int)\n * Use: insert e in front of data[index]\n */\n");

                printf("Then, enter the list id, index and the element value: ");
                
                scanf("%d %d %d", &list_id, &elem_order, &list_elem);

                L = list_set.head;
                while (L != NULL) {
                    if (L->ID == list_id) 
                        break;
                    L = L->next;
                }
                if (L == NULL) {
                    printf("ERROR List is not exist.\n");
                }
                else {
                    if (ListInsert(L, elem_order, list_elem) == OK)
                        printf("Insert succeed!\n");
                    else
                        printf("ERROR~\n");
                }

                printf("\n");
                break;

            case 11:
                printf("/* \n * Function Name: ListDelete\n * Parameter: LinkedList *L, int index, ElementType *e\n * Return: Status(int)\n * Use: delete data[index] and return its value from e\n */\n");

                printf("Then, enter the list id and index: ");
                
                scanf("%d %d", &list_id, &elem_order);

                L = list_set.head;
                while (L != NULL) {
                    if (L->ID == list_id) 
                        break;
                    L = L->next;
                }
                if (L == NULL) {
                    printf("ERROR List is not exist.\n");
                }
                else if (elem_order > L->Length || elem_order <= 0) {
                    printf("Index crosses the border!\n");
                }
                else {
                    if (ListDelete(L, elem_order, &list_elem) == OK)
                        printf("Delete %d succeed!\n", list_elem);
                    else 
                        printf("Delete failed~\n");
                }

                printf("\n");
                break;

            case 12:
                printf("/*\n * Function Name: ListTraverse\n * Parameter: LinkedList *L\n * Return: Status(int)\n * Use: traverse L\n */\n");

                printf("Then, enter the list id: ");
                
                scanf("%d", &list_id);

                L = list_set.head;
                while (L != NULL) {
                    if (L->ID == list_id) 
                        break;
                    L = L->next;
                }
                if (L == NULL) {
                    printf("ERROR List is not exist.\n");
                }
                else if(L->Length == 0) {
                    printf("The linked list %d is void!\n", L->ID);
                }
                else {
                    printf("The elements in linked list %d are:\n", list_id);
                    ListTraverse(L);
                }

                printf("\n");
                break;

            case 0:
                printf("Thank you for using~\n");
                break;
            
            default:
                printf("Baka, you entered the wrong num.\n");
                break;

        }

        SaveData(&list_set);
    }
    return 0;
}

