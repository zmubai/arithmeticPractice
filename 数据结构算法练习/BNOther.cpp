//
//  BNOther.cpp
//  数据结构算法练习
//
//  Created by zengbailiang on 2019/4/6.
//  Copyright © 2019年 zengbailiang. All rights reserved.
//

#include "BNOther.hpp"
#include "vector"
/*
 292. Nim游戏
 你和你的朋友，两个人一起玩 Nim游戏：桌子上有一堆石头，每次你们轮流拿掉 1 - 3 块石头。 拿掉最后一块石头的人就是获胜者。你作为先手。
 
 你们是聪明人，每一步都是最优解。 编写一个函数，来判断你是否可以在给定石头数量的情况下赢得游戏。
 
 示例:
 
 输入: 4
 输出: false
 解释: 如果堆中有 4 块石头，那么你永远不会赢得比赛；
 因为无论你拿走 1 块、2 块 还是 3 块石头，最后一块石头总是会被你的朋友拿走。
 */
/*
 假设为n块石头，每次能拿1-m块。如果最后只剩下m+1块那么后手必赢。如果n = （m+1）*k,那么后水只需要根据先手拿的块数a，拿出m+1 - a 的块数即可。如果n = (m+1)*k + s，那么先手第一次拿走s，必胜，但如果s==0，那么先手必输。
 */
bool canWinNim(int n) {
    return n%4 == 0 ?false:true;
    }

/*
 136. 只出现一次的数字
 给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
 
 说明：
 
 你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
 
 示例 1:
 
 输入: [2,2,1]
 输出: 1
 示例 2:
 
 输入: [4,1,2,1,2]
 输出: 4
 */
/*
 异或一下就可以了||排序对比，哈希表也是可以的
 */
int singleNumber(vector<int>& nums) {
    if(nums.size() == 0)
    {
        return -1;
    }
    if(nums.size() == 1)
    {
        return nums[0];
    }
    int x = nums[0];
    for (int i = 1; i < nums.size(); i ++) {
        x ^= nums[i];
    }
    return x;
}
