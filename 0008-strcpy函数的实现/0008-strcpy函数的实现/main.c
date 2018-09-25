//
//  main.c
//  0008-strcpy函数的实现
//
//  Created by pg on 16/5/20.
//  Copyright (c) 2016年 chen. All rights reserved.
//

#include <stdio.h>
#include <string.h>

char *myStrcpy(char *p1, const char *p2);

int main(int argc, const char * argv[]) {
    
    char s1[32] = "woshishui-wahaha";
    char s2[32] = "";
    
    myStrcpy(s2, s1);
    printf("s1:%s\ns2:%s\n",s1,s2);
    
    return 0;
}

char *myStrcpy(char *p1, const char *p2)
{
    while (*p2) {
        *p1 = *p2;
        p1++;
        p2++;
    }
    return p1;
}