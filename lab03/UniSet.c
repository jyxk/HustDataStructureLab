/*
 * @Author: Xiuxu Jin(jyxk)
 * @Date: 2018-10-24 07:47:03
 * @LastEditors: Xiuxu Jin(jyxk)
 * @LastEditTime: 2018-10-24 07:47:03
 * @Description: file content
 */


#include "BinTree.h"

typedef PtrToTree ElementType;

typedef struct SetNode {
    int index;
    ElementType data;
    struct SetNode *next;
} SetNode;

typedef struct UniSet {
    int num;
    struct SetNode *head;
} UniSet;