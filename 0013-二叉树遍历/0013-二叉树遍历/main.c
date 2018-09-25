//
//  main.c
//  0013-二叉树遍历
//
//  Created by pg on 16/11/17.
//  Copyright © 2016年 chen. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h> // 使用malloc函数

typedef char dataType;
// 链式存储
typedef struct BinNode{
    dataType data;
    struct BinNode* lchild;
    struct BinNode* rchild;
}BinNode,*bintree;

//typedef BinNode* bintree;

#pragma mark - 创建二叉树
bintree createBiTree() {
    dataType data;
    bintree T;
    // 按先序次序输入二叉树中结点的值,'#'表示空树
    scanf("%c",&data);
    if (data == '#') {
        T = NULL;
    }else {
        T = (bintree)malloc(sizeof(BinNode));
        // 生成根节点
        T->data = data;
        // 构造左子树
        T->lchild = createBiTree();
        // 构造右子树
        T->rchild = createBiTree();
    }
    return T;
}
void createBiTree_dev(bintree *T) {
    dataType data;
    scanf("%c",&data);
    if (data == '#') {
        *T = NULL;
    }else {
        *T = (bintree)malloc(sizeof(BinNode));
        if (!*T)
            exit(-1);
        
        // 生成根节点
        (*T)->data = data;
        // 构造左子树
        createBiTree_dev(&(*T)->lchild);
        // 构造右子树
        createBiTree_dev(&(*T)->rchild);
    }
}
#pragma mark - 递归算法
void visit(bintree T) {
    if (T->data != '#') {
        printf("%c",T->data);
    }
}
// 先序遍历
void preOrder(bintree T) {
    if (T != NULL) {
        // 访问根节点
        visit(T);
        // 访问左子树节点
        preOrder(T->lchild);
        // 访问右子树节点
        preOrder(T->rchild);
    }
}
// 中序遍历
void minOrder(bintree T) {
    if (T != NULL) {
        // 访问左子树节点
        minOrder(T->lchild);
        // 访问根节点
        visit(T);
        // 访问右子树节点
        minOrder(T->rchild);
    }
}
// 后序遍历
void postOrder(bintree T) {
    if (T != NULL) {
        // 访问左子树节点
        postOrder(T->lchild);
        // 访问右子树节点
        postOrder(T->rchild);
        // 访问根节点
        visit(T);
    }
}
#pragma mark - 非递归算法

#define SIZE 100
// 顺序栈存储
typedef struct seqstack{
    bintree data[SIZE];
    int tag[SIZE]; // 为后续遍历准备
    int top; // 数组下标
}seqstack;

void push(seqstack *s,bintree t) {
    if (s->top == SIZE) {
        printf("the stack is full \n");
    }else {
        s->top++;
        s->data[s->top] = t;
    }
}
bintree pop(seqstack *s) {
    if (s->top == -1) {
        return NULL;
    }else {
        s->top--;
        return s->data[s->top+1];
    }
}
// 前序遍历
void preorder_dev(bintree t) {
    seqstack s;
    s.top = -1; // -1表示数组为空
    if (!t) {
        printf("the tree is empty \n");
    }else {
        while (t || s.top!=-1) {
            while (t) { // 只要结点不为空就应该入栈保存,与其左右结点无关
                printf("%c",t->data);
                push(&s, t);
                t=t->lchild;
            }
            t=pop(&s);
            t=t->rchild;
        }
    }
}
// 中序遍历
void minorder_dev(bintree t) {
    seqstack s;
    s.top = -1;
    if (!t) {
        printf("the tree is empty \n");
    }else {
        while (t || s.top!= -1) {
            while (t) {
                push(&s, t);
                t=t->lchild;
            }
            t=pop(&s);
            printf("%c",t->data);
            t=t->rchild;
        }
    }
}
// 后序遍历
void postorder_dev(bintree T) {
    seqstack s;
    s.top = -1;
    if (!T) {
        printf("the tree is empty \n");
    }else {
        while (T || s.top != -1) {
            while (T) {
                push(&s, T);
                s.tag[s.top] = 0; // 设置访问标记,0为第一次访问,1为第二次访问
                T = T->lchild;
            }
            if (s.tag[s.top] == 0) {
                T = s.data[s.top];
                s.tag[s.top] = 1;
                T = T->rchild;
            }else {
                while (s.tag[s.top] == 1) {
                    T = pop(&s);
                    printf("%c",T->data);
                }
                T = NULL;
            }
        }
    }
}

#pragma mark - 层次遍历

#define MAX 1000
typedef struct seqqueue {
    bintree data[MAX];
    int front;
    int rear;
}seqqueue;

void enter(seqqueue *q,bintree t) {
    if (q->rear == MAX) {
        printf("the queue is full\n");
    }else {
        q->data[q->rear] = t;
        q->rear++;
    }
}
bintree del(seqqueue *q) {
    if (q->front == q->rear) {
        return NULL;
    }else {
        q->front++;
        return q->data[q->front-1];
    }
}
void level_tree(bintree t) {
    seqqueue q;
    q.front = q.rear = 0;
    if (!t) {
        printf("the tree is empty\n");
        return;
    }
    enter(&q, t);
    while (q.front != q.rear) {
        t = del(&q);
        printf("%c",t->data);
        if (t->lchild) {
            enter(&q, t->lchild);
        }
        if (t->rchild) {
            enter(&q, t->rchild);
        }
    }
}

#pragma mark - main 函数
int main(int argc, const char * argv[]) {
    
    bintree T;
    T = createBiTree();
    printf("先序遍历: ");
    preOrder(T);
    printf("\n");
    
    printf("中序遍历: ");
    minOrder(T);
    printf("\n");
    
    printf("后序遍历: ");
    postOrder(T);
    printf("\n");
    
    printf("2-先序遍历: ");
    preorder_dev(T);
    printf("\n");
    
    printf("2-中序遍历: ");
    minorder_dev(T);
    printf("\n");
    
    printf("2-后序遍历: ");
    postorder_dev(T);
    printf("\n");
    
    printf("层次遍历\n");
    level_tree(T);
    printf("\n");
    
    return 0;
}


/* 二叉树
                    A
                B       C
            D        E      F
        G      H       I
 ABDG##H###CE#I##F##
 前 : ABDGHCEIF
 中 : GDHBAEICF
 后 : GHDBIEFCA
 */




































