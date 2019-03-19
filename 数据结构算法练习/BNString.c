//
//  BNString.c
//  数据结构算法练习
//
//  Created by zengbailiang on 2019/3/4.
//  Copyright © 2019年 zengbailiang. All rights reserved.
//

#include "BNString.h"
#include <limits.h>
/*请你来实现一个 atoi 函数，使其能将字符串转换成整数。*/
int myAtoi(char* str) {
    int sign = 0;
    long res = 0;
    int i;
    for(i = 0; *(str + i) != '\0'; i ++)
    {
        int x = *(str + i);
        //跳过空格
        if (!isspace(x)) {
            if(x == '-')
            {
                sign = -1;
                i ++;
            }
            else if(x == '+')
            {
                sign = 1;
                i ++;
            }
            else if ( '0' <= x && x <= '9')
            {
                sign = 1;
            }
            else
            {
                return 0;
            }
            break;
        }
    }
    
    for (int j = i; *(str + j) != '\0'; j++) {
        int x = *(str + j);
        if('0' <= x && x <= '9')
        {
            res = res * 10 + (x - '0');
            if((sign == 1 && res >= INT_MAX) || (sign == -1 && sign * res <= INT_MIN))
                return sign == 1  ? INT_MAX : INT_MIN;
        }
        else
        {
            //遇到异常字符弹出
            break;
        }
    }
    return (int)(sign * res);
}


void itoa (int n ,char s[])
{
    int flag = 1;
    if(n < 0)
    {
        flag = -1;
        //绝对值
        n = -1 * n;
    }
    int i = 0;
    do {
        s[i] = n % 10 + '0';
        n = n / 10;
        //结束的时候多加了一
        i ++;
    } while (n > 0);
    if(flag == -1) printf("%c",'-');
    for (int j = i - 1; j >= 0; j --) {
        printf("%c",s[j]);
    }
}

///====
//leetcode3. 无重复字符的最长子串
int lengthOfLongestSubstring(char* s) {
    if(*s == NULL) return 0;
    if(*s == '\0') return 1;
    
    int max = 1;
    int si = 0;//startIndex
    for(int i = 0; *(s+i) != '\0';i++)
    {
        for(int j = si;j < i ; j ++)
        {
            if(*(s+j) == *(s+i))
            {
                if(j - si + 1 > max) max = j - si + 1;
                ///重复的下标的下一个坐标作为新起点。
                si = j + 1;
                break;
            }
            
            if( j == i-1 && i-si+1 > max)
            {
                
                max = i- si +1;
                // printf("i=%ld,max=%ld\n",i,max);
            }
            else if(j-si+1 > max)
            {
                max = j- si +1;
            }
        }
    }
    return max;
}
