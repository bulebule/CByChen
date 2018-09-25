//
//  main.c
//  0005-选择排序
//
//  Created by pg on 16/2/3.
//  Copyright (c) 2016年 chen. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

// 选择排序(Selection sort)

void swap(int *a,int *b);
void select_sort(int A[],int n);

int main(int argc, const char * argv[]) {
    
    // 工作原理是每一次从待排序的数据元素中选出最小(或最大)的一个元素,存放在序列的起始位置,直到全部待排序的数据元素排完
    int A[10] = {3,7,4,2,6,1,9,8,0,5};
    select_sort(A, sizeof(A)/sizeof(A[0]));
    
    return 0;
}

void swap(int *a,int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void select_sort(int A[],int n)
{
    register int i,j,min,m;
    for (i=0; i<n-1; i++) {
        min = i;
        for (j=i+1; j<n; j++) {
            if (A[min] > A[j]) {
                min = j;
            }
        }
        if (min != i) {
            swap(&A[min], &A[i]);
            printf("第%d趟排序结果为:\n",i+1);
            for (m=0; m<n; m++) {
                if (m>0) {
                    printf(" ");
                }
                printf("%d",A[m]);
            }
            printf("\n");
        }
    }
}













































