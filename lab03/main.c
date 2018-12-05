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
    printf("|     11.getChild              12.LeftSibling         |\n");
    printf("|     13.RightSibling          14.InsertChild         |\n");
    printf("|     15.DeleteChild           16.PreOrderTraverse    |\n");
    printf("|     17.InOrderTraverse       18.PostOrderTraverse   |\n");
    printf("|     19.LevelOrderTraverse    20.ShowTreeList        |\n");
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
void LoadData(PtrToSet TreeSet) {
    FILE *fp = fopen("BinaryTreeDataBase", "rb");
    if (fp == NULL)
        return ;

    BinTree trees, *a_tree = &trees;
    a_tree->next = NULL;

    int size = 0xff;
    while(1) {
        BinTreeModel definition;
        PtrToTree tmp = NULL;
        size = fread(&definition, sizeof(BinTreeModel), 1, fp);
        if (size == 0)
            break;

        tmp = (BinTree *)malloc(sizeof(BinTree));
        InitBiTree(tmp);

        if (definition.size != 0) {
            definition.pre_index = (int *)malloc(sizeof(int) * definition.size);
            definition.pre_definition = (int *)malloc(sizeof(int) * definition.size);
            definition.in_index = (int *)malloc(sizeof(int) * definition.size);
            definition.in_definition = (int *)malloc(sizeof(int) * definition.size);
            fread(definition.pre_index, sizeof(int) * definition.size, 1, fp);
            fread(definition.pre_definition, sizeof(int) * definition.size, 1, fp);
            fread(definition.in_index, sizeof(int) * definition.size, 1, fp);
            fread(definition.in_definition, sizeof(int) * definition.size, 1, fp);
            CreateBiTree(tmp, definition.pre_index, definition.pre_definition, definition.in_index, definition.in_definition, definition.size);
        }

        tmp->id = definition.id;
        tmp->next = NULL;
        a_tree->next = tmp;
        a_tree = a_tree->next;
    }

    TreeSet->head = trees.next;

    fclose(fp);
}


/**
 *
 * @param node
 * @param order
 * @param indexs
 * @param definition
 * @param pos
 */
void Traverse(PtrToNode node, int order, int *indexs, int *definition, int *pos) {
    if (node == NULL)
        return;
    if (pos == NULL) {
        int new_pos = 0;
        Traverse(node, order, indexs, definition, &new_pos);
        return;
    }
    if (order == PRE_ORDER) {
        indexs[*pos] = node->index;
        definition[*pos] = node->data;
        (*pos)++;
        Traverse(node->left_child, order, indexs, definition, pos);
        Traverse(node->right_child, order, indexs, definition, pos);
    }
    else if (order == IN_ORDER) {
        Traverse(node->left_child, order, indexs, definition, pos);
        indexs[*pos] = node->index;
        definition[*pos] = node->data;
        (*pos)++;
        Traverse(node->right_child, order, indexs, definition, pos);
    }
}

void SaveData(PtrToSet TreeSet) {
    FILE *fp = fopen("BinaryTreeDataBase", "wb");
    if (fp == NULL)
        return;

    PtrToTree a_tree = TreeSet->head;
    while (a_tree != NULL) {
        BinTreeModel definition;
        definition.id = a_tree->id;
        definition.size = a_tree->size;
        definition.pre_index = (int *)malloc(sizeof(int) * definition.size);
        definition.pre_definition = (int *)malloc(sizeof(int) * definition.size);
        definition.in_index = (int *)malloc(sizeof(int) * definition.size);
        definition.in_definition = (int *)malloc(sizeof(int) * definition.size);
        Traverse(a_tree->root, PRE_ORDER, definition.pre_index, definition.pre_definition, NULL);
        Traverse(a_tree->root, IN_ORDER, definition.in_index, definition.in_definition, NULL);
        fwrite(&definition, sizeof(BinTreeModel), 1, fp);
        fwrite(definition.pre_index, sizeof(int) * definition.size, 1 ,fp);
        fwrite(definition.pre_definition, sizeof(int) * definition.size, 1, fp);
        fwrite(definition.in_index, sizeof(int) * definition.size, 1, fp);
        fwrite(definition.in_definition, sizeof(int) * definition.size, 1, fp);
        a_tree = a_tree->next;
    }

    fclose(fp);
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

                if (tree_set.head == NULL) {
                    printf("There is no tree to destroy!\n");
                    break;
                }
                tree = tree_set.head;

                if (tree->id == tree_id) {
                    tree_set.head = tree_set.head->next;

                    DestoryBiTree(tree);
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
                    printf("Destroy error!The tree %d is not exist!", tree_id);
                }
                else {
                    PtrToTree temp = tree->next;
                    tree->next = tree->next->next;
                    DestoryBiTree(temp);
                    printf("Succeed! You has destroyed the tree %d", tree_id);
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
                    printf("Create ERROR! The Tree %d is already exist!\n", tree_id);
                }
                else {
                    int *pre_index = (int *)malloc(sizeof(int)*node_num);
                    int *pre_definition = (int *)malloc(sizeof(int)*node_num);
                    int *in_index = (int *)malloc(sizeof(int)*node_num);
                    int *in_definition = (int *)malloc(sizeof(int)*node_num);

                    printf("Please input the pre order of the tree:(index value)\n");
                    for (int i = 0; i < node_num; i++)
                        scanf("%d%d", &pre_index[i], &pre_definition[i]);
                    printf("Please input the in order of the tree:(index value)\n");
                    for (int i = 0; i < node_num; i++)
                        scanf("%d%d", &in_index[i], &in_definition[i]);
                    BinTree new;
                    CreateBiTree(&new, pre_index, pre_definition, in_index, in_definition, node_num);
                    printf("Create the tree %d succeed!\n", tree_id);
                    new.id = tree_id;
                    new.next = tree_set.head;
                    tree_set.head = &new;
                }
                printf("\n");
                break;

            case 4:
                printf("/**\n * @brief Clear the binary tree T\n * \n * @param T \n * @return Status \n */\n");
                printf("Now please input the tree id: ");
                scanf("%d", &tree_id);
                tree = tree_set.head;
                while (tree != NULL) {
                    if (tree_id == tree->id)
                        break;
                    tree = tree->next;
                }

                if (tree == NULL) {
                    printf("Clear ERROR! The Tree %d is not exist!\n", tree_id);
                }
                else {
                    if (ClearBiTree(tree) == OK)
                        printf("The tree %d has been cleared!\n", tree_id);
                    else
                        printf("ERROR! The tree %d is already empty!\n", tree_id);
                }

                break;
            case 5:
                printf("/**\n * @brief Is the binary tree T empty?\n * \n * @param T \n * @return BOOL \n */\n");
                printf("Now please input the tree id: ");
                scanf("%d", &tree_id);
                tree = tree_set.head;
                while (tree != NULL) {
                    if (tree_id == tree->id)
                        break;
                    tree = tree->next;
                }

                if (tree == NULL) {
                    printf("ERROR! The Tree %d is not exist!\n\n", tree_id);
                }
                else {
                    if (IsBiTreeEmpty(tree))
                        printf("The tree %d is empty!\n\n", tree_id);
                    else
                        printf("The tree %d is not empty!\n\n", tree_id);
                }
                break;

            case 6:
                printf("/**\n * @brief get the binary tree's depth\n * \n * @param T \n * @return Status \n */\n");
                printf("Now please input the tree id: ");
                scanf("%d", &tree_id);
                tree = tree_set.head;
                while (tree != NULL) {
                    if (tree_id == tree->id)
                        break;
                    tree = tree->next;
                }

                if (tree == NULL) {
                    printf("ERROR! The Tree %d is not exist!\n\n", tree_id);
                }
                else {
                    printf("The depth of the tree %d is %d", tree_id, BiTreeDepth(tree));
                }
                break;

            case 7:
                printf("/**\n * @brief get the root of T and return it \n * \n * @param T \n * @return PtrToNode \n */\n");
                printf("Now please input the tree id: ");
                scanf("%d", &tree_id);
                tree = tree_set.head;
                while (tree != NULL) {
                    if (tree_id == tree->id)
                        break;
                    tree = tree->next;
                }

                if (tree == NULL) {
                    printf("ERROR! The Tree %d is not exist!\n\n", tree_id);
                }
                else {
                    PtrToNode root = Root(tree);
                    if (root == NULL) {
                        printf("ERROR, the tree %d is empty", tree_id);
                    }
                    else {
                        printf("The root of the tree %d:\n", tree_id);
                        printf("index: %d, value: %d", root->index, root->data);
                    }
                }

                break;

            case 8:
                printf("/**\n * @brief get the {index} node in T\n * \n * @param T \n * @param index \n * @return Status \n */\n");
                printf("Now please input the tree id and node index: ");
                scanf("%d%d", &tree_id, &node_index);
                tree = tree_set.head;
                while (tree != NULL) {
                    if (tree_id == tree->id)
                        break;
                    tree = tree->next;
                }

                if (tree == NULL) {
                    printf("ERROR! The Tree %d is not exist!\n\n", tree_id);
                }
                else {
                    int value = Value(tree, node_index);
                    if (value == NOT_EXIST)
                        printf("The tree is empty!\n");
                    else if (value == NOT_FOUND)
                        printf("The node %d is not exist!", node_index);
                    else {
                        printf("The value of the node %d is %d!\n", node_index, value);
                    }
                }
                break;

            case 9:
                printf("/**\n * @brief assign the index node in T with value\n * \n * @param T \n * @param index \n * @param value \n * @return Status \n */\n");
                printf("Now please input the tree id , the index and the value!\n");
                scanf("%d%d%d", &tree_id, &node_index, &value);
                tree = tree_set.head;
                while (tree != NULL) {
                    if (tree_id == tree->id)
                        break;
                    tree = tree->next;
                }

                if (tree == NULL) {
                    printf("ERROR! The tree %d is not exist!\n\n", tree_id);
                }
                else {
                    if (Assign(tree, node_index, value) == OK)
                        printf("Assign the node %d succeed!\n", node_index);
                    else
                        printf("Error!The node %d is not exist!\n", node_index);
                }
                break;

            case 10:
                printf("/**\n * @brief get parent node of index in T\n * \n * @param T \n * @param index \n * @return PtrToNode \n */\n");
                printf("Now please input the tree id and the index!\n");
                scanf("%d%d", &tree_id, &node_index);
                tree = tree_set.head;
                while (tree != NULL) {
                    if (tree_id == tree->id)
                        break;
                    tree = tree->next;
                }

                if (tree == NULL) {
                    printf("ERROR! The tree %d is not exist!\n\n", tree_id);
                }
                else {
                    PtrToNode parent = Parent(tree, node_index);
                    if (parent == NULL)
                        printf("The parent is not found!Maybe you input a root node?\n");
                    else {
                        printf("The parent of node %d is :\n", node_index);
                        printf("Index:%d, Value:%d\n", parent->index, parent->data);
                    }
                }
                break;

            case 11:
                printf("/**\n * @brief Get the Child object\n * \n * @param node \n * @param index \n * @param LorR \n * @return PtrToNode \n */\n");
                printf("Now please input the tree id , the index and the child(0 for left and 1 for right)!\n");
                scanf("%d%d%d", &tree_id, &node_index, &LorR);
                tree = tree_set.head;
                while (tree != NULL) {
                    if (tree_id == tree->id)
                        break;
                    tree = tree->next;
                }

                if (tree == NULL) {
                    printf("ERROR! The tree %d is not exist!\n\n", tree_id);
                }
                else {
                    if (LorR == LEFT) {
                        PtrToNode left_child = LeftChild(tree, node_index);
                        if (left_child == NULL)
                            printf("The left child is not exist!\n");
                        else {
                            printf("The left child of node %d\n", node_index);
                            printf("Key: %d\n", left_child->index);
                            printf("Value: %d\n", left_child->data);
                        }
                    }
                    else {
                        PtrToNode right_child = RightChild(tree, node_index);
                        if (right_child == NULL)
                            printf("The right child is not exist!\n");
                        else {
                            printf("The right child of node %d\n", node_index);
                            printf("Key: %d\n", right_child->index);
                            printf("Value: %d\n", right_child->data);
                        }
                    }
                }
                break;

            case 12:
                printf("/**\n * @brief get the left sibing of index in T\n * \n * @param T \n * @param index \n * @return PtrToNode \n */\n");
                printf("Now please input the tree id and the index!\n");
                scanf("%d%d", &tree_id, &node_index);
                tree = tree_set.head;
                while (tree != NULL) {
                    if (tree_id == tree->id)
                        break;
                    tree = tree->next;
                }

                if (tree == NULL) {
                    printf("ERROR! The tree %d is not exist!\n\n", tree_id);
                }
                else {
                    PtrToNode left_sibling = LeftSibling(tree, node_index);
                    if (left_sibling == NULL) {
                        printf("Error, the left sibling not found!\n");
                    }
                    else {
                        printf("The left sibling of node %d\n", node_index);
                        printf("Index: %d\n", left_sibling->index);
                        printf("Value: %d\n", left_sibling->data);
                    }
                }

                printf("\n");
                break;

            case 13:
                printf("/**\n * @brief get the right sibing of index in T\n * \n * @param T \n * @param index \n * @return PtrToNode \n */\n");
                printf("Now please input the tree id and the index!\n");
                scanf("%d%d", &tree_id, &node_index);
                tree = tree_set.head;
                while (tree != NULL) {
                    if (tree_id == tree->id)
                        break;
                    tree = tree->next;
                }

                if (tree == NULL) {
                    printf("ERROR! The tree %d is not exist!\n\n", tree_id);
                }
                else {
                    PtrToNode right_sibling = RightSibling(tree, node_index);
                    if (right_sibling == NULL) {
                        printf("Error, the right sibling not found!\n");
                    }
                    else {
                        printf("The left sibling of node %d\n", node_index);
                        printf("Index: %d\n", right_sibling->index);
                        printf("Value: %d\n", right_sibling->data);
                    }
                }

                printf("\n");
                break;

            case 14:
                printf("/**\n * @brief insert LorR child to p\n * \n * @param T \n * @param p \n * @param LorR \n * @return Status \n */\n");
                printf("Now please input the tree id , the index , LorR and the child tree id\n");

                int child_id;
                scanf("%d%d%d%d", &tree_id, &node_index, &LorR, &child_id);
                tree = tree_set.head;
                while (tree != NULL) {
                    if (tree_id == tree->id)
                        break;
                    tree = tree->next;
                }

                if (tree == NULL) {
                    printf("ERROR! The tree %d is not exist!\n\n", tree_id);
                    break;
                }

                PtrToTree C = tree_set.head;

                if (C->id == child_id) {
                    if (InsertChild(tree, node_index, LorR, C) == OK) {
                        printf("Insert child tree %d succeed!\n", child_id);
                        tree_set.head = tree_set.head->next;
                        free(C);
                    }
                    else {
                        printf("Insert error, please check your input!\n");
                    }
                    printf("\n");
                    break;
                }
                if (InsertChild(tree, node_index, LorR, C->next) == OK) {
                    printf("Insert child tree %d succeed!\n", child_id);
                    PtrToTree tmp = C->next;
                    C->next = C->next->next;
                    free(tmp);
                }
                else {
                    printf("Insert error, please check yout input!\n");
                }
                printf("\n");

                break;

            case 15:
                printf("/**\n * @brief delete LorR child of p\n * \n * @param T \n * @param p \n * @param LorR \n * @return Status \n */\n");
                printf("Now please input the tree id , the index and LorR:\n");

                scanf("%d%d%d", &tree_id, &node_index, &LorR);
                tree = tree_set.head;
                while (tree != NULL) {
                    if (tree_id == tree->id)
                        break;
                    tree = tree->next;
                }

                if (tree == NULL) {
                    printf("ERROR! The tree %d is not exist!\n\n", tree_id);
                    break;
                }
                else {
                    if (DeleteChild(tree, node_index, LorR) == OK) {
                        printf("Delete child tree succeed!\n");
                    }
                    else {
                        printf("Delete error, please check your input!\n");
                    }
                }
                break;

            case 16:
                printf("/**\n * @brief Traverse the binary tree T by preorder\n * \n * @param T \n * @return Status \n */\n");
                printf("Now please input the tree id: ");
                scanf("%d", &tree_id);
                tree = tree_set.head;
                while (tree != NULL) {
                    if (tree_id == tree->id)
                        break;
                    tree = tree->next;
                }

                if (tree == NULL) {
                    printf("ERROR! The Tree %d is not exist!\n\n", tree_id);
                }
                else {
                    if (PreOrderTraverseNoRec(tree) == ERROR) {
                        printf("Error, this binary tree is empty!\n");
                    }
                }
                break;

            case 17:
                printf("/**\n * @brief Traverse the binary tree T by inorder\n * \n * @param T \n * @return Status \n */\n");
                printf("Now please input the tree id: ");
                scanf("%d", &tree_id);
                tree = tree_set.head;
                while (tree != NULL) {
                    if (tree_id == tree->id)
                        break;
                    tree = tree->next;
                }

                if (tree == NULL) {
                    printf("ERROR! The Tree %d is not exist!\n\n", tree_id);
                }
                else {
                    if (InOrderTraverse(tree) == ERROR) {
                        printf("ERROR, this binary is empty!\n");
                    }
                }
                break;

            case 18:
                printf("/**\n * @brief Traverse the binary tree T by postorder\n * \n * @param T \n * @return Status \n */\n");
                printf("Now please input the tree id: ");
                scanf("%d", &tree_id);
                tree = tree_set.head;
                while (tree != NULL) {
                    if (tree_id == tree->id)
                        break;
                    tree = tree->next;
                }

                if (tree == NULL) {
                    printf("ERROR! The Tree %d is not exist!\n\n", tree_id);
                }
                else {
                    if (PostOrderTraverse(tree) == ERROR) {
                        printf("ERROR, this binary is empty!\n");
                    }
                }
                break;

            case 19:
                printf("/**\n * @brief Traverse the binary tree T by level\n *\n * @param T\n * @return Status\n */\n");
                printf("Now please input the tree id: ");
                scanf("%d", &tree_id);
                tree = tree_set.head;
                while (tree != NULL) {
                    if (tree_id == tree->id)
                        break;
                    tree = tree->next;
                }

                if (tree == NULL) {
                    printf("ERROR! The Tree %d is not exist!\n\n", tree_id);
                }
                else {
                    if (LevelOrderTraverse(tree) == ERROR) {
                        printf("Error, this tree is empty!\n");
                    }
                }
                break;

            case 20:
                tree = tree_set.head;
                while (tree != NULL) {
                    printf("Id: %d\n", tree->id);
                    tree = tree->next;
                }
                printf("\n");
                break;

            case 0:
                printf("Thanks for using!\n");
                break;

            default:
                printf("You entered the wrong num.!\n");
                break;

        }
        SaveData(&tree_set);
    }
    return 0;
}
