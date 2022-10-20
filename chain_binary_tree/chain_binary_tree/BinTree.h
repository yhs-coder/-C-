#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<stdbool.h>


typedef char BTDataType;  //����д洢��Ԫ������

//��ʽ�������Ľ�����Ͷ���
typedef struct BTNode
{
	BTDataType data;//���ڵ��д洢��ֵ
	struct BTNode* left; //��ָ����ָ�����ӣ�
	struct BTNode* right;//��ָ����ָ���к��ӣ�
}BTNode;

//�������
void BinaryPrevOrder(BTNode* root);

//�������
void BinaryInOrder(BTNode* root);

//�������
void BinaryPostOrder(BTNode* root);

//�������
void BinaryLevelOrder(BTNode* root);

//���ĸ���
int BinaryTreeNum(BTNode* root);

//Ҷ�ӽ��ĸ���
int BinaryTreeLeafNum(BTNode* root);

//����ڸ���㣬��k����ĸ���
int BinaryTreeKLevelNum(BTNode* root, int k);

//����ֵΪx�Ľ��
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);

//����������
int BinaryTreeMaxDepth(BTNode* root);

//��ת������
BTNode* invertTree(BTNode* root);

//�ж����ö������Ƿ�Ϊ��ͬ
bool isSameTree(BTNode* p, BTNode* q);

//�ж϶������Ƿ�Ϊ��ȫ������
bool isCompleteTree(BTNode* root);

//�ж϶������Ƿ��ǵ�ֵ������
bool isUnivalTree(BTNode* root);


//�ж϶������Ƿ��ǶԳƶ�����
bool isSymmetricTree(BTNode* root);

//�ж϶������Ƿ���ƽ�������
bool isBalancedTree(BTNode* root);

//�ж϶������Ƿ�����һ�ö�����������
bool isSubtree(BTNode* root, BTNode* subRoot);

//������������
void BinaryTreeDestroy(BTNode* root);