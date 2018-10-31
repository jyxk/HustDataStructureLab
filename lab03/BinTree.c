/*
 * @Author: Xiuxu Jin(jyxk)
 * @Date: 2018-10-24 07:48:14
 * @LastEditors: Xiuxu Jin(jyxk)
 * @LastEditTime: 2018-10-24 09:12:25
 * @Description: the implement of binary tree ADT
 */

#include "BinTree.h"

/**
 * @brief Inital a binary tree
 * 
 * @param T 
 * @return Status 
 */
Status InitBiTree(PtrToTree T) {
    T->size = 0;
    T->root = NULL;
    return OK;
}

/**
 * @brief destory a binary tree
 * 
 * @param T 
 * @return Status 
 */
Status DestoryBiTree(PtrToTree T) {
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
    return;   
}

/**
 * @brief Create a Binary Tree object
 * 
 * @param T 
 * @return Status 
 */
Status CreateBiTree(PtrToTree T) {
    
}

/**
 * @brief Clear the binary tree T
 * 
 * @param T 
 * @return Status 
 */
Status ClearBiTree(PtrToTreheade T) {
    T->size = 0;
    FreeAllNode(T->root);
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
        return 0;
    if (node->index == index)
        return node->data;
    else {
        int left = getValue(node->left_child, index);
        int right = getValue(node->right_child, index);
        return left|right;
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
        return 0;
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
    if (node->index == value) {
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
    setAssign(T->root, index, value, flag);
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
    PtrToNode parent = Parent(T->root, index);
    if (parent->index == index)
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
    PtrToNode parent = Parent(T->root, index);
    if (parent->index == index)
        return NULL;
    else    
        return parent->right_child;
}

/**
 * @brief insert LorR child to p
 * 
 * @param T 
 * @param p 
 * @param LorR 
 * @return Status 
 */
Status InsertChild(PtrToTree T, PtrToNode p, int LorR, PtrToTree ) {

}

/**
 * @brief delete LorR child of p
 * 
 * @param T 
 * @param p 
 * @param LorR 
 * @return Status 
 */
Status DeleteChild(PtrToTree T, PtrToNode p, int LorR);

/**
 * @brief Traverse the binary tree T by preorder
 * 
 * @param T 
 * @return Status 
 */
Status PreOrderTraverse(PtrToTree T);

/**
 * @brief Traverse the binary tree T by inorder
 * 
 * @param T 
 * @return Status 
 */
Status InOrderTraverse(PtrToTree T);

/**
 * @brief Traverse the binary tree T by postorder
 * 
 * @param T 
 * @return Status 
 */
Status PostOrderTraverse(PtrToTree T);

/**
 * @brief Traverse the binary tree T by level
 * 
 * @param T 
 * @return Status 
 */
Status LevelOrderTraverse(PtrToTree T);
