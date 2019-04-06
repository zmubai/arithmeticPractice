//
//  linkedList.cpp
//  数据结构算法练习
//
//  Created by zengbailiang on 2019/4/3.
//  Copyright © 2019年 zengbailiang. All rights reserved.
//

#include "linkedList.hpp"
#include <vector>
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

/*
 237. 删除链表中的节点
 请编写一个函数，使其可以删除某个链表中给定的（非末尾）节点，你将只被给定要求被删除的节点。
 
 现有一个链表 -- head = [4,5,1,9]，它可以表示为:
 示例 1:
 
 输入: head = [4,5,1,9], node = 5
 输出: [4,1,9]
 解释: 给定你链表中值为 5 的第二个节点，那么在调用了你的函数之后，该链表应变为 4 -> 1 -> 9.
 示例 2:
 
 输入: head = [4,5,1,9], node = 1
 输出: [4,5,9]
 解释: 给定你链表中值为 1 的第三个节点，那么在调用了你的函数之后，该链表应变为 4 -> 5 -> 9.
 
 
 说明:
 
 链表至少包含两个节点。
 链表中所有节点的值都是唯一的。
 给定的节点为非末尾节点并且一定是链表中的一个有效节点。
 不要从你的函数中返回任何结果。
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
 采用复制后面节点的方式巧妙处理，剑指offer里面的有类似题目
 */
void deleteNode(ListNode* node) {
    if(node->next == NULL)
    {
        node = NULL;
    }
    else
    {
        node->val = node->next->val;
        node->next = node->next->next;
    }
}

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool findNode(TreeNode* root, TreeNode* x,vector<TreeNode*>& v)
{
    if (root == x) {
        v.push_back(root);
//        cout<<root->val<<"";
        return true;
    }
    else if (root != NULL)
    {
        
        if (root ->left != NULL && findNode(root ->left, x, v) == true) {
            v.push_back(root ->left);
//            cout<<root->left->val<<"";
            return true;
        }
        else if(root ->right != NULL && findNode(root ->right, x, v))
        {
            v.push_back(root ->right);
//            cout<<root->right->val<<"";
            return true;
        }
    }
    return false;
}

/*用两个向量容器记录查找的路径，通过路径找到最后一个相同元素，即为最近公共父节点*/
///任何的二叉树找最近公共父节点都可以
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    vector<TreeNode*> vp;
    vector<TreeNode*> vq;
    bool a = findNode(root, p, vp);
//    cout << "#"<<"";
    bool b =  findNode(root, q, vq);
    if(root != p)
    {
        vp.push_back(root);
    }
    if(root != q)
    {
        vq.push_back(root);
    }
    if (a && b) {
        long i = vp.size();
        long j = vq.size();
        while (i >=0 && j >=0) {
            if(vp[i] != vq[j])
            {
                return vp[i + 1];
            }
            else if(i == 0)
            {
                return vp[i];
            }
            else if (j == 0)
            {
                return vq[j];
            }
            i --;
            j --;
        }
        
        return NULL;
    }
    else
    {
        return NULL;
    }
    // return NULL;
}

///利用二叉搜索树的d特点
TreeNode* lowestCommonAncestorx(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == NULL)return NULL;
    ///考虑相等的情况
    if ((root->val <= p->val && root->val >= q->val)||
        (root->val >= p->val && root->val <= q->val))
    {
        return root;
    }
    else if (root->val < p->val && root->val < q->val ) {
        return  lowestCommonAncestor(root->right, p, q);
    }
    else if (root->val > p->val && root->val > q->val )
    {
        return  lowestCommonAncestor(root->left, p, q);
    }
    else
    {
        return NULL;
    }
}
