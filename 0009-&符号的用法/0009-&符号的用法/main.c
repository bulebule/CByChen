//
//  main.c
//  0009-&符号的用法
//
//  Created by pg on 16/5/31.
//  Copyright (c) 2016年 chen. All rights reserved.
//

#include <stdio.h>

int method(int a);

int main(int argc, const char * argv[]) {
    
    int a[5] = {1,2,3,4,5};
    int *p = (int *)(&a+1);
    // a 是数组的首地址
    // &a 是存数组的地址 +1 就是加 5(根据数组定义的大小而定)
    printf("%p ,%p\n",a,&a+1); // 因为int占4个字节,所以地址相差 5*4 = 20
    
    printf("%d",*(p-2)); // *(p-2) 相当于 a[5-2]
    
    printf("\ncount = %d",method(4095));
    
    return 0;
}
// 8888 的 二进制 10001010111000
/*
    10001010111000
    10001010110111 &之后 10001010110000 ＝ 8880, count = 1
 */

// 只需要检测a的二进制中有多少1,count＝1的个数
int method(int a)
{
    int count = 0;
    while (a) {
        count++;
        a = a & (a-1);
    }
    return count;
}