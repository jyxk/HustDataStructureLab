/*
 * @Author: Xiuxu Jin(jyxk)
 * @Date: 2018-10-19 09:04:21
 * @LastEditors: Xiuxu Jin
 * @LastEditTime: 2018-11-06 21:58:46
 * @Description: BinTree.h
 * @Email: jyxking007@gmail.com
 */

#ifndef _BINTREE_H
#define _BINTREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE  1
#define FALSE 0

#define OK    0
#define ERROR 1

#define LEFT  0
#define RIGHT 1

#define PRE_ORDER  0
#define IN_ORDER   1
#define POST_ORDER 2

typedef int ElementType;
typedef int Status;
typedef int BOOL;
struct TreeNode;
struct BinTree;

typedef struct TreeNode *PtrToNode;
typedef struct BinTree  *PtrToTree;

//the struct of Binary tree
typedef struct TreeNode {
    int index;
    ElementType data;
    PtrToNode left_child;
    PtrToNode right_child;
} TreeNode;

typedef struct BinTree {
    int id;
    int size;
    PtrToNode root;
    PtrToTree next;
} BinTree;

typedef struct TreeSet {
    PtrToTree head;
} TreeSet;

/**
 * @brief Inital a binary tree
 * 
 * @param T 
 * @return Status 
 */
Status InitBiTree(PtrToTree T);

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
int BiTreeDepth(PtrToTree T);

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
Status InsertChild(PtrToTree T, int index, int LorR, PtrToTree C);

/**
 * @brief delete LorR child of p
 * 
 * @param T 
 * @param p 
 * @param LorR 
 * @return Status 
 */
Status DeleteChild(PtrToTree T, int index, int LorR);

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

#endif