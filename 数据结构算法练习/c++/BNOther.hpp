//
//  BNOther.hpp
//  数据结构算法练习
//
//  Created by zengbailiang on 2019/4/6.
//  Copyright © 2019年 zengbailiang. All rights reserved.
//

#ifndef BNOther_hpp
#define BNOther_hpp

#include <stdio.h>
#include "stack"
#include <limits.h>
using namespace std;
class BNOther {
public:
    BNOther ()
    {
        min = INT_MAX;
    }
private:
    /*
     155. 最小栈
     设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。
     
     push(x) -- 将元素 x 推入栈中。
     pop() -- 删除栈顶的元素。
     top() -- 获取栈顶元素。
     getMin() -- 检索栈中的最小元素。
     示例:
     
     MinStack minStack = new MinStack();
     minStack.push(-2);
     minStack.push(0);
     minStack.push(-3);
     minStack.getMin();   --> 返回 -3.
     minStack.pop();
     minStack.top();      --> 返回 0.
     minStack.getMin();   --> 返回 -2.
     
     */
    stack<int> data;
    int min;
    void push(int x) {
        if(x <= min)
        {
            //弹入上次的最小值（存在两个，所以当出栈的时候，判断如果是栈顶等于最小值，那么需要出栈两次，一次是栈顶，还有就是这个多余的用来记录上一次最小值的元素，并赋值给min）
            data.push(min);
            min = x;
        }
        //在弹出当前值
        data.push(x);
    }
    void pop() {
       if(data.top() == min)
       {
           ///虽然弹出了两次，但对外部是不可见的。外部看来就是栈的正常弹出
           //弹出栈顶，最小值，唯一元素。
           data.pop();
           min = data.top();
           //弹出当前最小值副本。
           data.pop();
       }
        else
        {
         //非最小值，正常弹出
            data.pop();
        }
    }
    
    int top() {
        if (!data.empty()) {
            return data.top();
        }
        return -1;
    }
    
    int getMin() {
        return min;
    }
};
#endif /* BNOther_hpp */

