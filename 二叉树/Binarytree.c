#include "binarytree.h"
#include "Queue.h"

btnode* buynewnode(btdatatype x)
{
    btnode* node = (btnode*)malloc(sizeof(btnode));
    if (node == NULL)
    {
        perror("malloc fail");
        exit(-1);
    }
    node->val = x;
    node->leftchild = NULL;
    node->rightchild = NULL;
    return node;
}

// 前序遍历
void pretraversal(btnode* root)
{
    if (root == NULL)
    {
        printf("NULL ");
        return;
    }
    printf("%d ", root->val);
    pretraversal(root->leftchild);
    pretraversal(root->rightchild);
}

// 中序遍历（修正）
void intraversal(btnode* root)
{
    if (root == NULL)
    {
        printf("NULL ");
        return;
    }
    intraversal(root->leftchild);     // 调用自身
    printf("%d ", root->val);
    intraversal(root->rightchild);     // 调用自身
}

// 后序遍历（修正）
void aftertraversal(btnode* root)
{
    if (root == NULL)
    {
        printf("NULL ");
        return;
    }
    aftertraversal(root->leftchild);  
    aftertraversal(root->rightchild);  
    printf("%d ", root->val);
}

int treesize(btnode* root)
{
    if (root == NULL){
        return 0;
    }
    return treesize(root->leftchild) + treesize(root->rightchild) + 1;
}

// 计算叶子节点数（修正）
int treeleafsize(btnode* root)
{
    if (root == NULL){
        return 0;
    }
    // 叶子节点：左右子节点都为空
    if (root->leftchild == NULL && root->rightchild == NULL){
        return 1;
    }
    return treeleafsize(root->leftchild) + treeleafsize(root->rightchild);
}

int treeklevel(btnode* root, int level)
{
    assert(level > 0);
    if (root == NULL) {
        return 0;
    }
    if (level == 1){
        return 1;
    }
    return treeklevel(root->leftchild, level-1) + treeklevel(root->rightchild, level-1);
}

void treedestory(btnode* root)
{
    if (root == NULL)
    {
        return;
    }
    treedestory(root->leftchild);
    treedestory(root->rightchild);
    free(root);
}

// 查找节点（优化版）
btnode* treefind(btnode* root, int x)
{
    if (root == NULL)
        return NULL;
    
    if (root->val == x)
        return root;
    
    // 先在左子树查找
    btnode* leftResult = treefind(root->leftchild, x);
    if (leftResult != NULL)
        return leftResult;
    
    // 左子树没找到再查找右子树
    return treefind(root->rightchild, x);
}

void levelorder(btnode* root)
{
    que q;
    queueinit(&q);
    if (root)
        queuepush(&q, root);
    
    while (!queueempty(&q))
    {
        btnode* front = queuehead(&q);
        printf("%d ", front->val);
        
        if (front->leftchild)
            queuepush(&q, front->leftchild);
        if (front->rightchild)
            queuepush(&q, front->rightchild);
        
        queuepop(&q);
    }
    printf("\n");
    queuedestory(&q);
}

bool treecomplete(btnode* root)
{
    que q;
    queueinit(&q);
    bool meetNull = false;  // 标记是否遇到空节点
    
    if (root)
        queuepush(&q, root);
    
    while (!queueempty(&q))
    {
        btnode* front = queuehead(&q);
        queuepop(&q);
        
        if (front == NULL) {
            meetNull = true;  // 遇到第一个空节点
        } else {
            // 如果已经遇到过空节点，又遇到非空节点，则不是完全二叉树
            if (meetNull) {
                queuedestory(&q);
                return false;
            }
            // 无论子节点是否为空都入队
            queuepush(&q, front->leftchild);
            queuepush(&q, front->rightchild);
        }
    }
    
    queuedestory(&q);
    return true;
}

// 辅助函数：返回最大值
static int max(int a, int b)
{
    return a > b ? a : b;
}

int treehigh(btnode* root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftHeight = treehigh(root->leftchild);
    int rightHeight = treehigh(root->rightchild);
    return max(leftHeight, rightHeight) + 1;
}