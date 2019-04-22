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

/*
 编写一个函数来查找字符串数组中的最长公共前缀。
 
 如果不存在公共前缀，返回空字符串 ""。
 
 示例 1:
 
 输入: ["flower","flow","flight"]
 输出: "fl"
 示例 2:
 
 输入: ["dog","racecar","car"]
 输出: ""
 解释: 输入不存在公共前缀。
 说明:
 
 所有输入只包含小写字母 a-z 。
 */
///有使用字典树的解法
string longestCommonPrefix(vector<string>& strs) {
    if(strs.size() == 0) return "";
    string x ="";
    string fir = strs[0];
    for (int i = 0; i < fir.length(); i ++) {
        char dst = fir[i];
        for (int j = 1; j < strs.size(); j ++) {
            string sec = strs[j];
            if(sec.length() - 1 < i || sec[i] != dst) return x;
        }
        ///添加1个dst到x末尾，append的用法。
        x.append(1,dst);
    }
    return x;
}

/*竞赛题*/
string reverseOnlyLetters(string S) {
    long  left = 0;
    long  right = S.size() - 1;
    while (left < right) {
        while (left < right) {
            if((S[left] >= 'A' && S[left] <= 'Z')
               ||(S[left] >= 'a' && S[left] <= 'z'))
            {
                break;
            }
            left ++;
        }
        if (left >= right) {
            break;
        }
        while (left < right) {
            if((S[right] >= 'A' && S[right] <= 'Z')
               ||(S[right] >= 'a' && S[right] <= 'z'))
            {
                break;
            }
            right --;
        }
        if (left >= right) {
            break;
        }
        char temp = S[left];
        S[left] = S[right];
        S[right] = temp;
        left ++;
        right --;
    }
    return S;
}

/* 解法1 超出时间限制*/
int maxSubarraySumCircular(vector<int>& A) {
    long size = A.size();
    if(size == 0) return 0;
    if(size == 1) return A[0];
    for (int i = 0; i < 2; i ++) {
        for (int i = 0 ; i < size; i ++) {
            A.push_back(A[i]);
        }
    }
    int max = 0;
    //123 123 123
    for (long i = size ; i <= size + size - 1; i ++) {
        //左右扩展1 -n 长度
        if(max < A[i]) max = A[i];
        for (long j = i - 1 ; j > i - size; j --) {
            int temp = A[i];
            if(A[j]<=0) continue;
            for (long k = i - 1; k >= j; k --) {
                temp += A[k];
            }
            if(max < temp) max = temp;
        }
        
        for (long j = i + 1 ; j < i + size; j ++) {
            int temp = A[i];
            if(A[j]<=0) continue;
            for (long k = i + 1; k <= j; k ++) {
                temp += A[k];
            }
            if(max < temp) max = temp;
        }
    }
    return max;
}

int maxWitSubArr(vector<int>& A,int left,int right)
{
    int a = A[left];
    int max = a;
    for (int i = left + 1; i <= right; i ++) {
        if(a + A[i] < A[i])
        {
            a = A[i];
        }
        else
        {
            a = a + A[i];
        }
        if(a > max) max = a;
    }
    return max;
}

/*
 竞赛题 过了97/107个案例，超时，有待优化
 */
int maxSubarraySumCircularB(vector<int>& A) {
    long size = A.size();
    if(size == 0) return 0;
    if(size == 1) return A[0];
    for (int i = 0; i < 2; i ++) {
        for (int i = 0 ; i < size; i ++) {
            A.push_back(A[i]);
        }
    }
    int max = INT_MIN;
    for (int i = 1; i < size + size - 1; i++) {
        int temp = maxWitSubArr(A,i,i + size - 1);
        if(temp > max) max = temp;
    }
    return max;
}

/*
 918. 环形子数组的最大和
 动态规划:1.不跨越边界简单的最大连续和。2.跨越边界，再记录一个最小值。当最大值少于0可以直接返回，否则，获取数组之和减去最小值的差，与最大值对比，取较大的值。第二种情况中，要考虑最大值少于0直接返回（细节，如果少于0 ，返回的就是最大和），另外最大值大于等于0 的情况下，需要用数组和减去最小值获取跨越边界的最大值（关键）
 */
int max (int a , int b )
{
    return a>b?a:b;
}
int min(int a,int b )
{
    return a>b?b:a;
}
int maxSubarraySumCircularC(vector<int>& A) {
    if(A.size() == 0) return 0;
    vector<int> maxV;
    vector<int> minV;
    maxV.push_back(A[0]);
    minV.push_back(A[0]);
    long size = A.size();
    int maxT =  maxV[0];
    int minT = minV[0];
    int sum = A[0];
    for (int i = 1; i < size; i ++) {
        sum += A[i];
        int a =  max(maxV[i-1]+A[i],A[i]);
        maxV.push_back(a);
        if(a > maxT) maxT = a;
        int b = min(minV[i-1]+A[i],A[i]);
        minV.push_back(b);
        if(b < minT) minT = b;
    }
    if(maxT<0) return maxT;
    return max(maxT,sum - minT);
}



