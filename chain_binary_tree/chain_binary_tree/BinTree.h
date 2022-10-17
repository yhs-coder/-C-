#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>


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

