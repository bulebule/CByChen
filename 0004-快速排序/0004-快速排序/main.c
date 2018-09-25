//
//  main.c
//  0004-快速排序
//
//  Created by pg on 15/12/16.
//  Copyright (c) 2015年 chen. All rights reserved.
//

#include <stdio.h>

#define kInt 1

// 快速排序,从小到大
void mSort(int *a,int left,int right);
// 测试
void test(int *a);

static int count;

int main(int argc, const char * argv[]) {
    
    int a[] = {7,6,4,8,3,9,5};
    test(a);
    mSort(a, 0, sizeof(a)/sizeof(a[0])-1);
    printf("排序次数:%d\n",count);
    printf("数组个数:%ld\n",sizeof(a)/sizeof(a[0]));
    for(int i=0;i<sizeof(a)/sizeof(a[0]);i++)
        printf("%d ",a[i]);
    return 0;
}
// 选定一个基数,然后将小于它的放左边,大于它的放右边
void mSort(int *a,int left,int right)
{
    if(left >= right) // 如果左边大于或者等于右边的索引就代表已经整理完成一个组了
        return;
    
    int i = left;
    int j = right;
    int key = a[i];
    
    while (i<j)
    {
        while (i<j && key<a[j])
        {
            j--;
            count++;
        }
        if(i < j)
            a[i++] = a[j];
        
        while (i<j && key>=a[i])
        {
            i++;
            count++;
        }
        if(i < j)
            a[j--] = a[i];
    }
    a[i] = key;
    mSort(a, left, i-1);
    mSort(a, i+1, right);
}

void test(int *a)
{
    int i=0;
    int key = a[i]; // 改变i的值,key的值不会改变
    printf("Test:%d\n",key);
    i=4;
    printf("Test:%d\n",key);
    
    int j=1;
    int m = a[j++]; // 先执行a[j],再执行j++
    printf("Test:%d,%d\n",m,j);
}





