//
//  linkedList.cpp
//  数据结构算法练习
//
//  Created by zengbailiang on 2019/4/3.
//  Copyright © 2019年 zengbailiang. All rights reserved.
//

#include "linkedList.hpp"
/*
 21. 合并两个有序链表
 将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
 
 示例：
 
 输入：1->2->4, 1->3->4
 输出：1->1->2->3->4->4

 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode *head;
    ListNode *temp;
    ListNode *head1 = l1;
    ListNode *head2 = l2;
    if(head1 ==  NULL)
    {
        return head2;
    }
    else if (head2 == NULL)
    {
        return head1;
    }
    else
    {
        if(head1->val < head2->val)
        {
            head = head1;
            head1 = head1->next;
        }
        else
        {
            head = head2;
            head2 = head2->next;
        }
    }
    temp = head;
    while(head1 != NULL || head2 != NULL)
    {
        if(head1 == NULL)
        {
            temp->next = head2;
            head2 = head2 ->next;
        }
        else if (head2 == NULL)
        {
            temp->next = head1;
            head1 = head1 ->next;
        }
        else
        {
            if(head1->val<head2->val)
            {
                temp->next = head1;
                head1 = head1 ->next;
            }
            else
            {
                temp->next = head2;
                head2 = head2 ->next;
            }
        }
        temp = temp->next;
    }
    temp->next = NULL;
    return head;
}
