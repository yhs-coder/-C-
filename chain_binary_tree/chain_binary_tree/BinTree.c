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


int BinaryTreeKLevelNum(BTNode* root, int k)
{
	if (k < 1 || root == NULL) //空树或者k值不合法！
		return 0;

	if (k== 1)//第一层结点
		return 1;

	//主要思路：
	//第k层结点的个数，等价于求 k-1层 根节点 的左、右子树的个数之和，而不是求k-1层下总共有多少结点！！！
	//递归每次k-1，直至k=1时，找到第k层,
	//再判断是否为空，返回相应结点个数！
	return BinaryTreeKLevelNum(root->left, k - 1) + BinaryTreeKLevelNum(root->right, k - 1);
}

//取最大值
int Max(int a, int b)
{
	return a > b ? a : b;
}
int BinaryTreeMaxDepth(BTNode* root)
{
	if (root == NULL)//空树，深度为0
		return 0;

	//树的最大深度= 左有子树中深度的较大值+1
	//之所以要加1，是因为只计算了子树的深度，没有算入根节点的深度
	return Max(BinaryTreeMaxDepth(root->left), BinaryTreeMaxDepth(root->right))+1;

}

BTNode* invertTree(BTNode* root)
{
	//翻转二叉树： 交换 根左右子树的位置

	if (root == NULL)//根为空，返回空树
		return NULL;

	//递归操作： 分治思想，分解到根结点没有左、右子树
	BTNode* left = invertTree(root->left);//翻转左子树
	BTNode* right = invertTree(root->right);//翻转右子树

	//左右子树进行交换
	root->left = right;
	root->right = left;
	return root;

}

bool isSameTree(BTNode* p, BTNode* q)
{
	/*
	* 判断两棵二叉树是否相同:
	 1.比较两棵树的根是否相同。
 	  2.比较两根的左子树是否相同。
	 3.比较两根的右子树是否相同。
	*/
	if (p == NULL && q == NULL)//两棵树都为空，则相同
		return true;
	if (p == NULL || q == NULL)	//两棵树只有一棵为空，不相同
		return false;
	if (p->data != q->data)//两棵树的值不同，返回false
		return false;
	//比较两棵树的左右子树，相同则返回true
	return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);

}

bool isCompleteTree(BTNode* root)
{


}