//
//  main.c
//  0001-线性链表
//
//  Created by pg on 15/12/16.
//  Copyright (c) 2015年 chen. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct grade{
    int score;
    struct grade *next;
};
typedef struct grade NODE;

// 创建链表
struct grade *create();
// 插入数据,i为插入位置
void mInsert(NODE *head,NODE *pnew,int i);
// 删除数据
void mDelete(NODE *head,int i);
// 输出链表
void mDisplay(NODE *head);
// 销毁链表
void mFree(NODE *head);

#pragma mark - main函数
int main(int argc, const char * argv[]) {
    
    struct grade *head,*pnew;
    head = create();
    if (head == NULL) {
        return 0;
    }
    printf("第一次输出创建的链表:");
    mDisplay(head);
    
    pnew = malloc(sizeof(NODE));
    if (pnew == NULL) {
        printf("创建pnew失败");
        return 0;
    }
    pnew->score = 88;
    mInsert(head, pnew, 3);
    printf("插入后的链表:");
    mDisplay(head);
    
    mDelete(head, 2);
    printf("删除后的链表:");
    mDisplay(head);
    
    mFree(head);
    
    return 0;
}

struct grade *create()
{
    NODE *head,*tail,*pnew;
    int score;
    
    head = malloc(sizeof(NODE)); // 创建头节点
    if (head == NULL) {
        printf("创建失败!!");
        return NULL;
    }
    head->next = NULL; // 头节点指针域置为NULL
    tail = head;       // tail指向head,
    
    printf("输入学生成绩:");
    while (1)
    {
        scanf("%d",&score);
        if (score < 0) // 成绩为负则退出循环
            break;
        pnew = malloc(sizeof(NODE));
        if (pnew == NULL) {
            printf("创建失败!!");
            return NULL;
        }
        pnew->score = score; // 新节点数据域存放输入的成绩
        pnew->next  = NULL;  // 新节点指针域置为NULL
        
        tail->next = pnew;
        tail = pnew;
    }
    
    return head; // 返回创建链表的头指针
}

void mInsert(NODE *head,NODE *pnew,int i)
{
    NODE *p;
    int j;
    p = head;
    
    for (j=0; j<i && p!=NULL; j++)
        p = p->next;
    
    if (p==NULL) {
        printf("准备插入的节点不存在");
        return;
    }
    
    pnew->next = p->next; // 插入节点的指针域指向第i个节点的后继节点
    p->next    = pnew; // 将第i个节点的指针域指向插入的新节点
}

void mDelete(NODE *head,int i)
{
    NODE *p,*q;
    int j;
    
    if (i==0) // 删除的是头指针
        return;
    p=head;
    for (j=1; j<i && p->next != NULL; j++)
        p = p->next; // 将p指向准备删除的第i个节点的前驱节点
    
    if (p->next == NULL) {
        printf("准备删除的节点不存在!");
        return;
    }
    
    q = p->next; // q指向待删除的节点
    p->next = q->next; //删除节点i,也可写成p->next=p->next->next
    
    free(q); // 释放节点i的内存单元
}

void mDisplay(NODE *head)
{
    NODE *p;
    for(p=head->next;p!=NULL;p=p->next)
        printf("%d ",p->score);
    printf("\n");
}

void mFree(NODE *head)
{
    NODE *p,*q;
    p = head;
    while(p->next != NULL)
    {
        q       = p->next;
        p->next = q->next;
        free(q);
    }
}
