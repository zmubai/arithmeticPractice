//
//  BNBinaryTree.c
//  数据结构算法练习
//
//  Created by zengbailiang on 2019/3/13.
//  Copyright © 2019年 zengbailiang. All rights reserved.
//

#include "BNBinaryTree.h"

//104. 二叉树的最大深度
/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int maxDepth(struct TreeNode* root) {
    if(root == NULL) return 0;
    int dl =  maxDepth(root->left);
    int dr =  maxDepth(root->right);
    //容易出错的地方 1 + dl>dr?dl:dr; 【很容易导致错误的写法】 ，记得加括弧
    return 1 + (dl>dr?dl:dr);
}
