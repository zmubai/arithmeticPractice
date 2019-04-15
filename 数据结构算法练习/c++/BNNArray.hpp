//
//  BNNArray.hpp
//  数据结构算法练习
//
//  Created by zengbailiang on 2019/3/25.
//  Copyright © 2019年 zengbailiang. All rights reserved.
//

#ifndef BNNArray_hpp
#define BNNArray_hpp

#include <stdio.h>
#include <vector>
///命名空间 default using namespace std;
/*
 为了解决C++标准库中的标识符与程序中的全局标识符之间以及不同库中的标识符之间的同名冲突，应该将不同库的标识符在不同的命名空间中定义(或声明)。标准C++库的所有的标识符都是在一个名为std的命名空间中定义的，或者说标准头文件(如iostream)中函数、类、对象和类模板是在命名空间 std中定义的。std是standard(标准)的缩写，表示这是存放标准库的有关内容的命名空间，含义请楚，不必死记。
 这样，在程序中用到C++标准库时，需要使用std作为限定。如
 std::cout<<”OK．”<
 */
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums);
};
#endif /* BNNArray_hpp */

