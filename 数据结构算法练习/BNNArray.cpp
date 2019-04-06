//
//  BNNArray.cpp
//  数据结构算法练习
//
//  Created by zengbailiang on 2019/3/25.
//  Copyright © 2019年 zengbailiang. All rights reserved.
//

#include "BNNArray.hpp"
#include <map>
#include <set>
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

//1 5 1 5 9 k = 2  t = 3 //使用有序集合set
bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    //k index之差
    //t value之差
    set<long> window;//维护一个长度为k的有序窗口
    long tt = t;
    for (int i = 0 ; i < nums.size(); i ++) {
        //擦除某个值
        if (i > k) window.erase(nums[i - k - 1]);
        //获取第一个等于或则大于入参的值 x>=nums[i]-t
        //  -t<=|nums[i]-x|<=t  =>  x>=nums[i]-t && x<=(nums[i]+t)
        set<long>::iterator it = window.lower_bound(nums[i] - tt);
        if(it!= window.end() && *(it) <= nums[i] + tt) return true;
        window.insert(nums[i]);
    }
    return false;
}

/*
 219. 存在重复元素 II
 给定一个整数数组和一个整数 k，判断数组中是否存在两个不同的索引 i 和 j，使得 nums [i] = nums [j]，并且 i 和 j 的差的绝对值最大为 k。
 */
bool containsNearbyDuplicate(vector<int>& nums, int k) {
    set<long> window;
    ///考虑长度问题，如果算术式了有一个是long的话，底层就会转成long型。
    long kk = k ;
    ///->向右遍历
    for (int i = 0 ; i < nums.size(); i ++) {
    /// 0 1 2 擦除最左边的
        if(i>k) window.erase(nums[i - kk - 1]);
        ///<-向左查找最近的数匹配
        set<long>::iterator it = window.lower_bound(nums[i]);
        if (it != window.end() && *it == nums[i]) {
            return true;
        }
        window.insert(nums[i]);
    }
    return false;
}

/*88. 合并两个有序数组
 给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。
 
 说明:
 
 初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
 你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
 示例:
 
 输入:
 nums1 = [1,2,3,0,0,0], m = 3
 nums2 = [2,5,6],       n = 3
 
 输出: [1,2,2,3,5,6]
 */
/*
 从后到前归并，只需要时间复杂度m+n，如果从头到位归并可能需要多次移动元素，效率变低。
 */
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    
    if(n == 0)
    {
        return;
    }
    
    int indexA = m - 1;
    int indexB = n - 1;
    int indexC = m + n - 1;
    while(indexB >=0 || indexA >= 0)
    {
        if(indexB < 0)
        {
            nums1[indexC--] = nums1[indexA--];
        }
        else if (indexA < 0)
        {
            nums1[indexC--] = nums2[indexB--];
        }
        else
        {
            if(nums1[indexA] > nums2[indexB])
            {
                nums1[indexC--] = nums1[indexA--];
            }
            else
            {
                nums1[indexC--] = nums2[indexB--];
            }
        }
    }
}


/*
  169. 求众数
 给定一个大小为 n 的数组，找到其中的众数。众数是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。
 
 你可以假设数组是非空的，并且给定的数组总是存在众数。
 
 示例 1:
 
 输入: [3,2,3]
 输出: 3
 示例 2:
 
 输入: [2,2,1,1,1,2,2]
 输出: 2
 */
/*对其进行排序n.如果为偶数，那么有n/2为众数；如果是奇数，那么 n/2也为众数
 */
int majorityElement(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    return nums[nums.size()/2];
}

/*解法二*/
/*
 解题思路：众数在数组中出现次数大于 ⌊ n/2 ⌋，所以遇到同样的数+1，不同的数-1
 只有两种数，众数和非众数
 */
int majorityElementx(vector<int>& nums) {
    int cur = 0;
    int count = 0;
    for(int i = 0; i < nums.size(); i++){
        if(count == 0)
            cur = nums[i];
        if(nums[i] == cur)
            count++;
        else
            count--;
    }
    return cur;
}



