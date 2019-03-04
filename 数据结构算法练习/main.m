//
//  main.m
//  数据结构算法练习
//
//  Created by zengbailiang on 2019/3/4.
//  Copyright © 2019年 zengbailiang. All rights reserved.
//

#import <Foundation/Foundation.h>
#include "BNString.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        NSLog(@"Hello, World!");
      int res =  myAtoi("-2147483647");
        printf("%d\n",res);
        char *s = malloc(sizeof(char) * 20);
        itoa(12345, s);
    }
    return 0;
}
