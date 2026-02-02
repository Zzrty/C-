#ifndef _DBELIST_H_
#define _DBELIST_H_
//#define _CRT_SECURE_NO_WARNINGS -1	//该行代码需要注意自己编译器环境配置要求
 
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include<string.h>
#include<time.h>
#include<math.h>
 
typedef int Dbedatatype;
typedef struct Dbelist {
	Dbedatatype data;		//结点数据域
	struct Dbelist* next;	//后指针
	struct Dbelist* prev;	//前指针
}LTNode;
 
LTNode* buylistnode(Dbedatatype x);	//创建一个数据域为x的新结点
LTNode* LTlist();	//双向链表的初始化
void LTprint(LTNode* phead);	//遍历整个双向链表
void LTpushback(LTNode *phead,Dbedatatype x);	//尾插
void LTpopback(LTNode* phead);	//尾删
void LTpushfront(LTNode* phead, Dbedatatype x);	//头插
void LTpopfront(LTNode* phead);	//头删
int LTsize(LTNode* phead);	//双向链表的长度
LTNode* LTfind(LTNode* phead, Dbedatatype x);	//查找双向链表中元素值为x的结点
void LTinsertpos(LTNode* pos, Dbedatatype x);	//在双向链表中的指定pos结点位置插入结点
void LTerasepos(LTNode* pos);	//删除双向链表指定pos结点位置的结点
void LTdestory(LTNode* phead);		//双向链表的销毁

#endif //_DBELIST_H_