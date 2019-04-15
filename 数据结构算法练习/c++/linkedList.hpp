//
//  linkedList.hpp
//  数据结构算法练习
//
//  Created by zengbailiang on 2019/4/3.
//  Copyright © 2019年 zengbailiang. All rights reserved.
//

#ifndef linkedList_hpp
#define linkedList_hpp
using namespace std;
#include <stdio.h>
struct ListNode {
    int val;
    ListNode *next;
//    ListNode(int x) : val(x), next(NULL) {}
};
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) ;
#endif /* linkedList_hpp */
