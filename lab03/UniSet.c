/*
 * AUTHOR: Xiuxu Jin
 * GITHUB: jyxk
 * E_MAIL: jyxking007@gmail.com
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