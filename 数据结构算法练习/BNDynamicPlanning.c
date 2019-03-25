//
//  BNDynamicPlanning.c
//  数据结构算法练习
//
//  Created by zengbailiang on 2019/3/19.
//  Copyright © 2019年 zengbailiang. All rights reserved.
//  动态规划 或 贪心算法

#include "BNDynamicPlanning.h"

//leetcode121. 买卖股票的最佳时机
/*
 给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
 
 如果你最多只允许完成一笔交易（即买入和卖出一支股票），设计一个算法来计算你所能获取的最大利润。
 
 注意你不能在买入股票前卖出股票。
 
 示例 1:
 
 输入: [7,1,5,3,6,4]
 输出: 5
 解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
 注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格。
 示例 2:
 
 输入: [7,6,4,3,1]
 输出: 0
 解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。
 */
int maxProfit(int* prices, int pricesSize) {
    if(pricesSize < 2){
        return 0;
    }
    if (prices == NULL) {
       return 0;
    }
    int min = prices[0];//记录当前最低买入价格
    int maxRes = 0;//记录当前最大收益
    for (int i = 0 ; i < pricesSize; i ++) {
        if(min > prices[i])
        {
            min = prices[i];
        }
        if (maxRes < prices[i] - min) {
            maxRes = prices[i] - min;
        }
    }
    return maxRes;
}

/*
 198. 打家劫舍
 你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
 
 给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。
 
 示例 1:
 
 输入: [1,2,3,1]
 输出: 4
 解释: 偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
 偷窃到的最高金额 = 1 + 3 = 4 。
 示例 2:
 
 输入: [2,7,9,3,1]
 输出: 12
 解释: 偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
 偷窃到的最高金额 = 2 + 9 + 1 = 12 。
 */
///需要使用动态规划 fn = max(f(n-2) + res[n], f(n-1));
int rob(int* nums, int numsSize) {
    if(nums == NULL || numsSize == 0) return 0;
    if(numsSize == 1) return nums[0];
    int fn0 = nums[0];
    int fn1 = nums[1] > nums[0] ? nums[1] : nums[0];
    for (int i = 2; i < numsSize; i++) {
        int temp = (fn0 + nums[i]) > fn1? (fn0 + nums[i]) : fn1;
        fn0 = fn1;
        fn1 = temp;
    }
    return fn1;
}

/*
 300. 最长上升子序列
 给定一个无序的整数数组，找到其中最长上升子序列的长度。
 
 示例:
 
 输入: [10,9,2,5,3,7,101,18]
 输出: 4
 解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。
 说明:
 
 可能会有多种最长上升子序列的组合，你只需要输出对应的长度即可。
 你算法的时间复杂度应该为 O(n2)。
 进阶: 你能将算法的时间复杂度降低到 O(n log n) 吗?
 */
// statu: i did
int lengthOfLIS(int* nums, int numsSize) {
    if (nums == NULL || numsSize == 0) {
        return 0;
    }
    int *p = (int*)malloc(sizeof(int)*numsSize);
    memset(p,0,sizeof(int)*numsSize);
    
    p[0] = 1;
    int res = 1;//记录全局最大连续升序列
    ///复杂度 n * n
    for (int i = 0 ; i < numsSize; i ++) {
        int max = 0;
        for (int j = 0; j< i;j ++) {
            ///考虑下当前最大升序列，会受到前面的比它小的p的影响。并遍历获取做大p ，max+1为p[i];不是单纯的动态规划，动态规划的基础上还要遍历前面的元素，获取最大的p。
            if (nums[j]<nums[i]) {
                if (max < p[j])
                {
                    max = p[j];
                }
            }
        }
        p[i] = max + 1;//当前位置最大升序列
        if(res < p[i]) res = p[i];
    }
    return res;
}

/*
 高级解法，贪心选择 + 二分查找
 https://blog.csdn.net/lw_power/article/details/80758674
 */

int insertAndTryReplaceByBinarySearch(int *nums,int len,int dst)
{
    ///如果比最后的元素还大，插入
    if (dst > nums[len - 1]) {
        nums[len] = dst;
        return 1;
    }
    ///查找合适的位置替换，二分查找第一个比他小的元素，并替换这个元素的下一个元素。
    int mid = 0;
    int left = 0;
    int right = len - 1;
    ///do while 比较合适，不然结束条件不好写
    do {
        mid = left + (right - left) / 2;
        printf("mid:%d  left:%d  right:%d\n",mid,left,right);
        if (nums[mid] > dst) {
            ///保留当前mid的值，可能作为第一个比dst大。
            right = mid;
        }
        else if(nums[mid] < dst)
        {
            left = mid + 1;
        }
        else
        {
            return 0;
        }
    } while (left < right);
    nums[left] = dst;
    return 0;
}


int lengthOfLIS1(int* nums, int numsSize)
{
    if(nums == NULL || numsSize == 0) return 0;
    int *tempNums = (int *)malloc(sizeof(int) * numsSize);
    int len = 1;
    tempNums[0] = nums[0];
    for (int i = 1; i < numsSize; i ++) {
      int res  = insertAndTryReplaceByBinarySearch(tempNums, len, nums[i]);
        if (res == 1) {
            len ++;
        }
    }
    return len;
}

