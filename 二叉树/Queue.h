/*
 * @Author: Zzrty 3485797290@qq.com
 * @Date: 2026-02-01 13:42:35
 * @LastEditors: Zzrty 3485797290@qq.com
 * @LastEditTime: 2026-02-01 13:57:42
 * @FilePath: \数据结构模板\二叉树\Queue.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef __QUEUE_H__
#define __QUEUE_H__
//#define _CRT_SECURE_NO_WARNINGS -1	//该行代码需要注意自己编译器环境配置要求
 
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include<string.h>
#include<time.h>
#include<math.h>
 
/*
typedef struct binarytreenode{
	struct binarytreenode *Lchild;
	struct binarytreenode *Rchild;
	elemtype data;
}btnode;
typedef  btnode* qtypedata;  //二叉树层序遍历，对队列的简单改造
*/
 
typedef int qtypedata; 
typedef struct queuenode {
	struct queuenode* next;
	qtypedata a;
}qnode;	//队列中的结点

typedef struct queue {
	qnode* head;		//队头指针
	qnode* tail;		//队尾指针
	int size;		//队列长度
}que;	
 
void queueinit(que *ps);	//队列的初始化
void queuepush(que* ps,qtypedata x);	//入队
void queuepop(que* ps);	//出队
void queuedestory(que* ps);	//队列的销毁
qtypedata queuehead(que* ps);	//拿到队头元素
qtypedata queuetail(que* ps);	//拿到队尾元素
bool queueempty(que* ps);		//判断队列是否为空
int queuesize(que* ps);		//队列的长度

#endif // __QUEUE_H__