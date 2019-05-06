//
//  linkedList.cpp
//  数据结构算法练习
//
//  Created by zengbailiang on 2019/4/3.
//  Copyright © 2019年 zengbailiang. All rights reserved.
//

#include "linkedList.hpp"
#include <vector>
#include <map>
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

/*
 160. 相交链表
 编写一个程序，找到两个单链表相交的起始节点。
 注意：
 
 如果两个链表没有交点，返回 null.
 在返回结果后，两个链表仍须保持原有的结构。
 可假定整个链表结构中没有循环。
 程序尽量满足 O(n) 时间复杂度，且仅用 O(1) 内存。[被这里m迷惑了]
 */
/*
 
 */
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int aSize = 0;
    int bSize = 0;
    ListNode *tA = headA;
    ListNode *tB = headB;
    while (tA != NULL) {
        ++ aSize;
        tA = tA->next;
    }
    while (tB != NULL) {
        ++ bSize;
        tB = tB->next;
    }
    
    int skip;
    if(aSize > bSize)
    {
        skip = aSize - bSize;
        aSize = bSize;
        while (skip > 0) {
            -- skip;
            if(headA == NULL) return NULL;
            headA = headA->next;
        }
    }
    else
    {
        skip = bSize - aSize;
        bSize = aSize;
        while (skip > 0) {
            -- skip;
            if(headB == NULL) return NULL;
            headB = headB->next;
        }
    }
    while (headB != NULL && headA !=NULL ) {
        if(headB != headA)
        {
            headB = headB ->next;
            headA = headA ->next;
        }
        else
        {
            return headB;
        }
    }
    return NULL;
};


bool hasCycle(ListNode *head) {
    //1.如果要求常量的内存，那么用Map标记下，就能判断出，是否有环
    map<ListNode* ,int> history;
    while (head != NULL) {
        if (history.find(head) != history.end())
        {
            return true;
        }
        history.insert(pair<ListNode* ,int>(head,1));
    }
    return false;
}

bool hasCyclex(ListNode *head) {
    //2.如果需要常量的内存，那么可以使用快慢跑这，我开始想的时候，也是一个快一个慢，但就是想一次遍历就能找出结果，抓住这个不放，以致于放下这个思路去实现，方法1。
    //一个走两步，一个走一步。
    if (head == NULL) {
        return false;
    }
    ListNode *headLow = head;
    ListNode *headFast = head ->next;
    
    while (headFast != NULL) {
        if(headFast == headLow)
        {
            return true;
        }
        else
        {
            headFast = headFast->next;
            if(headFast == NULL) return false;
            headFast = headFast->next;
            headLow = headLow->next;
        }
    }
    return false;
}

/*
 给定一个二叉搜索树，编写一个函数 kthSmallest 来查找其中第 k 个最小的元素。
 
 说明：
 你可以假设 k 总是有效的，1 ≤ k ≤ 二叉搜索树元素个数。
 
 示例 1:
 
 输入: root = [3,1,4,null,2], k = 1
 3
 / \
 1   4
 \
 2
 输出: 1
 示例 2:
 
 输入: root = [5,3,6,2,4,null,null,1], k = 3
 5
 / \
 3   6
 / \
 2   4
 /
 1
 输出: 3
 进阶：
 如果二叉搜索树经常被修改（插入/删除操作）并且你需要频繁地查找第 k 小的值，你将如何优化 kthSmallest 函数？
 */
void subKthSmallest(TreeNode *root, int &r, int &k)
{
    if(root == NULL || k == 0)
    {
        return;
    }
    subKthSmallest(root->left, r, k);
//    mins.push_back(root->val);
    k--;
    if(k == 0)
    {
        r = root->val;
        return;
    }
    subKthSmallest(root->right, r, k);
}

int kthSmallest(TreeNode* root, int k) {
    int r = 0;
    int sum = k;
    subKthSmallest(root, r, sum);
    return r;
}

/*首先想到的方法，使用了额外的空间去存储元素*/
void subKthSmallest1(TreeNode *root, vector<int> &mins, int k)
{
    if(root == NULL || mins.size() == k)
    {
        return;
    }
    subKthSmallest1(root->left, mins, k);
    if(mins.size() == k)
    {
        return;
    }
    mins.push_back(root->val);
    if(mins.size() == k)
    {
        return;
    }
    subKthSmallest1(root->right, mins, k);
    if(mins.size() == k)
    {
        return;
    }
}

int kthSmallest1(TreeNode* root, int k) {
    vector<int> mins;
    subKthSmallest1(root, mins, k);
    // cout<<mins.size()<<"";
    return mins[k-1];
}
