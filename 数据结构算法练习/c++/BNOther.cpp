//
//  BNOther.cpp
//  数据结构算法练习
//
//  Created by zengbailiang on 2019/4/6.
//  Copyright © 2019年 zengbailiang. All rights reserved.
//

#include "BNOther.hpp"
#include "vector"
#include "map"
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

/*
 判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
 
 示例 1:
 
 输入: 121
 输出: true
 示例 2:
 
 输入: -121
 输出: false
 解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
 示例 3:
 
 输入: 10
 输出: false
 解释: 从右向左读, 为 01 。因此它不是一个回文数。
 */
/*获取每一位放入向量容器中，然后前后指针对比，如果遇到不相等的退出返回false，如果执行到最后则为回文数*/
bool isPalindrome(int x) {
    if (x < 0) {
        return false;
    }
    vector<int> v;
    while (x > 0) {
        v.push_back(x%10);
        x /= 10;
    }
    int left = 0;
    int right = (int)v.size() - 1;
    while (left < right) {
        if (v[left] != v[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

bool isPalindromexx(int x) {
    ///跟解法一思路上完全一致，其实就是修改了判断的顺序，测试用例的集合少于0的数比较少。如果在实际编码中需要考虑输入的集合的情况来优化条件判断的顺序，这个也能提高程序的执行效率。
    if (x >= 0) {
        vector<int> v;
        while (x) {
            v.push_back(x%10);
            x /= 10;
        }
        int left = 0;
        int right = (int)v.size() - 1;
        while (left < right) {
            if (v[left] != v[right]) {
                return false;
            }
            ++left;
            --right;
        }
        return true;
    }
    return false;
}

/*别的解法，根据回文数的特点，原数的低位为回文数的高位，这样生成一个回文数，对比原数，如果相等那么原数就是回文数，反之不是*/
bool isPalindromeX(int x) {
    long long ans = 0;
    int temp = x;
    while(temp > 0) {
        ans = ans * 10 + temp % 10;
        temp /= 10;
    }
    
    return (x == ans);
}

/*
 231. 2的幂
 给定一个整数，编写一个函数来判断它是否是 2 的幂次方。
 
 示例 1:
 
 输入: 1
 输出: true
 解释: 20 = 1
 示例 2:
 
 输入: 16
 输出: true
 解释: 24 = 16
 示例 3:
 
 输入: 218
 输出: false
 */
bool isPowerOfTwo(int n) {
    if(n == 1) return true;
    int g = 2;
    bool flag = false;
    while(1)
    {
        // int pre = n ;
        while(n % g !=0 && g > 2)
        {
            //标记过高，并查找合适的g
            flag = true;
            g /= 2;
        }
        if(g  == 1 || n % 2 != 0)
        {
            return false;
        }
        else
        {
            if(n == g ) return true;
            n /= g;
        }
        //判断结果
        if(n == 2)
        {
            return true;
        }
        else if(n%2 != 0)
        {
            return false;
        }
        else if (n == 0)
        {
            return false;
        }
        ///先指数增长，如果过高标记后平缓增长
        g *= flag?2:g;
        
    }
    return true;
}

/*高端解法
 负数不是
 如果为2的幂，那么 n 与 n-1 的二进制与运算结果为0 如果 2【00000010】 1【000000001】
 */
bool isPowerOfTwox(int n) {
    return n && ((n&(n-1)) == 0);
    /*
     leetcode 编译器问题,n 为大负数的时候越界，正常来说 n 少于0不会执行&&后的条件判断的
     if(n <=0) return false;
     return ((n&(n-1)) == 0);
     */
}

//class BNOther {
//
//}

//void pop() {
//    
//}
//
//int top() {
//    
//}
//
//int getMin() {
//    
//}

/*
 436. 寻找右区间
 
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
static bool cmp0(pair<int, int> a , pair<int, int> b){
    return a.first < b.first;
}
static bool cmp1(pair<int, int> a , int b ){
    ///< 代表没有比较继续  返回true
    /// >= 表示比较结束 返回false
    return a.first < b;
}
vector<int> findRightInterval(vector<vector<int>>& intervals) {
    int n = intervals.size();
    vector<pair<int, int>> pairs(n);
    vector <int> res(n,-1);
    for (int i = 0; i < n; i ++) {
        int left = intervals[i][0];
        pairs[i] = make_pair(left,i);
    }
    sort(pairs.begin(), pairs.end(), cmp0);
    for (int i = 0; i < n; i ++) {
        int right = intervals[i][1];
        ///获取第一个大于等于right的
        /*
         auto可以在声明变量的时候根据变量初始值的类型自动为此变量选择匹配的类型，类似的关键字还有decltype
         自动匹配类型
         */
       auto it = lower_bound(pairs.begin(), pairs.end(), right, cmp1);
        if (it != pairs.end()) {
            ///(*it)获取迭代器当前的值，second 当前值的第二个元素
            res[i] = (*it).second;
        }
    }
    return res;
}

/*
 454. 四数相加 II
 给定四个包含整数的数组列表 A , B , C , D ,计算有多少个元组 (i, j, k, l) ，使得 A[i] + B[j] + C[k] + D[l] = 0。
 
 为了使问题简单化，所有的 A, B, C, D 具有相同的长度 N，且 0 ≤ N ≤ 500 。所有整数的范围在 -228 到 228 - 1 之间，最终结果不会超过 231 - 1 。
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/4sum-ii
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
    map<long, long> mmap;
    int res = 0;
    ///如果是0 的长度 会怎么办。 因为是具有相同的长度，所以如果是0的化，直接返回是0.
    for (int i = 0 ; i < A.size(); i ++) {
        for (int j = 0; j < B.size(); j ++) {
            int v = A[i] + B[j];
            auto it = mmap.find(v);
            if (it != mmap.end()) {
                mmap[v] += 1;
            }
            else{
                mmap[v] = 1;
            }
        }
    }
    
    for (int i = 0 ; i < C.size(); i ++) {
        for (int j = 0; j < D.size(); j ++) {
            auto it = mmap.find(-(C[i] + D[j]));
            if(it != mmap.end()){
                ///first 取的是key, second 取的是value
                res += (*it).second;
            }
        }
    }
    return res;
}
