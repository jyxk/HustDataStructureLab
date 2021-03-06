/*
 * @Author: Xiuxu Jin(jyxk)
 * @Date: 2018-10-24 07:48:14
 * @LastEditors: Xiuxu Jin
 * @LastEditTime: 2018-11-08 18:50:23
 * @Description: the implement of binary tree ADT
 */

#include "BinTree.h"
#include "queue.h"

static void FreeAllNode(PtrToNode node);
static int GetDepth(PtrToNode node, int depth);

/**
 * @brief 
 * 
 * @param array 
 * @param size 
 * @param target 
 * @return int 
 */
int search_array(const int * array, int size, int target) {
    int i;
    for (i = 0; i < size; i++) {
        if (array[i] == target)
            return i;
    }
    return -1;
}


/**
 * @brief free child node and its sons
 * 
 * @param node 
 */
void free_child(PtrToNode node) {
    if (node == NULL)
        return;
    if (node->left_child != NULL)
        free_child(node->left_child);
    if (node->right_child != NULL)
        free_child(node->right_child);

    free(node);
}

/**
 * @brief Inital a binary tree
 * 
 * @param T 
 * @return Status 
 */
Status InitBiTree(PtrToTree T) {
    T->size = 0;
    T->root = NULL;
    T->insert_node = NOT_EXIST;
    return OK;
}

/**
 * @brief destory a binary tree
 * 
 * @param T 
 * @return Status 
 */
Status DestoryBiTree(PtrToTree T) {
    if (T != NULL)
        FreeAllNode(T->root);
    return OK;
}

/**
 * @brief free all node in the binary tree
 *        designed for DestroyBiTree
 * 
 * @param node 
 */
static void FreeAllNode(PtrToNode node) {
    if (node == NULL)
        return;
    if (node->left_child != NULL)
        FreeAllNode(node->left_child);
    if (node->right_child != NULL)
        FreeAllNode(node->right_child);
    free(node);
}

PtrToNode create_tree(int *ind1, int *def1, int *ind2, int *def2,
                        int max_pos, int min_pos, int *pos) {
    if (pos == NULL) {
        int new_pos = 0;
        return create_tree(ind1, def1, ind2, def2, max_pos, min_pos, &new_pos);
    }

    int root_pos = search_array(def2 + min_pos, max_pos - min_pos, def1[*pos]);
    if (root_pos == -1)
        return NULL;
    else
        root_pos += min_pos;

    PtrToNode root = (PtrToNode)malloc(sizeof(TreeNode));
    root->index = ind1[*pos];
    root->data = def1[*pos];
    (*pos)++;

    root->left_child = create_tree(ind1,def1, ind2, def2, root_pos, min_pos, pos);
    root->right_child = create_tree(ind1, def1, ind2, def2, max_pos, root_pos+1, pos);
    return root;
}

/**
 * @brief Create a Binary Tree object
 * 
 * @param T 
 * @return Status 
 */
Status CreateBiTree(PtrToTree T, int *pre_index, int *pre_defination,
                    int *in_index, int *in_defination, int defination_len) {
    if (defination_len <= 0)
        return ERROR;
    T->size = defination_len;
    T->root = create_tree(pre_index, pre_defination, in_index, in_defination, defination_len, 0, NULL);
    return OK;
    
}

/**
 * @brief Clear the binary tree T
 * 
 * @param T 
 * @return Status 
 */
Status ClearBiTree(PtrToTree T) {
    T->size = 0;
    FreeAllNode(T->root);
    T->root = NULL;
    return OK;
}

/**
 * @brief Is the binary tree T empty?
 * 
 * @param T 
 * @return BOOL 
 */
BOOL IsBiTreeEmpty(PtrToTree T) {
    return T->size == 0;
}

/**
 * @brief get the binary tree's depth
 * 
 * @param T 
 * @return Status 
 */
int BiTreeDepth(PtrToTree T) {
   return GetDepth(T->root, 0); 
}

/**
 * @brief Get the Depth of the tree
 * 
 * @param node 
 * @param depth 
 * @return int 
 */
static int GetDepth(PtrToNode node, int depth) {
    if (node == NULL)
        return depth;
    int left_sub_depth = GetDepth(node->left_child, depth+1);
    int right_sub_depth = GetDepth(node->right_child, depth+1);

    return (left_sub_depth > right_sub_depth) ? left_sub_depth:right_sub_depth;
}

/**
 * @brief get the root of T and return it 
 * 
 * @param T 
 * @return PtrToNode 
 */
PtrToNode Root(PtrToTree T) {
    return T->root;
}

/**
 * @brief get the value of index
 * 
 * @param node 
 * @param index 
 * @return int 
 */
int getValue(PtrToNode node, int index) {
    if (node == NULL)
        return NOT_FOUND;
    if (node->index == index)
        return node->data;
    else {
        int left = getValue(node->left_child, index);
        int right = getValue(node->right_child, index);
        if (left == NOT_FOUND && right == NOT_FOUND)
            return NOT_FOUND;
        else if (left != NOT_FOUND)
            return left;
        else
            return right;
    }
}

/**
 * @brief get the {index} node in T
 * 
 * @param T 
 * @param index 
 * @return Status 
 */
Status Value(PtrToTree T, int index) {
    if (T->root == NULL)
        return NOT_EXIST;
    return getValue(T->root, index);
}
 
 /**
  * @brief Set the Assign object
  * 
  * @param node 
  * @param index 
  * @param value 
  */
void setAssign(PtrToNode node, int index, int value, int *flag) {
    if (node == NULL)
        return ;
    if (node->index == index) {
        node->data = value;
        *flag = 1;
    }
    else {
        setAssign(node->left_child, index, value, flag);
        setAssign(node->right_child, index, value, flag);
    }
}

/**
 * @brief assign the index node in T with value
 * 
 * @param T 
 * @param index 
 * @param value 
 * @return Status 
 */
Status Assign(PtrToTree T, int index, int value) {
    int flag = 0;
    setAssign(T->root, index, value, &flag);
    if (flag == 1)
        return OK;
    else
        return ERROR;
}


PtrToNode findParent(PtrToNode node, int index) {
    if (node == NULL)
        return NULL;
    if ((node->left_child != NULL && node->left_child->index == index) || 
        (node->right_child != NULL && node->right_child->index == index))
        return node;
    PtrToNode parent = findParent(node->left_child, index);
    if (parent == NULL)
        parent = findParent(node->right_child, index);
    return parent;
}

/**
 * @brief get parent node of index in T
 * 
 * @param T 
 * @param index 
 * @return PtrToNode 
 */
PtrToNode Parent(PtrToTree T, int index) {
    return findParent(T->root, index);
}

/**
 * @brief Get the Child object
 * 
 * @param node 
 * @param index 
 * @param LorR 
 * @return PtrToNode 
 */
PtrToNode getChild(PtrToNode node, int index, int LorR) {
    if (node == NULL)
        return node;
    if (node->index == index) {
        if (LorR == LEFT)
            return node->left_child;
        else    
            return node->right_child;
    }
    PtrToNode child = getChild(node->left_child, index, LorR);
    if (child == NULL)
        child = getChild(node->right_child, index, LorR);
    return child;
}

/**
 * @brief get the left child of index
 * 
 * @param T 
 * @param index 
 * @return PtrToNode 
 */
PtrToNode LeftChild(PtrToTree T, int index) {
    return getChild(T->root, index, LEFT);
}

/**
 * @brief get the right child of index
 * 
 * @param T 
 * @param index 
 * @return PtrToNode 
 */
PtrToNode RightChild(PtrToTree T, int index) {
    return getChild(T->root, index, RIGHT);
}

/**
 * @brief get the left sibing of index in T
 * 
 * @param T 
 * @param index 
 * @return PtrToNode 
 */
PtrToNode LeftSibling(PtrToTree T, int index) {
    if (Root(T)->index == index)
        return NULL;
    PtrToNode parent = Parent(T, index);
    if (parent == NULL || parent->left_child->index == index)
        return NULL;
    else
        return parent->left_child;
}

/**
 * @brief get the right sibing of index in T
 * 
 * @param T 
 * @param index 
 * @return PtrToNode 
 */
PtrToNode RightSibling(PtrToTree T, int index) {
    if (Root(T)->index == index)
        return NULL;
    PtrToNode parent = Parent(T, index);
    if (parent == NULL || parent->right_child->index == index)
        return NULL;
    else    
        return parent->right_child;
}

/**
 * @brief assist function to insert a child tree
 * 
 * @param node 
 * @param index 
 * @param LorR 
 * @param sub_tree 
 * @return PtrToNode 
 */
PtrToNode TreeInsertChild(PtrToNode node, int index, int LorR, PtrToNode sub_tree) {
    if (node == NULL)
        return NULL;
    if (node->index == index) {
        PtrToNode tmp_node;
        if (LorR == LEFT) {
            tmp_node = node->left_child;
            node->left_child = sub_tree;
        }
        else {
            tmp_node = node->right_child;
            node->right_child = sub_tree;
        }
        sub_tree->right_child = tmp_node;
    }

    node->left_child = TreeInsertChild(node->left_child, index, LorR, sub_tree);
    node->right_child = TreeInsertChild(node->right_child, index, LorR, sub_tree);
    return node;
}

/**
 * @brief insert LorR child to p
 * 
 * @param T 
 * @param p 
 * @param LorR 
 * @return Status 
 */
Status InsertChild(PtrToTree T, int index, int LorR, PtrToTree C) {
    if (T->root == NULL || C->root == NULL || C->root->right_child != NULL)
        return ERROR;
    T->size += C->size;
    T->root = TreeInsertChild(T->root, index, LorR, C->root);
    return OK;
}

Status NewInsertChild(PtrToTree T, PtrToNode target, int LorR, PtrToTree C) {
    return InsertChild(T, target->index, LorR, C);
}

PtrToNode find_node(PtrToNode node, int node_index) {

    if (node == NULL)
        return NULL;
    if (node->index == node_index)
        return node;
    PtrToNode target = find_node(node->left_child, node_index);
    if (target)
        return target;
    return find_node(node->right_child, node_index);
}

PtrToNode FindNode(PtrToTree T, int node_index) {
    return find_node(T->root, node_index);
}

/**
 * @brief assist function for search a binary tree
 * 
 * @param node 
 * @param index 
 * @return int 
 */
static int search_binary_tree(PtrToNode node, int index) {
    if (node == NULL)
        return 0;
    if (node->index == index)
        return 1;
    return search_binary_tree(node->left_child, index) | search_binary_tree(node->right_child, index);
}

/**
 * @brief assist function to count binary tree node
 * 
 * @param node 
 * @return int 
 */
int count_binary_tree(PtrToNode node) {
    if (node == NULL)
        return 0;
    return 1+ count_binary_tree(node->left_child) + count_binary_tree(node->right_child);
}

/**
 * @brief assist function to delete a child of a tree
 * 
 * @param node 
 * @param index 
 * @param LorR 
 * @return PtrToNode 
 */
PtrToNode delete_child(PtrToNode node, int index, int LorR) {
    if (node == NULL)
        return NULL;
    if (node->index == index) {
        if (LorR == LEFT) {
            free_child(node->left_child);
            node->left_child = NULL;
        }
        else {
            free_child(node->right_child);
            node->right_child = NULL;
        }
    }
    node->left_child = delete_child(node->left_child, index, LorR);
    node->right_child = delete_child(node->right_child, index, LorR);
    return node;
}

/**
 * @brief delete LorR child of p
 * 
 * @param T 
 * @param p 
 * @param LorR                     list_set.head->next = (SqList *)malloc(sizeof(SqList));
 * @return Status 
 */
Status DeleteChild(PtrToTree T, int index, int LorR) {
    if (T->root == NULL || !search_binary_tree(T->root, index))
        return ERROR;
    T->root = delete_child(T->root, index, LorR);
    T->size = count_binary_tree(T->root);
    return OK;
}

/**
 * @brief assist function for traerse a tree by different ways
 * 
 * @param node 
 * @param flag 
 */
void traverse_tree(PtrToNode node, int flag) {
    if (node == NULL)
        return ;
    if (flag == PRE_ORDER) {
        printf("Index: %d, Value: %d \n", node->index, node->data);
        traverse_tree(node->left_child, flag);
        traverse_tree(node->right_child, flag);
    }
    if (flag == POST_ORDER) {
        traverse_tree(node->left_child, flag);
        traverse_tree(node->right_child, flag);
        printf("Index: %d, Value: %d \n", node->index, node->data);
    }
    if (flag == IN_ORDER) {
        traverse_tree(node->left_child, flag);
        printf("Index: %d, Value: %d \n", node->index, node->data);
        traverse_tree(node->right_child, flag);
    }
}

/**
 * @brief Traverse the binary tree T by preorder
 * 
 * @param T 
 * @return Status 
 */
Status PreOrderTraverse(PtrToTree T) {
    if (T->root == NULL)
        return ERROR;
    printf("Pre Order Traverse tree:%d\n", T->id);
    printf("Tree size: %d \n", T->size);
    traverse_tree(T->root, PRE_ORDER);
    return OK;
}

/**
 *
 * @param T
 * @return
 */
Status PreOrderTraverseNoRec(PtrToTree T) {
    if (IsBiTreeEmpty(T))
        return ERROR;

    PtrToNode p = T->root;
    PtrToNode stack[30];
    int num = 0;
    while (p != NULL || num > 0) {
        while (p != NULL) {
            printf("Index: %d Value: %d\n", p->index, p->data);
            stack[num++] = p;
            p = p->left_child;
        }
        num--;
        p = stack[num];
        p = p->right_child;
    }
    printf("\n");
    return OK;
}

/**
 * @brief Traverse the binary tree T by inorder
 * 
 * @param T 
 * @return Status 
 */
Status InOrderTraverse(PtrToTree T) {
    if (T->root == NULL)
        return ERROR;
    printf("In Order Traverse tree:%d\n", T->id);
    printf("Tree size: %d \n", T->size);
    traverse_tree(T->root, IN_ORDER);
    return OK;
}

/**
 * @brief Traverse the binary tree T by postorder
 * 
 * @param T 
 * @return Status 
 */
Status PostOrderTraverse(PtrToTree T) {
    if (T->root == NULL)
        return ERROR;
    printf("Post Order Traverse tree:%d\n", T->id);
    printf("Tree size: %d \n", T->size);
    traverse_tree(T->root, POST_ORDER);
    return OK;
}

/**
 * @brief Traverse the binary tree T by level
 * 
 * @param T 
 * @return Status 
 */
Status LevelOrderTraverse(PtrToTree T) {
    if (T->root == NULL)
        return ERROR;
    
    Queue node_queue = CreateQueue(T->size + 5);
    PtrToNode node = NULL;
    printf("Level Order Traverse(BFS) tree:%d\n", T->id);
    printf("Tree size: %d \n", T->size);

    Enqueue(T->root, node_queue);
    while(!IsQueueEmpty(node_queue)) {
        node = FrontAndDequeue(node_queue);
        printf("Index: %d, Value: %d\n", node->index, node->data);
        if (node->left_child != NULL)
            Enqueue(node->left_child, node_queue);
        if (node->right_child != NULL)
            Enqueue(node->right_child, node_queue);
    }

    return OK;
}
