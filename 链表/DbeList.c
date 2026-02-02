#include "DbeList.h"

#define default 0

// 创建节点
LTNode* buylistnode(Dbedatatype x)
{
    LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
    if (newnode == NULL)
    {
        perror("malloc fail");
        exit(-1);
    }
    newnode->data = x;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}

// 初始化链表
LTNode* LTlist()
{
    LTNode* phead = buylistnode(default);  //传入默认值
    phead->next = phead;
    phead->prev = phead;
    return phead;
}

// 打印链表
void LTprint(LTNode* phead)
{
    assert(phead);
    printf("phead");
    LTNode* cur = phead->next;
    while (cur != phead)  //判断是否回到头节点
    {
        printf("<->%d", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

// 尾插
void LTpushback(LTNode* phead, Dbedatatype x)
{
    assert(phead);
    LTNode* newnode = buylistnode(x);
    LTNode* tail = phead->prev;
    
    tail->next = newnode;
    newnode->prev = tail;
    newnode->next = phead;
    phead->prev = newnode;
}

// 尾删
void LTpopback(LTNode* phead)
{
    assert(phead);
    assert(phead->next != phead);
    
    LTNode* tail = phead->prev;
    LTNode* newtail = tail->prev;
    
    newtail->next = phead;
    phead->prev = newtail;
    
    free(tail);
    // tail = NULL;  // 局部变量，不需要置NULL
}

// 头插
void LTpushfront(LTNode* phead, Dbedatatype x)
{
    assert(phead);
    LTNode* newnode = buylistnode(x);
    LTNode* headnext = phead->next;
    
    phead->next = newnode;
    newnode->prev = phead;
    newnode->next = headnext;
    headnext->prev = newnode;
}

// 头删
void LTpopfront(LTNode* phead)
{
    assert(phead);
    assert(phead->next != phead);
    
    LTNode* headnext = phead->next;
    LTNode* nextnode = headnext->next;  // 保存下一个节点
    
    phead->next = nextnode;
    nextnode->prev = phead;  // 设置后继节点的prev指针
    
    free(headnext);
    // headnext = NULL;  // 局部变量，不需要置NULL
}

// 获取链表大小
int LTsize(LTNode* phead)
{
    assert(phead);
    LTNode* cur = phead->next;
    int cnt = 0;
    while (cur != phead)
    {
        cnt++;
        cur = cur->next;
    }
    return cnt;
}

// 查找节点
LTNode* LTfind(LTNode* phead, Dbedatatype x)
{
    assert(phead);
    LTNode* cur = phead->next;
    while (cur != phead)  //判断是否回到头节点
    {
        if (cur->data == x)
            return cur;
        cur = cur->next;
    }
    return NULL;
}

// 在pos位置前插入
void LTinsertpos(LTNode* pos, Dbedatatype x)
{
    assert(pos);
    LTNode* posprev = pos->prev;
    LTNode* newnode = buylistnode(x);
    
    posprev->next = newnode;
    newnode->prev = posprev;
    newnode->next = pos;
    pos->prev = newnode;
}

// 删除pos位置节点
void LTerasepos(LTNode* pos)
{
    assert(pos);
    // 注意：不能删除头节点（如果pos是头节点）
    LTNode* posprev = pos->prev;
    LTNode* posnext = pos->next;
    
    posprev->next = posnext;
    posnext->prev = posprev;
    
    free(pos);
    // pos = NULL;  // 局部变量，不需要置NULL
}

// 销毁链表
void LTdestory(LTNode* phead)
{
    assert(phead);
    LTNode* cur = phead->next;
    while (cur != phead)  // 修改：判断是否回到头节点
    {
        LTNode* next = cur->next;
        free(cur);
        cur = next;
    }
    free(phead);
    // phead = NULL;  // 局部变量，无法修改外部指针
    // 需手动将指针置为NULL
}