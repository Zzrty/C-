#ifndef __BINARYTREE_H__
#define __BINARYTREE_H__
//#define _CRT_SECURE_NO_WARNINGS -1	//该行代码需要注意自己编译器环境配置要求
 
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include<string.h>
#include<time.h>
#include<math.h>
 
typedef int btdatatype;
typedef struct binarytreenode {
	btdatatype val;	//数据域
	struct binarytreenode* leftchild;		//左子节点指针
	struct binarytreenode* rightchild;	//右子节点指针
}btnode;
 
btnode* buynewnode(btdatatype x);		//创建一个新结点
void pretraversal(btnode *root);		//前序遍历
void intraversal(btnode* root);	//中序遍历
void aftertraversal(btnode* root);	//后序遍历
int treesize(btnode *root);		//树中的结点个数
int treeleafsize(btnode* root);	//树中的叶子节点个数
int treeklevel(btnode* root,int level);	//树第level层结点总数
void treedestory(btnode* root);		//树的销毁
btnode* treefind(btnode* root,int x);	//查找树中的结点
void levelorder(btnode *root);		//层序遍历
bool treecomplete(btnode* root);	//判断是否为完全二叉树
int treehigh(btnode* root);		//树的高度

#endif // __BINARYTREE_H__