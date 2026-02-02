#ifndef __SLISTNODE_H__
#define __SLISTNODE_H__
//#define _CRT_SECURE_NO_WARNINGS -1	//该行代码需要注意自己编译器环境配置要求
 
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include<string.h>
#include<time.h>
#include<math.h>
 
/*
typedef struct ElemType{
	//...
}ET;
*/
 
//单向链表
typedef int elemtype;
typedef struct SListNode{
	elemtype data;	//复合数据类型：ET data;
	struct SListNode *next;
}SLNode,*linklist;
 
SLNode* SLNode_Init();    //链表的初始化（创建头结点）
SLNode* SLNode_BuyListNode(elemtype x);    //动态申请一个结点
void SLNode_Print(SLNode *L);    //单链表打印
void SLNode_PushBack(SLNode *L,elemtype x);    //单链表尾插
void SLNode_PushFront(SLNode *L,elemtype x);    //单链表头插
void SLNode_PopBack(SLNode *L);    //单链表尾删
void SLNode_PopFront(SLNode *L);    //单链表头删
int SLNode_Find(SLNode *L,elemtype x);    //单链表查找
void SLNode_InsertPos(SLNode *L,elemtype x,int pos);    //单链表在pos位置之后插入x
void SLNode_DeletePos(SLNode *L,int pos);    //单链表删除pos位置之后的值
 

void SLNode_Recycling(SLNode *L)    //使单链表循环化
{
	if(L==NULL)
	{
		perror("链表不存在");
		return;
	}
	if(L->next==NULL)
	{
		L->next=L;
		return;
	}
	SLNode*cur=L;
	while(cur->next!=NULL)
	{
		cur=cur->next;
	}
	cur->next=L;
}

#endif // __SLISTNODE_H__
