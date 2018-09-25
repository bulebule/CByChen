//
//  main.c
//  0010-指针函数
//
//  Created by pg on 16/6/1.
//  Copyright (c) 2016年 chen. All rights reserved.
//

#include <stdio.h>

int *reverse(int *a, int length); // 将一维数组逆序

int main(int argc, const char * argv[]) {
    
    int a[] = {1,2,3,4,5,6};
    int *p;
    
    int count = sizeof(a)/sizeof(a[0]);
    p = reverse(a,count);
    // 指针函数返回一个指针,让返回值更丰富
    
    for (int i=0; i<count; i++) {
        printf("%d ",p[i]);
    }
    
    return 0;
}

int *reverse(int *a,int length)
{
    int count = length;
    int left = 0;
    int right = count - 1;
    
    int *p = a;
    
    while (right > left) {
        
        int tmp    = *(p+left);
        *(p+left)  = *(p+right);
        *(p+right) = tmp;
        
        left++;
        right--;
    }
    
    return p;
}
