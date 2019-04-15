//
//  BNArray.c
//  数据结构算法练习
//
//  Created by zengbailiang on 2019/3/5.
//  Copyright © 2019年 zengbailiang. All rights reserved.
//

#include "BNArray.h"
#include <limits.h>
#include <string.h>
int length()
{
    return 2;
}

int location (int n )
{
    return  n * 2 % sizeof(int);
}

int idx(int n)
{
    return n * 2 / sizeof(int);
}

//[1,2,2,1]
//[2,2]
//数组交集 位图不可取。 为了兼容int的范围，太浪费空间，不实际。
int* Test_intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    ///bit map  00不存在 01存在  11 已经打印
    ////  1111
    int bit = sizeof(int) / 2;
    long size = INT_MAX / bit == 0 ? INT_MAX / bit : INT_MAX / bit + 1;//10亿
    int *bitMap = (int*)malloc(sizeof(int) * size);//占用4个G空间。 1g约等于8亿bit
    memset(bitMap, 0, sizeof(int) * size);
    for (int i = 0; i < nums1Size; i ++) {
        int x =  *nums1 + i;
        int id = idx(x);
        int dest = *(bitMap + id);
        if (location(x) == 0) {
            *(bitMap + idx(x)) = (dest & 7);
        }
        else if(location(x) == 2)
        {
            *(bitMap + idx(x)) = (dest & 13);
        }
    }
    
    int *items = (int*)malloc(sizeof(int) * nums1Size);
    int index = 0;
    for (int i = 0; i < nums2Size; i ++) {
        int x =  *nums1 + i;
        int id = idx(x);
        int dest = *(bitMap + id);
        if (location(x) == 0 && ((dest & 12) == 4)) {
            *(items + index++) = x;
        }
        else if(location(x) == 2 && ((dest & 3) == 1))
        {
            *(items + index++) = x;
        }
    }
    return items;
}

#pragma mark -
///切分
int partition(int *num, int left,int right)
{
    int x = *(num + left);
    int left_index = left;
    ///向上补偿1，为了程序的正确性
    int right_index = right + 1;
    
    ///循环查找并交换元素
    while (1) {
        ///左向右扫描
        while(*(num + ++left_index) < x)
        {
            if(left_index == right) break;
        }
        ///右向左扫描
        while (*(num + --right_index) >= x) {
            if(right_index == left) break;
        }
        
        ///扫描结束，如果下标是非法退出
        if(left_index >= right_index)
        {
            break;
        }
        
        int tmep = *(num + right_index);
        *(num + right_index) = *(num + left_index);
        *(num + left_index) = tmep;
    }
    
    int tmep = *(num + right_index);
    *(num + right_index) = x;
    *(num + left) = tmep;
    ///返回切分位置
    return right_index;
}
///快速排序
void quickSort(int *num,int left,int right)
{
    if(left >= right)
    {
        return;
    }
    int p = partition(num, left, right);
    quickSort(num,left,p - 1);
    quickSort(num, p + 1, right);
}

///特别注意returnSize为返回的数组的size，因为是c的原因
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize)
{
    ///健壮性处理 判断非法输入等等
    ///...省略
    if(nums2Size == 0 || nums1Size == 0 || nums1 == NULL || nums2 == NULL)
    {
        int *res = malloc(sizeof(int) *0);
        return res;
    }
    
    ///处理阶段
    /*
     int a[] = {1,5,3,7};
     int b[] = {6,4,2,8};
     */
    quickSort(nums1,0,nums1Size -1);///11223 ==?123
    quickSort(nums2,0,nums2Size -1);///11223
    printf("%d",*returnSize);
    int *res = (int *)malloc(sizeof(int)* (nums1Size < nums2Size ? nums1Size : nums2Size));
    memset(res, 0, sizeof(int)* 10);
    ///两路归并
    int res_index = -1;
    int num1_index = 0;
    int num2_index = 0;
    while (num1_index < nums1Size && num2_index < nums2Size) {
        int x1 = *(nums1 + num1_index);
        int x2 = *(nums2 + num2_index);
        if(x1 == x2)
        {
            ///如果不是相同的可以加入
            if((res_index >=0 && *(res + res_index) != x1) || res_index == -1)
            {
                *(res + ++res_index) = x1;
            }
            num1_index ++;
            num2_index ++;
        }
        else if(x1 > x2)
        {
            num2_index ++;
        }
        else
        {
            num1_index ++;
        }
    }
    *returnSize = res_index + 1;
    return res;
}




