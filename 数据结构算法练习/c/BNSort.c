//
//  BNSort.c
//  数据结构算法练习
//
//  Created by zengbailiang on 2019/3/6.
//  Copyright © 2019年 zengbailiang. All rights reserved.
//

#include "BNSort.h"

///quickSort 参考BNArray数组取交集


///归并排序
///自上而下的归并 化整为零的处理方式

///原地归并的抽象方法 [lo,mid] [mid +1, hi]
void merge(int *a , int lo, int mid, int hi)
{
    int size = hi - lo + 1;
    ////!!!!!如果不在函数内部创建一个辅助数据，可在全局创建一个同等大小的数组并传入，这样下标的处理很更省力。但是程序至少一次编码，无数次使用。《《应该看哪种方法更高效合理，而不是哪种更容易编码。》》
    int *b = ((int *)malloc(sizeof(int) * size));
    ///使用辅助数组复制元素
    for (int i = 0; i < size; i ++) {
        *(b + i) = *(a + i + lo);
    }
    
    int  index0 = 0;
    int index1 = mid - lo + 1;
    int j = lo;
    ///归并
    while (j <= hi) {
        if(index0 == mid - lo)
        {
            ///如果左边已经处理完
            *(a + j ++) = *(b + index1 ++);
        }
        else if (index1 == size -1)
        {
            ///如果右边已经处理完
            *(a + j ++) = *(b + index0 ++);
        }
        else
        {
            ///比较取较小的归并
            int k0 = *(b + index1);
            int k1 = *(b + index0);
            if( k0 > k1)
            {
                *(a + j ++) = k1;
                index1 ++;
            }
            else
            {
                *(a + j ++) = k0;
                index0++;
            }
        }
    }
}

void mergeSore(int *a, int lo, int hi)
{
    if (lo <= hi) {
        return;
    }
    int mid = lo + (lo + hi) / 2;
    ///处理左部分
    mergeSore(a, lo, mid);
    ///处理右部分
    mergeSore(a, mid + 1, hi);
    ///当处理完左右部分，才执行归并步骤。  此文字思考，结合归并过程可易得出此步骤为最后一步。编程时可填入此步，在补充上面两步逻辑。
    merge(a, lo, mid, hi);
}


///================================================================================
///自下而上的归并 循序渐进的处理方式
void mergeSore1(int *a, int lo , int hi)
{
    ///健壮性判断
    ///....
    
    int size = hi + 1 - hi;
    
    for (int len = 1; len < size ; len = len + len) {
        for (int start = lo; start + len < size; start += len + len/*两个长度*/) {
            merge(a, start, start + len - 1, start + len + len - 1< hi ? start + len + len - 1 : hi/*考虑最后一组数据数据的长度问题*/);
        }
    }
}


///================================================================================
///n 个有序链表，输出一个有序链表
struct Node
{
    int var;
    struct Node *next;
};

///归并生生一个新的有序链表
struct Node* subSort(struct Node *link0,struct Node *link1)
{
    struct Node *head = (struct Node*)malloc(sizeof(struct Node));
    struct Node *cur0 = link0->next;
    struct Node *cur1 = link1->next;
    struct Node *resutCur = head;
    while (cur0 != NULL || cur1 != NULL) {
        if(cur0 == NULL)
        {
            resutCur->var = cur1->var;
            cur1 = cur1->next;
        }
        else if(cur1 == NULL)
        {
            resutCur->var = cur0->var;
            cur0 = cur0->next;
        }
        else
        {
            int max = cur1->var > cur0->var ?  cur1->var:cur0->var;
            resutCur->var = max;
        }
        resutCur ->next = (struct Node*)malloc(sizeof(struct Node));
        resutCur = resutCur ->next;
    }
    resutCur = NULL;
    return head;
}

struct Node* sort(int  n , struct Node **heads)
{
    if (n == 0) {
        return NULL;
    }
    if(n==1)
    {
        return heads[0];
    }
    struct Node *head;
    ///第一第二个归并生成一个有序链表
    head = subSort(heads[0],heads[1]);
    for (int i = 2; i < n ; i ++) {
        ///遍历，合成新链表
       head = subSort(head,heads[i]);
    }
    return head;
}

///更好的思路，（k个长度为n的链表）
/*1.用n个链表的头元素生成一个k大小的最小堆
 2.取出第一个元素
 3.然后再插入取出元素所在链表的下一个元素插入，并调整堆
 4.重复2-3，直到所有元素取出。时间复杂度 k(nlongk);
 */
