#define _CRT_SECURE_NO_WARNINGS
#include"BinTree.h"
#include"Queue.h"

//��������� �� ������ ������
void BinaryPrevOrder(BTNode* root)
{
	//ÿ�η��ʽ�㣬���������һ��
	//ֱ��������������Ϊ��ʱ���ŷ���

	//�ɲ��õݹ鷽��ʵ��
	//����˼���������������ظ��Ĳ���
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
	QueueInit(&q); //��ʼ������
	if (root != NULL)
	{
		QueuePush(&q, root);
	}

	//���в�Ϊ��ʱ��ѭ������
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);	//�ȶ�ȡ��ͷ��Ԫ��
		//QueuePop(&q);//��ɾ����ͷԪ��

		printf("%c ", front->data);//��ӡ���ӵ�Ԫ��

		//�����ͷ�������Һ��Ӳ�Ϊ�գ������ν���
		if (front->left)
		{
			QueuePush(&q, front->left);
		}
		if (front->right)
		{
			QueuePush(&q, front->right);
		}

		QueuePop(&q);//��ɾ����ͷԪ��
	}
	QueueDestroy(&q);//���ٶ���

}

int BinaryTreeNum(BTNode* root)
{
	//������ĸ��������Խ���ֽ�Ϊ���� ������+������+����㣨���� �ĸ���
	//ÿ�εݹ飬���ǽ��俴��һ��������������  ������+������+����� �ĸ���
	//�ݹ������ֱ�����Ϊ�գ����ظ���0
	
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
	* ˼·��
	*��1��Ҷ�ӽ�����=��������Ҷ�ӽ�����+��������Ҷ�ӽ�����
	 ��2�����������
		1.������Ϊ�գ�Ҷ�ӽ���������0
		2.��������������������Ϊ�գ��򷵻�Ҷ�ӽ��
	 ��3��ʵ�֣�ʹ�õݹ�ʵ�֣�����ȥ�ݹ��������������ж��Ƿ�ΪҶ�ӽ�㣬���򷵻ظ���1
	*/
	if (root == NULL)
		return 0;

	//��Ҷ�ӽ��ͷ���1
	if (root->left == NULL && root->right == NULL)
		return 1;

	return  BinaryTreeLeafNum(root->left)+BinaryTreeLeafNum(root->right);
}