#define _CRT_SECURE_NO_WARNINGS
#include"BinTree.h"
#include"Queue.h"

//先序遍历： 根 左子树 右子树
void BinaryPrevOrder(BTNode* root)
{
	//每次访问结点，都先序遍历一遍
	//直至遇到左右子树为空时，才返回

	//可采用递归方法实现
	//逆向思考结束的条件，重复的操作
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	printf("%c ", root->data);
	BinaryPrevOrder(root->left);
	BinaryPrevOrder(root->right);
}

void BinaryInOrder(BTNode* root)
{
	if (root == NULL)
	{
		//printf("NULL ");
		return;
	}
	BinaryInOrder(root->left);
	printf("%c ", root->data);
	BinaryInOrder(root->right);
}

void BinaryPostOrder(BTNode* root)
{
	if (root == NULL)
	{
		//printf("NULL ");
		return;
	}
	BinaryPostOrder(root->left);
	BinaryPostOrder(root->right);
	printf("%c ", root->data);
}

void BinaryLevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q); //初始化队列
	if (root != NULL)
	{
		QueuePush(&q, root);
	}

	//队列不为空时，循环继续
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);	//先读取队头的元素
		//QueuePop(&q);//再删除对头元素

		printf("%c ", front->data);//打印出队的元素

		//如果队头结点的左右孩子不为空，则依次进队
		if (front->left)
		{
			QueuePush(&q, front->left);
		}
		if (front->right)
		{
			QueuePush(&q, front->right);
		}

		QueuePop(&q);//再删除对头元素
	}
	QueueDestroy(&q);//销毁队列

}

int BinaryTreeNum(BTNode* root)
{
	//计算结点的个数，可以将其分解为计算 左子树+右子树+根结点（自身） 的个数
	//每次递归，都是将其看成一棵树，来计算其  左子树+右子树+根结点 的个数
	//递归结束：直至结点为空，返回个数0
	
	// 
	//if (root == 0)
	//{
	//	return  0;
	//}
	return root==NULL? 0 : BinaryTreeNum(root->left) + BinaryTreeNum(root->right) + 1;
}

int BinaryTreeLeafNum(BTNode* root)
{
	/*
	* 思路：
	*（1）叶子结点个数=左子树的叶子结点个数+右子树的叶子结点个数
	 （2）两种情况：
		1.如果结点为空，叶子结点个数返回0
		2.若结点的左子树和右子树为空，则返回叶子结点
	 （3）实现：使用递归实现，依次去递归结点左右子树，判断是否为叶子结点，是则返回个数1
	*/
	if (root == NULL)
		return 0;

	//是叶子结点就返回1
	if (root->left == NULL && root->right == NULL)
		return 1;

	return  BinaryTreeLeafNum(root->left)+BinaryTreeLeafNum(root->right);
}