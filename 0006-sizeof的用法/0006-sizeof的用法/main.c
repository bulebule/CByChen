//
//  main.c
//  0006-sizeof的用法
//
//  Created by pg on 16/2/26.
//  Copyright (c) 2016年 chen. All rights reserved.
//

#include <stdio.h>

void testOne();
void testTwo();
void testThree();
void testFour();
void testFive();

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
//    testOne();
//    testTwo();
//    testThree();
//    testFour();
    testFive();
    
    return 0;
}
#pragma char类型
void testOne()
{
    printf("%lu\n",sizeof(char));          // 1
    printf("%lu\n",sizeof(unsigned char)); // 1
    printf("%lu",sizeof(signed char));     // 1
}
#pragma 基本类型
void testTwo()
{
    printf("%lu\n",sizeof(int));            // 4
    printf("%lu\n",sizeof(unsigned int));   // 4
    printf("%lu\n",sizeof(short int));      // 2
    printf("%lu\n",sizeof(unsigned short)); // 2
    printf("%lu\n",sizeof(long int));       // 8
    printf("%lu\n",sizeof(unsigned long));  // 8
    printf("%lu\n",sizeof(float));          // 4
    printf("%lu\n",sizeof(double));         // 8
    printf("%lu",sizeof(long double));      // 16
}
#pragma 数组
void testThree()
{
    char a[8];
    int b[6];
    printf("%lu\n",sizeof(a)); // 8
    printf("%lu",sizeof(b));   // 24
}
#pragma 常数
void testFour()
{
    printf("%lu\n",sizeof(8));    // 4
    printf("%lu\n",sizeof(8.8));  // 8
    printf("%lu\n",sizeof("ab")); // 3
    // 自动转化为数组类型，
    // 长度是4，不是3，因为加上了最后的'\n'符
    // 有资料说，会自动转化为指针类型(Linux为4)
    // 可能和操作系统与编译器有关系
}
#pragma union和struct
void testFive()
{
    union u{
        char c;
        double d;
    }mu;
    
    printf("%lu\n",sizeof(mu)); // 8
    printf("%lu,%lu",sizeof(mu.c),sizeof(mu.d)); // 1,8
    
    struct a{
        char b;
        double x;
    }a;
    printf("%lu",sizeof(a)); // 16
    /*
        这是因为编译器在考虑对齐问题,在结构中插入空位以控制各成员对象的地址对齐。
        但如果全对齐的话，sizeof(a) = 16, 这是因为b被放到偏移量为0的地址，占1个字节；
        在存放x时，double类型长度为8，需要放到能被8整除的偏移量上，这时候需要补7个空字节，
        达到8个，这时候偏移量为8，放上x后长度为16
     
        在Linux中,所有的结构成员都要放在被4整除的地址(Linux的存放方式)，这里补3个字节
     */
}

































