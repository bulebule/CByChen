//
//  main.c
//  0011-输入字符串大写转小写
//
//  Created by pg on 16/7/22.
//  Copyright © 2016年 chen. All rights reserved.
//

#include <stdio.h>

int func(char *s);

int main(int argc, const char * argv[]) {
    
    char a[512];
    printf("请输入字符串:");
    scanf("%s",a);
    int i = func(a);
    printf("大写字母的个数:%d\n",i);
    
    return 0;
}

int func(char *s)
{
    int count = 0;
    char *p = s;
    while (*p) {
        if (*p>='A' && *p<='Z') {
            *p += 32;
            count++;
        }
        p++;
    }
    
    return count;
}
