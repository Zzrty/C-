#include "stack.h"
 
void STinit(ST* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->capacity=0;
	ps->top = 0;
}
 
void STdestory(ST* ps)
{
	assert(ps);
	free(ps->a);	//释放栈空间
	ps->a = NULL;	//将栈指针赋为空
	ps->capacity = ps->top = 0;
}
 
void STpush(ST* ps, STtypedata x)
{
	assert(ps);
	if (ps->top == ps->capacity)	//判断是否栈满
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		STtypedata* tmp = (STtypedata*)realloc(ps->a, sizeof(STtypedata) * newcapacity);	//扩容
		if (tmp == NULL)
		{
			perror("relloc fail");
			exit(-1);
		}
		ps->a = tmp;	//将栈指针指向扩容空间首地址
		ps->capacity = newcapacity;	//修改容量为新容量大小
	}
	ps->a[ps->top] = x;	//入栈
	ps->top++;	//栈顶计数++
}
 
void STpop(ST* ps)
{
	assert(ps);
	assert(ps->top > 0);
	ps->top--;	//栈顶计数--，出栈
}
 
STtypedata STtop(ST* ps)
{
	assert(ps);
	return ps->a[ps->top - 1];	//返回栈顶元素
}
 
int STsize(ST* ps)
{
	assert(ps);
	return ps->top;	//返回栈顶长度，即元素个数
}
 
bool STempty(ST* ps)
{
	assert(ps);
	if (ps->top == 0)	//判断栈是否为空
	{
		return true;
	}
	return false;
}