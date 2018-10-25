/*
 * @Author: Xiuxu Jin(jyxk)
 * @Date: 2018-10-19 10:37:35
 * @LastEditors: Xiuxu Jin
 * @LastEditTime: 2018-10-19 10:43:18
 * @Description: file content
 * @Email: jyxking007@gmail.com
 */

/**
 * @file BinTree.c
 * @author Xiuxu Jin(jyxk) (jyxking007@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2018-10-19
 * 
 * @copyleft CopyLeft (c) 2018
 * 
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
Status DestoryBiTree(PtrToTree T);

/**
 * @brief Create a Bi Tree object
 * 
 * @param T 
 * @return Status 
 */
Status CreateBiTree(PtrToTree T);

/**
 * @brief Clear the binary tree T
 * 
 * @param T 
 * @return Status 
 */
Status ClearBiTree(PtrToTree T);

/**
 * @brief Is the binary tree T empty?
 * 
 * @param T 
 * @return BOOL 
 */
BOOL IsBiTreeEmpty(PtrToTree T);

/**
 * @brief get the binary tree's depth
 * 
 * @param T 
 * @return Status 
 */
Status BiTreeDepth(PtrToTree T);

/**
 * @brief get the root of T and return it 
 * 
 * @param T 
 * @return PtrToNode 
 */
PtrToNode Root(PtrToTree T);

/**
 * @brief get the {index} node in T
 * 
 * @param T 
 * @param index 
 * @return Status 
 */
Status Value(PtrToTree T, int index);

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
