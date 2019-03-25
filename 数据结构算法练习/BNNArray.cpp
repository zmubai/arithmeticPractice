//
//  BNNArray.cpp
//  数据结构算法练习
//
//  Created by zengbailiang on 2019/3/25.
//  Copyright © 2019年 zengbailiang. All rights reserved.
//

#include "BNNArray.hpp"
#include <map>
/*
 217. 存在重复元素
 给定一个整数数组，判断是否存在重复元素。
 
 如果任何值在数组中出现至少两次，函数返回 true。如果数组中每个元素都不相同，则返回 false。
 
 示例 1:
 
 输入: [1,2,3,1]
 输出: true
 示例 2:
 
 输入: [1,2,3,4]
 输出: false
 示例 3:
 
 输入: [1,1,1,3,3,4,3,2,4,2]
 输出: true
 */
///如果使用c++ 还是使用伪代码比较合适。
bool containsDuplicate(vector<int>& nums) {
    ///map的使用
    map<int , int > mapNums;
    
    ///向量的遍历
    for(vector<int>::iterator it = nums.begin();it!=nums.end();it++)
    {
        int x = *it;
        ///通过键去查找是否存在
        if(mapNums.find(x) != mapNums.end())
        {
            return true;
        }
        else
        {
            ///插入键值
            mapNums.insert(pair<int, int>(x,x));
        }
    }
        return false;
    }

/*
 220. 存在重复元素 III
 给定一个整数数组，判断数组中是否有两个不同的索引 i 和 j，使得 nums [i] 和 nums [j] 的差的绝对值最大为 t，并且 i 和 j 之间的差的绝对值最大为ķ。
 
 示例 1:
 
 输入: nums = [1,2,3,1], k = 3, t = 0
 输出: true
 示例 2:
 
 输入: nums = [1,0,1,1], k = 1, t = 2
 输出: true
 示例 3:
 
 输入: nums = [1,5,9,1,5,9], k = 2, t = 3
 输出: false
 */
bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
///if k 和 t确定了有限范围，那么可以通过建立键值对去查找。
    map<long , long >  mapNums;
    ///k 为下标之差最大值，t为值之差绝对值最大值
    long a = k;
    long b = t;
    for(vector<int>::iterator it = nums.begin();it!=nums.end();it++)
    {
        if (a>2*b) {
            //下标作为索引
            mapNums.insert(pair<long, long>(it - nums.begin(),*it));
        }
        else
        {
            //value作为索引
            mapNums.insert(pair<long, long>(*it,it - nums.begin()));
        }
    }
    for(vector<int>::iterator it = nums.begin();it!=nums.end();it++)
    {
        int v0 = *it;
        if (a>2*b) {
            ///有严重问题，当k很大 就傻逼了
            if (a>2*b) {
                for (long i = it - nums.begin(); i <= it - nums.begin() + a; i ++) {
                    long v1 = mapNums.find(i)->second;
                    if (v0 - v1 <= t && v1 - v0 <= t) {
                        return true;
                    }
                }
            }
        }
        else
        {
            int index0 = (int)(it - nums.begin());
            long i;
            ///有严重问题，当k很大 就傻逼了
            for (i = v0 - b; i <= v0 + b; i ++) {
                if (mapNums.find(i)!= mapNums.end()) {
                    long index1 = mapNums.find(i)->second;
                    if (index0 - index1 <= k && index1 - index0 <= k && index1 != index0) {
                        
                        return true;
                    }
                }
            }
        }
    }
    return false;
}
