//
//  BNDyPlan.c
//  数据结构算法练习
//
//  Created by zengbailiang on 2019/3/12.
//  Copyright © 2019年 zengbailiang. All rights reserved.
//

#include "BNDyPlan.h"
///lett 70 爬楼梯

///我的思路 递归
int realClibmbStairs(int *fn,int n)
{
    if(n<=1) return 1;
    ////AAAAA
    if(fn[n] != 0) return fn[n];
    fn[n] = realClibmbStairs(fn,n-1) + realClibmbStairs(fn,n-2);
    return fn[n];
}

int climbStairs(int n) {
    if (n <= 1) return 1;
    if (n == 2) return 2;
    int *fn = (int*)malloc(sizeof(int) * (n + 1));
    ///不能使用sizeof(fn)，初始化，会错误。必须要初始化。不然AAAAA的地方就会因为随机值，而退出，程序不正确。
    memset(fn,0,sizeof(int) * (n + 1));
    return realClibmbStairs(fn,n);
}

///其他思路， 动态规划
int _climbStairs(int n) {
    int *dp = (int *)malloc(sizeof(int)*(n+1));
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for(int j=3; j<=n; j++)
        dp[j] = dp[j-1]+dp[j-2];
    return dp[n];
}

///循环，更高效 ，斐波那契数列 [典型的斐波那契]
int __climbStairs(int n) {
    if (n <= 2) {
        return n;
    }
    int pre1 = 2, pre2 = 1;
    for (int i = 2; i < n; i++) {
        int cur = pre1 + pre2;
        pre2 = pre1;
        pre1 = cur;
    }
    return pre1;
}

//=============================================
//leetcode 746. 使用最小花费爬楼梯 【动态规划】
int min(int a, int b)
{
    return a>b ? b :a ;
}

int minCostClimbingStairs(int* cost, int costSize) {
    //f(n) = min(f(n-1),fn(n-2));
    if(costSize == 0) return -1;
    if(costSize == 1) return 0;
    if(costSize == 2) return min(cost[0],cost[1]);
    int *fn = malloc(sizeof(int) * costSize);
    fn[0] = 0;
    fn[1] = 0;
    fn[2] = min(cost[0],cost[1]);
    for(int i = 3; i < costSize;i++)
    {
        ///fn[i]，为落实到第 i 不得动态值，包含本值（+ cost[i]），以提供给后面使用
        fn[i] = min(fn[i-1],fn[i-2]) + cost[i];
    }
    
    return min(fn[costSize-2],fn[costSize - 1]);
}
