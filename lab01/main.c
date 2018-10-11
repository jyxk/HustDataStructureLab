#include "main.h"

void PrintMenu(void) {
    /*
     * Function Name: PrintMenu
     * Parameter: None
     * Return: None
     * Use: print the menu 
     */

    printf("+-----------------------------------------------------+\n");
    printf("|                jyxk's SqList demo                   |\n");
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
    FILE *fp = fopen("SqListDataBase", "rb");
    if (fp == NULL)
        return ERROR;
    
    


}

Status SaveData(PtrToSet list_set) {
/* 
 * Function Name: SaveData
 * Parameter: PtrToSet
 * Return: Status(int)
 * Use: save data
 */

    FILE *fp = fopen("SqListDataBase", "wb");
    if (fp == NULL)
        return ERROR;
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

        int list_id, list_elem, list_index;
        SqList *L = NULL;

        switch(func_flag) {
            case 1: 
                printf("/*\n");
                printf(" * Function Name: InitaList\n");
                printf(" * Parameter: SqList *L\n");
                printf(" * Return: Status(int)\n");
                printf(" * Use: initial the linear list\n"); 
                printf(" */\n");
                printf("\n please enter the id of the list");

                scanf("%d", &list_id);
                L = list_set.head;
                while (L != NULL) {
                    if (L->ListID == list_id)
                        break;
                    L = L->next;
                }
                if (L != NULL) {
                    printf("Error, the list %d already exist.\n", list_id);
                }
                else {
                    SqList *new_list = (SqList *)malloc(sizeof(SqList));
                    if (InitaList(new_list) == OK) {
                        printf("Inital the list %d succeed.\n", list_id);
                        new_list->ListID = list_id;
                        new_list->next = list_set.head;
                        list_set.head = new_list;
                    }
                    else {
                        printf("ERROR, something wrong with the RAM");
                    }
                }
                printf("\n");
                break;

            case 2:
                printf("/*\n * Function Name: DestroyList\n * \
                Parameter: SqList *L\n * Return: Status(int)\n * Use: destroy the list\n */\n");

                printf("\n please enter the id of the list");

                scanf("%d", &list_id);
                L = list_set.head;
                if (L->ListID == list_id) {
                    list_set.head = list_set.head->next;
                    DestroyList(L);
                    printf("List %d has been removed", list_id);
                    break;
                }
                else {
                    while (L->next != NULL) {
                        L = L->next;
                        if (L->ListID == list_id);
                            break;
                    }
                }
        }
    }
}

