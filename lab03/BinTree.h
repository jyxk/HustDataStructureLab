/*
 * AUTHOR: Xiuxu Jin
 * GITHUB: jyxk
 * E_MAIL: jyxking007@gmail.com
 */

#ifndef _BINTREE_H
#define _BINTREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

#define OK 0
#define ERROR 1

typedef int ElementType;
typedef int Status;
struct TreeNode;
struct BinTree;

typedef struct TreeNode *PtrToNode;
typedef struct BinTree  *PtrToTree;

//the struct of Binary tree
typedef struct TreeNode {
    int index;
    ElementType element;
    PtrToNode left_child;
    PtrToNode right_child;
} TreeNode;

typedef struct BinTree {
    int size;
    PtrToNode head;
} BinTree;

#endif