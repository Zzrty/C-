#include "queue.h"
 
void queueinit(que* ps)
{
	assert(ps);
	ps->head = NULL;
	ps->tail = NULL;
	ps->size = 0;
}
 
void queuepush(que* ps, qtypedata x)
{
	assert(ps);
 
	qnode* newnode = (qnode*)malloc(sizeof(qnode));		//入队，创建一个新结点
	if (newnode == NULL){
		perror("malloc fail");
		exit(-1);
	}	
	newnode->a = x;	//将x赋值入结点的数据域
	newnode->next = NULL;	//结点指针域指向空作为尾结点，队列为尾插
 
	if (ps->tail == NULL)	//判断是否为第一个结点，若是直接头尾指针指向，反之进行尾插链接
	{
		ps->head=ps->tail= newnode;
	}
	else
	{
		ps->tail->next = newnode;
		ps->tail = newnode;
	}
	ps->size++;	//队列长度++
}
 
void queuepop(que* ps)
{
	assert(ps);
	assert(!queueempty(ps));
	if (ps->head->next==NULL)	//判断是否为第一个结点，若是直接释放并指向空，否则进行头出链接
	{
		free(ps->head);
		ps->head = ps->tail = NULL;
	}
	else
	{
		qnode* del = ps->head->next;
		free(ps->head);
		ps->head = del;
	}
	ps->size--;	//队列长度--
 
}
 
void queuedestory(que* ps)
{
	assert(ps);
 
	qnode* cur1 = ps->head;
	while (cur1)	//遍历队列链表进行队列的销毁
	{
		qnode* cur2 = cur1->next;
		free(cur1);
		cur1 = cur2;
	}
	ps->head = ps->tail = NULL;	//头尾指针指向空
	ps->size = 0;		//队列长度为0
}
 
qtypedata queuehead(que* ps)
{
	assert(ps);
	assert(!queueempty(ps));
	return ps->head->a;	//返回队头元素
}
 
qtypedata queuetail(que* ps)
{
	assert(ps);
	return ps->tail->a;	//返回队尾元素
}
 
bool queueempty(que* ps)	
{
	assert(ps);
	return ps->head == NULL;	//判断队头指针是否为空，若是空返回0，反之返回1
}
 
int queuesize(que* ps)
{
	assert(ps);
	return ps->size;	//返回队列长度
}