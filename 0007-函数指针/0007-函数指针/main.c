//
//  main.c
//  0007-函数指针
//
//  Created by pg on 16/5/12.
//  Copyright (c) 2016年 chen. All rights reserved.
//

#include <stdio.h>

#include <unistd.h>

// 函数指针声明方法:
// 返回值类型 (* 指针变量名)([形参列表]);
// 指向函数的变量
// 作用:调用函数和作为函数的参数
int max(int x,int y)
{
    printf("调用max\n");
    return x-y;
};

int func(int a)
{
    return a*a;
};
// 等待一段时间之后再执行max()方法
int method(int (*a)(int, int))
{
    printf("休眠开始\n");
    sleep(3);
    printf("休眠结束\n");
    int p = (*a)(10, 2);
    
    return p;
}

int main(int argc, const char * argv[]) {
    
    int (*p)(int, int);
    int a,b,c,d;
    p = max; // p就是函数指针
    scanf("%d%d",&a,&b);
    c = (*p)(a,b);
    
    d = func(p(a,b)); // 作为函数的参数
    
    printf("a=%d,b=%d,c=%d,d=%d\n",a,b,c,d);
    
    int e = method(p);
    printf("e = %d\n",e);
    
    return 0;
}

// int func(int x); // 声明一个函数
// int (*f)(int x); // 声明一个函数指针
// f = func;











































