/*
 * @Author: Zzrty 3485797290@qq.com
 * @Date: 2026-02-01 13:31:44
 * @LastEditors: Zzrty 3485797290@qq.com
 * @LastEditTime: 2026-02-01 13:55:32
 * @FilePath: \数据结构模板\栈\Stack.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @Author: Zzrty 3485797290@qq.com
 * @Date: 2026-02-01 13:31:44
 * @LastEditors: Zzrty 3485797290@qq.com
 * @LastEditTime: 2026-02-01 13:36:48
 * @FilePath: \数据结构模板\栈\Stack.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef __STACK_H__
#define __STACK_H__
//#define _CRT_SECURE_NO_WARNINGS -1	//该行代码需要注意自己编译器环境配置要求
 
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include<string.h>
#include<time.h>
#include<math.h>
 
typedef int STtypedata;
typedef struct stack {
	STtypedata* a;
	int top;	//栈顶
	int capacity;	//容量
}ST;
 
void STinit(ST *ps);		//栈的初始化
void STdestory(ST *ps);		//栈的销毁
void STpush(ST *ps,STtypedata x);	//入栈
void STpop(ST* ps);	//出栈
STtypedata STtop(ST* ps);	//取得栈顶元素
int STsize(ST* ps);		//栈中元素数量
bool STempty(ST* ps);		//判断栈是否为空

#endif //__STACK_H__