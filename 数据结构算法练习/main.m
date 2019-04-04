//
//  main.m
//  数据结构算法练习
//
//  Created by zengbailiang on 2019/3/4.
//  Copyright © 2019年 zengbailiang. All rights reserved.
//

#import <Foundation/Foundation.h>
#include <limits.h>
#include "BNArray.h"
#include "BNDyPlan.h"
#include "BNDynamicPlanning.h"
#import "BNTest.h"
#import "BNCString.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        [BNTest test];
        // insert code here...
        int res =  myAtoi("-2147483647");
        printf("%d\n",res);
        char *s = malloc(sizeof(char) * 20);
        itoa(-12345, s);
//        int bit = sizeof(int) / 2;
//        long size = INT_MAX / bit == 0 ? INT_MAX / bit : INT_MAX / bit + 1;
//        int *bitmap =  malloc(sizeof(int) *size);
//        printf("%d\n",res);
//        printf("%d\n",res);
        //======
//        int a[] = {1,2,2,1};
//        int b[] = {2,2};
//        int size = 1;
//        intersection(&a, 4, &b,2, &size);
        //======
//        int x = climbStairs(3);
        //======
//        int a[] = {10,9,2,5,3,7,101,18};
//        int a[] =  {18,55,66,2,3,54};
        int a[] = {3,5,6,2,5,4,19,5,6,7,12};
        int len = lengthOfLIS1(a, 10);
        
    }
    return 0;
}
