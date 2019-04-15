//
//  BNstring.cpp
//  数据结构算法练习
//
//  Created by zengbailiang on 2019/4/4.
//  Copyright © 2019年 zengbailiang. All rights reserved.
//

#include "BNstring.hpp"
#include <vector>
#include "string"
#include "stack"
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

/*
 20. 有效的括号
 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
 
 有效字符串需满足：
 
 左括号必须用相同类型的右括号闭合。
 左括号必须以正确的顺序闭合。
 注意空字符串可被认为是有效字符串。
 示例 1:
 
 输入: "()"
 输出: true
 示例 2:
 
 输入: "()[]{}"
 输出: true
 示例 3:
 
 输入: "(]"
 输出: false
 示例 4:
 
 输入: "([)]"
 输出: false
 示例 5:
 
 输入: "{[]}"
 输出: true
 */
/*我晕，开始写了两种面相过程的处理方式，都没有过全部案例，发现不能覆盖全部的情况。后面联系了下过去对z括号类似于算术法的计算过程，好像是用栈去处理，在看下这个结构很适合使用栈来处理。所以开始做的时候花一两分钟去想下这个题目是否是某一类问题，是否需要某种数据结构来处理，这样的话可能就能找到对的思路，而不会在错的方式哪里几番折腾了。1.题目的类型，2.适合的数据结构。
 */
bool isValid(string s) {
    //使用一个栈来处理
    stack<char> stt;
    for (int i = 0; i < s.size(); i ++) {
        char dst  = s[i];
        if (stt.empty()) {
            stt.push(dst);
        }
        else
        {
            char pst = stt.top();
            if((pst == '{' && dst == '}')
               ||(pst == '[' && dst == ']')
               ||(pst == '(' && dst == ')'))
            {
                stt.pop();
            }
            else
            {
                stt.push(dst);
            }
        }
    }
    return stt.empty();
}

