#include "SListNode.h"

SLNode* SLNode_Init() 
{
    SLNode* newNode = (SLNode*)malloc(sizeof(SLNode));    //创建头结点，若无头结点的单向链表，后续操作将会涉及到双指针
    if (!newNode) {
        perror("链表初始化失败");
        return NULL;
    }
    newNode->next = NULL;
    return newNode;
}

SLNode* SLNode_BuyListNode(elemtype x)
{
    SLNode* newNode = (SLNode*)malloc(sizeof(SLNode));
    if(newNode == NULL){
        perror("申请节点失败");
        return NULL;  
    }	
    newNode->data = x;    //将申请结点的数据直接放入结点的数据域中
    newNode->next = NULL;	
    return newNode;    //返回该节点进行后续的前后链接操作
}

void SLNode_Print(SLNode *L)
{
    if(L == NULL){
        perror("链表不存在");
        return;
    }
    
    if(L->next == NULL){
        printf("链表为空\n");
        return;
    }    //非法情况判断
    
    SLNode *cur = L->next;        //指向头结点的下一个数据结点
    while(cur != NULL)    //遍历单向链表数据域
    {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

void SLNode_PushBack(SLNode *L, elemtype x)
{
    if(L == NULL){
        perror("链表不存在");
        return;
    }
    
    SLNode *cur = L;
    while(cur->next != NULL)
    {
        cur = cur->next;
    }
    SLNode* tmpNode = SLNode_BuyListNode(x);    //调用动态申请结点的函数接口，并返回一个临时节点
    cur->next = tmpNode;     //尾指针结点的指针域指向该结点，使该结点成为尾结点
}

void SLNode_PushFront(SLNode *L, elemtype x)
{
    if(L == NULL){
        perror("链表不存在");
        return;
    }
    
    SLNode* tmpNode = SLNode_BuyListNode(x);	
    //将该结点的指针域指向此刻头结点的下一个结点，再将头结点的指针域指向该结点
    tmpNode->next = L->next;
    L->next = tmpNode;
}

void SLNode_PopBack(SLNode *L)
{
    if(L == NULL || L->next == NULL)
    {
        perror("链表为空");
        return;  // 修正：返回类型是void，不应该返回0
    }    //非法情况判断
    
    SLNode *cur = L->next;        //遍历到链表的尾结点指针
    SLNode *pre = L;    //遍历到链表的倒数第二个结点指针
    
    while(cur->next != NULL){
        pre = cur;
        cur = cur->next;
    }    //循环遍历，指针后移
    
    free(cur);        //释放cur指针所指向的尾结点，实现尾删
    cur = NULL;
    pre->next = NULL;    //上一个结点指针指向空，成为尾结点
}

void SLNode_PopFront(SLNode *L)
{
    if(L == NULL || L->next == NULL)
    {
        perror("链表为空");
        return;  //返回类型是void，不应该返回0
    }    //非法情况判断
    
    SLNode *cur = L->next;        //指向待删除的第一个头数据结点
    L->next = cur->next;    //头结点指针指向头数据结点的下一个结点
    free(cur);        //释放cur指针所指向的头数据结点
    cur = NULL;
}

int SLNode_Find(SLNode *L, elemtype x)
{
    if(L == NULL || L->next == NULL){
        return -1;
    }
    
    SLNode* cur = L->next;        //遍历结点的指针
    int cntNode = 0;    //记录结点的个数
    while(cur != NULL)
    {
        if(cur->data == x)    //遍历判断查找
        {
            return cntNode;
        }
        cur = cur->next;
        cntNode++;
    }
    return -1;
}

void SLNode_InsertPos(SLNode *L, elemtype x, int pos)
{
    if(L == NULL){
        perror("链表不存在");
        return;
    }
    
    if(pos < 1)    //合法性判断
        return;
    
    // 如果链表为空，插入到第一个位置
    if(L->next == NULL){
        if(pos == 1){
            SLNode_PushFront(L, x);
        }
        return;
    }
    
    SLNode *cnt_cur = L->next;
    int cnt = 0;
    while(cnt_cur != NULL)
    {
        cnt_cur = cnt_cur->next;
        cnt++;
    }
    
    if(pos > cnt + 1)    //如果pos的值大于此刻链表中的结点个数+1，则直接插入到表尾
        pos = cnt + 1;
    
    if(pos == 1){
        SLNode_PushFront(L, x);
        return;
    }
    
    SLNode* tmpNode = SLNode_BuyListNode(x);
    SLNode* pre = L;
    SLNode* cur = L->next;
    for(int i = 1; i < pos; i++)
    {
        pre = cur;
        cur = cur->next;
    }
    pre->next = tmpNode;
    tmpNode->next = cur;
}

void SLNode_DeletePos(SLNode *L, int pos)
{
    if(L == NULL || L->next == NULL){
        perror("链表为空");
        return;
    }
    
    if(pos < 1)    //合法性判断
        return;
    
    SLNode *cnt_cur = L->next;
    int cnt = 0;
    while(cnt_cur != NULL)
    {
        cnt_cur = cnt_cur->next;
        cnt++;
    }
    if(pos > cnt)    //如果pos的值大于此刻链表中的结点个数，则直接默认删除表尾结点
        pos = cnt;
    
    if(pos == 1){
        SLNode_PopFront(L);
        return;
    }
    
    SLNode* pre = L;
    SLNode* cur = L->next;
    for(int i = 1; i < pos; i++)
    {
        pre = cur;
        cur = cur->next;
    }
    pre->next = cur->next;
    free(cur);
    cur = NULL;
}