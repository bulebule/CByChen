//
//  main.c
//  0002-冒泡排序
//
//  Created by pg on 15/12/16.
//  Copyright (c) 2015年 chen. All rights reserved.
//

#include <stdio.h>
#define KSIZE 8

static int count;

// 冒泡排序
void bubble_sort(int a[],int n);

int main(int argc, const char * argv[]) {
    
    int number[KSIZE] = {1,2,3,4,5,6,7,8};
    int i;
    bubble_sort(number, KSIZE);
    printf("排序次数:%d\n",count);
    for (i=0; i<KSIZE; i++) {
        printf("%d ",number[i]);
    }
    
    return 0;
}

void bubble_sort(int a[],int n)
{
    int i,j,temp;
    
    for (j = 0; j<n-1; j++)
        for (i=0; i<n-j-1; i++)
            if (a[i] < a[i+1]) { // 从大到小
                temp   = a[i];
                a[i]   = a[i+1];
                a[i+1] = temp;
                count++;
            }
}












































