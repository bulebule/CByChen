//
//  main.c
//  0003-最大公约数算法
//
//  Created by pg on 15/12/16.
//  Copyright (c) 2015年 chen. All rights reserved.
//

#include <stdio.h>
#include <assert.h>

// 辗转相除法、欧几里德算法(最大公约数)
int method_one(int a,int b);
// 更相减损法
int method_two(int a,int b);

int main(int argc, const char * argv[]) {
    
    int a,b;
    printf("请输入两个正整数:");
    scanf("%d %d",&a,&b);
//    assert(a == b);
    printf("%d和%d的最大公约数为:%d AND %d",a,b,method_one(a,b),method_two(a, b));
    
    return 0;
}

int method_one(int a,int b)
{
    int temp;
    if (a<b) { // 交换
        temp = a;
        a = b;
        b = temp;
    }
    while (b!=0) {
        temp = a%b;
        a = b;
        b = temp;
    }
    return a;
}

int method_two(int a,int b)
{
    int temp;
    
    while (a) {
        if (a < b) {
            temp = a;
            a = b;
            b = temp;
        }
        a = a-b;
    }
    return b;
}

















