//
//  main.c
//  0014-栈
//
//  Created by pg on 2017/3/17.
//  Copyright © 2017年 chen. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // 使用bool类型


/*
    ------栈-----
    1、只要栈的剩余空间大于所申请空间,系统将为程序提供内存,否则将报异常提示栈溢出
    2、栈是向低地址扩展的数据结构,是一块连续的内存区域.栈的最大容量是系统预先规定好的
    3、由系统自动分配,速度快,但是程序员无法控制
    4、LIFO (后进先出)
 */

#pragma mark - 链式栈

typedef int StackType;
typedef struct Node {
    StackType data;
    struct Node *next;
}Node,*PNode;

typedef struct Stack {
    PNode top; // 栈顶结点
    int count; //
}Stack,*PStack;

#pragma mark - 栈定义
// 初始化操作,建立一个空栈s
void initStack(PStack s) {
    // 创建一个空结点,让top指向它
    s->top = (PNode)malloc(sizeof(Node));
    if (NULL != s->top) {
        // 清空空结点的指针域
        s->top->next = NULL;
        s->count = 0;
    }
    else {
        printf("内存分配失败!程序退出!\n");
        exit(-1);
    }
}
// 若栈存在,插入新元素e
void push(PStack s,StackType e) {
    // 动态创建一个新结点
    PNode item = (PNode)malloc(sizeof(Node));
    // 设置新结点的数据域值
    if (item == NULL) {
        perror("push malloc faul");
    }
    item->data = e;
    // 将新结点的指针域指向之前建的空结点
    item->next = s->top;
    // top指向新结点
    s->top = item;
    s->count++;
}
// 遍历栈
void traverse(PStack s) {
    PNode item = s->top;
    int count = s->count;
    while (item != NULL) {
        printf("%d:%d\n",count--,item->data);
        item = item->next;
        
    }
    printf("\n");
}
// 判断栈是否为空
bool isEmptyStack(PStack s) {
    if (s->count == 0 && s->top->next==NULL) {
        return true;
    }
    else
        return false;
}
// 删除栈s中栈顶元素
bool pop(PStack s,StackType *e) {
    if (isEmptyStack(s)) {
        printf("pop stack is empty");
        return false;
    }
    
    PNode item = s->top;
    *e = item->data;
    s->top = item->next;
    free(item);
    item = NULL;
    s->count--;
    return true;
}
// 将栈清空
void clearStack(PStack s) {
    if (isEmptyStack(s))
        return;
    
    PNode p1 = s->top; // 定义元素p1指向栈顶元素
    PNode p2 = NULL; // 定义元素p2,初始值为空
    while (!isEmptyStack(s)) {
        p2 = p1->next; // p2指向p1的下一个元素
        free(p1);
        s->count--;
        p1 = p2;
    }
    s->top->next = NULL;
}

// 若栈存在,则销毁它
// 若栈不为空,返回s的栈顶元素e
// 返回栈s的元素个数

int main(int argc, const char * argv[]) {
    
    Stack s;
    initStack(&s);
    
    printf("是否为空:%d\n",isEmptyStack(&s));
    
    push(&s, 19);
    push(&s, 23);
    push(&s, 54);
    push(&s, 89);
    push(&s, 45);
    
    printf("是否为空:%d\n",isEmptyStack(&s));
    
    traverse(&s);
    
    int val;
    if (pop(&s, &val)) {
        printf("出栈成功,出栈的元素是%d\n",val);
    }
    else
        printf("出栈失败");
    
    traverse(&s);
    
    if (pop(&s, &val)) {
        printf("出栈成功,出栈的元素是%d\n",val);
    }
    else
        printf("出栈失败");
    
    traverse(&s);
    
    clearStack(&s);
    printf("是否为空:%d\n",isEmptyStack(&s));
    
    return 0;
}
