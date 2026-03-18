#ifndef _CYCLICLIST_H_
#define _CYCLICLIST_H_
#include <stdio.h>
#include <stdlib.h>

typedef int CyclicDataType;
typedef struct CyclicListNode {
    CyclicDataType data; // 结点数据域
    struct CyclicListNode* next; 
} CyclicListNode;

typedef struct Cyclic
{
    CyclicListNode* head; // 循环链表头指针
    CyclicListNode* tail; // 循环链表尾指针
    int size; // 循环链表的长度
}CyclicList;
CyclicList* createCyclicList(); // 创建循环链表
CyclicListNode* buyCyclicListNode(CyclicDataType x); // 创建一个数据域为x的新结点
void printCyclicList(CyclicList* list); // 遍历整个循环链表
int TailInsertCyclicList(CyclicList* list, CyclicDataType x); // 尾插法
int HeadInsertCyclicList(CyclicList* list, CyclicDataType x); // 头插法
int InsertCyclicList(CyclicList* list, int pos, CyclicDataType x); // 任意位置插入
int DeleteCyclicList(CyclicList* list, int pos); // 删除指定位置的结点
int GetCyclicList(CyclicList* list, int pos, CyclicDataType* x); // 获取指定位置的结点数据
int LocateCyclicList(CyclicList* list, CyclicDataType x); // 查找值为x的结点位置
void DestroyCyclicList(CyclicList* list); // 销毁循环链表

#endif