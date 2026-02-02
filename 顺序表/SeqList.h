#ifndef __SEQLIST_H__
#define __SEQLIST_H__
//#define _CRT_SECURE_NO_WARNINGS -1	//该行代码需要注意自己编译器环境配置要求
 
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include<string.h>
#include<time.h>
#include<math.h>
 
//静态顺序表
#define N 10
typedef int SLdatatype;
struct SeqList
{
	SLdatatype arr[N];	//指定顺序表空间大小
	int size;                   //记录顺序表中元素个数
};

 
//动态顺序表
typedef int SLdatatype;
typedef struct SeqList
{
	SLdatatype* arr;    //定义一个指向空间的指针，等待动态开辟顺序表空间
	int size;         //记录顺序表中元素个数
	int capacity;          //记录顺序表的容量大小
}SL;
 
void SLinit(SL* s);	//顺序表初始化
void SLdestory(SL* s);	//顺序表销毁
void checksizecapactiy(SL* s);	//检查顺序表的容量大小，容量满后继续动态扩容
void SLpushback(SL* s, SLdatatype x);	//尾插
void SLpopback(SL* s);	//尾删
void SLpushfront(SL* s, SLdatatype x);	//头插
void SLpopfront(SL* s);	//头删
int SLfind(SL* s, SLdatatype x);	//查找顺序表中指定元素所在的位置
void SLinsert(SL* s,int pos, SLdatatype x);		//往顺序表中指定位置进行插入
void SLerase(SL* s, int pos);	//删除顺序表中指定位置的元素
void SLmodify(SL* s, int pos, SLdatatype x);	//修改顺序表中指定位置的元素

#endif // __SEQLIST_H__