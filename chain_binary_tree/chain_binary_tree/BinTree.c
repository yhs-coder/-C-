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
	return root == NULL ? 0 : BinaryTreeNum(root->left) + BinaryTreeNum(root->right) + 1;
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

	return  BinaryTreeLeafNum(root->left) + BinaryTreeLeafNum(root->right);
}


int BinaryTreeKLevelNum(BTNode* root, int k)
{
	if (k < 1 || root == NULL) //空树或者k值不合法！
		return 0;

	if (k == 1)//第一层结点
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
	return Max(BinaryTreeMaxDepth(root->left), BinaryTreeMaxDepth(root->right)) + 1;

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

//bool isCompleteTree(BTNode* root)
//{
//	/*该怎么判断一棵树是完全二叉树呢？？
//		要知道完全二叉树中结点的顺序是连续的，当出现一个结点为空，但它的下一个结点不为空时，就可以判断出这树不是完全二树！
//		思路：类似于层序遍历，借助队列进出结点
//		1.首先根节点进队
//		2.读取队头的结点，让其左右孩子进队后，队头结点再出队
//		3.重复第二步操作，直至队列为空
//		4.检查队列的剩余值，当队列中全为空，则为完全二叉树，如果出现非空结点，则不是完全二叉树
//	*/
//	Queue q;
//	QueueInit(&q);
//	if (root != NULL)
//		QueuePush(&q, root);//根结点进队
//
//	while (!QueueEmpty(&q))//队列不为空时，循环继续
//	{
//		BTNode* front = QueueFront(&q);//读取队头元素
//		QueuePop(&q); //删除队头元素
//
//		if (front == NULL)//当读取到空结点时，停止入队操作
//			break;
//		QueuePush(&q, front->left);
//		QueuePush(&q, front->right);
//		//QueuePop(&q); //删除对头元素
//
//	}
//	while (!QueueEmpty(&q))//读取队列中剩余的元素
//	{
//		BTNode* front = QueueFront(&q);
//		QueuePop(&q);
//		if (front != NULL)
//		{
//			QueueDestroy(&q); //销毁队列
//			return false;
//		}
//	}
//	QueueDestroy(&q);//销毁队列
//	return true;
//	//结点进队出队时，怎么判断队列为空？当结点为空时，又怎么判断下一个结点是否为空
//
//}

bool isCompleteTree(BTNode* root)
{
	/*
	思路（借助一个队列）：
 1.根先入队列，然后开始从队头出数据。
 2.出队头的数据，然后让其左孩子和右孩子依次入队列（NULL也入队列）。
 3.重复进行步骤2，直到读取到的队头元素为NULL时停止入队列。
 4.检查队列中剩余数据，若全为NULL，则是完全二叉树；若其中有一个非空的数据，则不是完全二叉树。
	*/

	Queue q;
	QueueInit(&q);
	if (root != NULL) //不为空树，插入根结点
		QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);//读取队头的元素

		QueuePop(&q); //删除队头数据

		//判断出队元素是否为空NULL
		if (front == NULL)//当遇到空结点时，停止入队操作
			break;
		
		//让队头的左、右孩子入队列
		QueuePush(&q, front->left);
		QueuePush(&q, front->right);
	}

	
	//读取队列中剩余元素
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		//此时的front是上面NULL空结点的下一个元素
		QueuePop(&q);

		
		if (front != NULL) //读取到非空结点，说明不是完全二叉树！
		{
			QueueDestroy(&q);//销毁队列
			return false;
		}
	}

	//队列中全为空结点,说明二叉树为完全二叉树！
	QueueDestroy(&q);//销毁队列
	return true;
}


bool isUnivalTree(BTNode* root)
{
	/*
		单值二叉树
		思路：（分而治之）
		1.将问题分解为：依次比较 根与左子树的值、根与右子树的值
		2.进一步比较 （以根的左子树为）根的结点与其左子树的值、 （以根的右子树为)根的结点与右子树的值
		3.递归比较，
		4.结束条件：当结点为空时返回true,；当根与左子树的值不同时，返回false
	*/

	if (root == NULL)//根为空时，结点全都为NULL，是单值二叉树
		return true;
	if (root->left && root->data != root->left->data)//左孩子存在，但左孩子的值不等于根的值
		return false;
	if (root->right && root->data != root->right->data)////右孩子存在，但右孩子的值不等于根的值
		return true;

	//依次比较根与左右子树的值
	//当左右子树都为单值二叉树，此树便为单值二叉树！
	return isUnivalTree(root->left) && isUnivalTree(root->right);
}

//判断镜像位置是否相等
bool travel(BTNode* left, BTNode* right)
{
	if (left == NULL && right == NULL)//左右子树同时遍历到NULL,返回true
		return true;

	if (left == NULL || right == NULL) //如果左右子树中，一个为NULL,另一个不为NULL,即镜像不相等！
		return false;
	
	if (left->data != right->data) //如果左右子树的结点值不同，即镜像不相等！
		return false;

	//递归调用！
	//子问题：左子树遍历，如先左后右；则右子树相反方向遍历，即先右后左。
	//如果两次都遍历比较成功，则是对称二叉树
	/*			A
			B		B
		C		E		C
	D		F		F		D
	*/
	return travel(left->left, right->right) && travel(left->right, right->left);
}
bool isSymmetricTree(BTNode* root)
{
	/*
		对称二叉树，对称是指镜像对称

		比较根的左右子树是否为镜像对称，镜像对称则左右子树镜像位置的值是相同的。
		//每次计较左右子树镜像位置的值，若不同，则此树不为对称二叉树

	*/

	if (root == NULL)//空树也是对称二叉树
		return true;
	return travel(root->left, root->right);//判断左右子树的镜像位置是否相等！
}




bool _isBlancedtree(BTNode* root, int* ph)
{
	if (root == NULL)
	{
		*ph = 0; //空树高度返回0
		return true;
	}
	//先判断左子树是不是平衡二叉树
	int leftHight = 0;
	if (_isBlancedtree(root->left, &leftHight) == false)
		return false;

	//再判断右子树是不是平衡二叉树
	int rightHight = 0;
	if (_isBlancedtree(root->right, &rightHight) == false)
		return false;

	//把左右子树的高度中的较大值+1，作为当前树的高度返回给上一层
	*ph = Max(leftHight, rightHight) + 1;

	return abs(leftHight - rightHight) < 2;//平衡二叉树的条件

}

bool isBalancedTree(BTNode* root)
{
	/*
		平衡二叉树：若一棵二叉树的每个结点的左右两个子树的高度差的绝对值不超过1，则称该树为平衡二叉树。

	*/
	
	/*
		思路一： 时间复杂度为 O(N^2)
		分治处理：每次分解成子问题
		1.求出左子树的深度。
 		2.求出右子树的深度。
 		3.若左子树与右子树的深度差的绝对值不超过1，并且左右子树也是平衡二叉树，则该树是平衡二叉树。
	*/
	//if (root == NULL) //空树是平衡二叉树！
	//	return true;
	//int leftDepth=BinaryTreeMaxDepth(root->left);//求左子树的深度
	//int rightDepth=BinaryTreeMaxDepth(root->right);//求右子树的深度

	////左右子树的高度差的绝对值不超过1 &&左子树得是平衡二叉树&&右子树也得是平衡二叉树
	//return abs(leftDepth - rightDepth) < 2 && isBalancedTree(root->left) && isBalancedTree(root->right);


	/*
		思路2：采用后续遍历
		1.从叶子结点处开始计算每课子树的高度。（每棵子树的高度 = 左右子树中高度的较大值 + 1）
 		2.先判断左子树是否是平衡二叉树。
 		3.再判断右子树是否是平衡二叉树。
 		4.若左右子树均为平衡二叉树，则返回当前子树的高度给上一层，继续判断上一层的子树是否是平衡二叉树，直到判断到根为止。（若判断过程中，某一棵子树不是平衡二叉树，则该树也就不是平衡二叉树了）

	*/
	int hight = 0;
	return _isBlancedtree(root, &hight);
}

void BinaryTreeDestroy(BTNode* root)
{
	//采用后序，一边遍历一边销毁
	if (root == NULL)
		return;
	BinaryTreeDestroy(root->left);//销毁左子树
	BinaryTreeDestroy(root->right);//销毁右子树
	free(root);//释放根节点
	root = NULL;
}