//
//  BNstring.cpp
//  数据结构算法练习
//
//  Created by zengbailiang on 2019/4/4.
//  Copyright © 2019年 zengbailiang. All rights reserved.
//

#include "BNstring.hpp"
#include <vector>
/*
 编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 char[] 的形式给出。
 
 不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。
 
 你可以假设数组中的所有字符都是 ASCII 码表中的可打印字符。
 
 
 
 示例 1：
 
 输入：["h","e","l","l","o"]
 输出：["o","l","l","e","h"]
 示例 2：
 
 输入：["H","a","n","n","a","h"]
 输出：["h","a","n","n","a","H"]
 */
/*
 前后指针交换
 */
void reverseString(vector<char>& s) {
    long left = 0 ;
    long right = s.size() - 1;
    while (left<right) {
        int temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
}

///看了答案中比较好的处理方式，改写
void reverseString1(vector<char>& s) {
    long size = s.size();
    for (long i = 0; i < size / 2; i ++) {
        long temp = s[i];
        s[i] = s[size - i - 1];
        s[size - i - 1] = temp;
    }
}
