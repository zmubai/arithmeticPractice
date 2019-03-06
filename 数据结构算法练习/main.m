//
//  main.m
//  数据结构算法练习
//
//  Created by zengbailiang on 2019/3/4.
//  Copyright © 2019年 zengbailiang. All rights reserved.
//

#import <Foundation/Foundation.h>
#include "BNString.h"
#include <limits.h>
#include "BNArray.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        NSLog(@"Hello, World!");
      int res =  myAtoi("-2147483647");
        printf("%d\n",res);
        char *s = malloc(sizeof(char) * 20);
        itoa(-12345, s);
        
//        int bit = sizeof(int) / 2;
//        long size = INT_MAX / bit == 0 ? INT_MAX / bit : INT_MAX / bit + 1;
//        int *bitmap =  malloc(sizeof(int) *size);
//        printf("%d\n",res);
//        printf("%d\n",res);
        int a[] = {1,2,2,1};
        int b[] = {2,2};
        int size = 1;
        intersection(&a, 4, &b,2, &size);
    }
    return 0;
}
