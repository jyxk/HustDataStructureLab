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
Status ClearBiTree(PtrToTree T) {
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
 * @brief get the {index} node in T
 * 
 * @param T 
 * @param index 
 * @return Status 
 */
Status Value(PtrToTree T, int index);


int 
/**
 * @brief assign the index node in T with value
 * 
 * @param T 
 * @param index 
 * @param value 
 * @return Status 
 */
Status Assign(PtrToTree T, int index, int value);

/**
 * @brief get parent node of index in T
 * 
 * @param T 
 * @param index 
 * @return PtrToNode 
 */
PtrToNode Parent(PtrToTree T, int index);

/**
 * @brief get the left child of index
 * 
 * @param T 
 * @param index 
 * @return PtrToNode 
 */
PtrToNode LeftChild(PtrToTree T, int index);

/**
 * @brief get the right child of index
 * 
 * @param T 
 * @param index 
 * @return PtrToNode 
 */
PtrToNode RightChild(PtrToTree T, int index);

/**
 * @brief get the left sibing of index in T
 * 
 * @param T 
 * @param index 
 * @return PtrToNode 
 */
PtrToNode LeftSibling(PtrToTree T, int index);

/**
 * @brief get the right sibing of index in T
 * 
 * @param T 
 * @param index 
 * @return PtrToNode 
 */
PtrToNode RightSibling(PtrToTree T, int index);

/**
 * @brief insert LorR child to p
 * 
 * @param T 
 * @param p 
 * @param LorR 
 * @return Status 
 */
Status InsertChild(PtrToTree T, PtrToNode p, int LorR);

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