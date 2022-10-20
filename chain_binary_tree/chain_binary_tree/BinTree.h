#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<stdbool.h>


typedef char BTDataType;  //结点中存储的元素类型

//链式二叉树的结点类型定义
typedef struct BTNode
{
	BTDataType data;//树节点中存储的值
	struct BTNode* left; //左指针域（指向左孩子）
	struct BTNode* right;//右指针域（指向有孩子）
}BTNode;

//先序遍历
void BinaryPrevOrder(BTNode* root);

//中序遍历
void BinaryInOrder(BTNode* root);

//后序遍历
void BinaryPostOrder(BTNode* root);

//层序遍历
void BinaryLevelOrder(BTNode* root);

//结点的个数
int BinaryTreeNum(BTNode* root);

//叶子结点的个数
int BinaryTreeLeafNum(BTNode* root);

//相对于根结点，第k层结点的个数
int BinaryTreeKLevelNum(BTNode* root, int k);

//查找值为x的结点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);

//树的最大深度
int BinaryTreeMaxDepth(BTNode* root);

//翻转二叉树
BTNode* invertTree(BTNode* root);

//判断两棵二叉树是否为相同
bool isSameTree(BTNode* p, BTNode* q);

//判断二叉树是否为完全二叉树
bool isCompleteTree(BTNode* root);

//判断二叉树是否是单值二叉树
bool isUnivalTree(BTNode* root);


//判断二叉树是否是对称二叉树
bool isSymmetricTree(BTNode* root);

//判断二叉树是否是平衡二叉树
bool isBalancedTree(BTNode* root);

//判断二叉树是否是另一棵二叉树的子树
bool isSubtree(BTNode* root, BTNode* subRoot);

//二叉树的销毁
void BinaryTreeDestroy(BTNode* root);