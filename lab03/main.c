#include <main.h>

/*
 * @Author: Xiuxu Jin(jyxk)
 * @Date: 2018-10-16 22:09:12
 * @LastEditors: Xiuxu Jin
 * @LastEditTime: 2018-11-18 09:37:46
 * @Description: the implement of the BinTree system
 * @Email: jyxking007@gmail.com
 */

void PrintMenu(void) {
    printf("\n+-----------------------------------------------------+\n");
    printf("|               jyxk's Binary Tree demo               |\n");
    printf("|                                                     |\n");
    printf("|                   Function List:                    |\n");
    printf("|                                                     |\n");
    printf("|      1.InitalBiTree           2.DestroyBiTree       |\n");
    printf("|      3.CreateBiTree           4.ClearBiTree         |\n");
    printf("|      5.IsBitreeEmpty          6.BiTreeDepth         |\n");
    printf("|      7.Root                   8.Value               |\n");
    printf("|      9.Assign                10.Parent              |\n");
    printf("|     11.LeftChild             12.RightChild          |\n");
    printf("|     13.LeftSibling           14.RightSibling        |\n");
    printf("|     15.InsertChild           16.DeleteChild         |\n");
    printf("|     17.PreOrderTraverse      18.InOrderTraverse     |\n");
    printf("|     19.PostOrderTraverse     20.LevelOrderTraverse  |\n");
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

/**
 * @brief load data from my super SSD LOL
 *
 * @param TreeSet
 * @return
 */
Status LoadData(PtrToSet TreeSet) {
    FILE *fp = fopen("BinaryTreeDataBase", "rb");
    if (fp == NULL)
        return ERROR;

    BinTree trees, *a_tree = &trees;
    a_tree->next = NULL;

    int size = 0xff;
    while(1) {
        BinTreeModel defination;
        PtrToTree tmp = NULL;
    }
}

Status SaveData(PtrToSet TreeSet) {

}

int main(void) {
    int function_flag = 0xff;

    while(function_flag != 0) {
        PrintMenu();
        scanf("%d", &function_flag);
        TreeSet tree_set;
        tree_set.head = NULL;
        LoadData(&tree_set);

        int tree_id, node_num, node_index, value, LorR;

        PtrToTree tree = NULL;

        switch(function_flag) {
            case 1:
                printf("/**\n * @brief Inital a binary tree\n * \n * @param T \n * @return Status \n */\n");
                printf("Now, please enter the tree id: ");
                scanf("%d", &tree_id);

                tree = tree_set.head;
                while (tree != NULL) {
                    if (tree->id == tree_id)
                        break;
                    tree = tree->next;
                }
                if (tree != NULL) {
                    printf("Initial ERROR.The tree is already exist!\n");
                }
                else {
                    BinTree new;
                    InitBiTree(&new);
                    printf("Initial tree %d succeed!\n", tree_id);
                    new.id = tree_id;
                    new.next = tree_set.head;
                    tree_set.head = &new;
                }
                printf("\n");
                break;

            case 2:
                printf("/**\n * @brief destory a binary tree\n * \n * @param T \n * @return Status \n */\n");
                printf("Now, please enter the tree id: ");
                scanf("%d", &tree_id);

                tree = tree_set.head;

                if (tree->id == tree_id) {
                    tree_set.head = tree_set.head->next;
                    DestoryBiTree(&tree_set.head);
                    printf("Succeed!Tree %d has been destoried!\n", tree_id);
                    break;
                }
                else {
                    while (tree->next != NULL) {
                        if (tree->next->id == tree_id)
                            break;
                        tree = tree->next;
                    }
                }

                if (tree == NULL) {
                    printf("Destroy error!The tree %d is not exist!");
                }
                else {
                    PtrToTree temp = tree->next;
                    tree->next = tree->next->next;
                    DestoryBiTree(temp);
                    printf("Succeed! You has destroied the tree %d", tree_id);
                }
                printf("\n");
                break;

            case 3:
                printf("/**\n * @brief Create a Bi Tree object\n * \n * @param T \n * @return Status \n */\n");
                printf("Now, please enter the tree id and tree size: ");
                scanf("%d %d", &tree_id, &node_num);

                tree = tree_set.head;

                while (tree != NULL) {
                    if (tree_id == tree->id)
                        break;
                    tree = tree->next;
                }

                if (tree != NULL) {
                    printf("Create ERROR! The Tree %d is already exist!\n");
                }
                else {

                }

                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                break;
            case 10:
                break;
            case 11:
                break;
            case 12:
                break;
            case 13:
                break;
            case 14:
                break;
            case 15:
                break;
            case 16:
                break;
            case 17:
                break;
            case 18:
                break;
            case 19:
                break;
            case 20:
                break;
            case 21:
                break;
            case 22:
                break;
            case 23:
                break;
            case 0:
                break;
            default:
                break;

        }
    }
}
