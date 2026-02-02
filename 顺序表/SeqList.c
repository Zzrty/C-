/*
 * @Author: Zzrty 3485797290@qq.com
 * @Date: 2026-02-01 13:08:04
 * @LastEditors: Zzrty 3485797290@qq.com
 * @LastEditTime: 2026-02-01 13:31:04
 * @FilePath: \数据结构模板\顺序表\SeqList.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "SeqList.h"
 
void SLinit(SL* s)
{
	s->arr = (SLdatatype*)malloc(sizeof(SLdatatype) * 10);	//开辟空间	
	s->size = 0;
	s->capacity = 10;
}
 
void SLdestory(SL* s)
{
	free(s->arr);	//释放空间
	s->arr = NULL;	//防止野指针，要将其指向空
	s->size = 0;
	s->capacity = 0;
}
 
void checksizecapactiy(SL* s)
{
    if (s->size == s->capacity)
    {
        SLdatatype* tmp = (SLdatatype*)realloc(s->arr, 
            s->capacity * 2 * sizeof(SLdatatype));
        if (tmp == NULL) {
            perror("realloc failed");
            exit(EXIT_FAILURE);
        }
        s->arr = tmp;
        s->capacity *= 2;
    }
}
 
void SLpushback(SL* s, SLdatatype x)
{
	checksizecapactiy(s);	//尾插前进行容量检查
	s->arr[s->size] = x;
	s->size++;
}
 
void SLpopback(SL* s)
{
	assert(s->size > 0);	//通过断言函数接口去判断边界非法情况
	s->size--;
}
 
void SLpushfront(SL* s, SLdatatype x)
{
	checksizecapactiy(s);	//头插前进行容量检查
	for (int i = s->size - 1; i >= 0; i--)	//全部元素统一后移一位
	{
		int j = i + 1;
		s->arr[j] = s->arr[i];
	}
	s->arr[0] = x;
	s->size++;
}
 
void SLpopfront(SL* s)
{
	assert(s->size > 0);	//通过断言函数接口去判断边界非法情况
	for (int i = 1; i < s->size; i++)	//全部元素统一前移一位
	{
		int j = i - 1;
		s->arr[j] = s->arr[i];
	}
	s->size--;
}
 
int SLfind(SL* s, SLdatatype x)
{
    for (int i = 0; i < s->size; i++)
    {
        if (s->arr[i] == x)
        {
            return i;
        }
    }
    return -1;
}
 
void SLinsert(SL* s, int pos, SLdatatype x)
{
    assert(pos >= 0 && pos <= s->size);
    checksizecapactiy(s);
    for (int i = s->size; i > pos; i--)
    {
        s->arr[i] = s->arr[i-1];
    }
    s->arr[pos] = x;
    s->size++;
}
 
void SLerase(SL* s, int pos)
{
	for (int i = pos + 1; i < s->size; i++)	//将删除元素后面的元素全部向前移动一位
	{
		int j = i - 1;
		s->arr[j] = s->arr[i];
	}
	s->size--;
}
 
void SLmodify(SL* s, int pos, SLdatatype x)
{
	assert(pos >= 0 && pos < s->size);	//通过断言函数接口去判断边界非法情况
	s->arr[pos] = x;
}