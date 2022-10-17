#define _CRT_SECURE_NO_WARNINGS

#include"BinTree.h"

void TestBinaryTree()
{
	BTNode* A = (BTNode*)malloc(sizeof(BTNode));
	assert(A);
	A->data = 'A';
	BTNode* B = (BTNode*)malloc(sizeof(BTNode));
	assert(B);
	B->data = 'B';
	BTNode* C = (BTNode*)malloc(sizeof(BTNode));
	assert(C);
	C->data = 'C';
	BTNode* D = (BTNode*)malloc(sizeof(BTNode));
	assert(D);
	D->data = 'D';
	BTNode* E = (BTNode*)malloc(sizeof(BTNode));
	assert(E);
	E->data = 'E';
	BTNode* F = (BTNode*)malloc(sizeof(BTNode));
	assert(F);
	F->data = 'F';
	BTNode* G = (BTNode*)malloc(sizeof(BTNode));
	assert(G);
	G->data = 'G';

	A->left = B;
	A->right = C;

	B->left = D;
	B->right = E;

	C->left = NULL;
	C->right = F;

	D->left = NULL;
	D->right = NULL;

	E->left = G;
	E->right = NULL;

	F->left = NULL;
	F->right = NULL;

	G->left = NULL;
	G->right = NULL;

	//先序遍历
	//BinaryPrevOrder(A);

	//中序遍历
	//BinaryInOrder(A);

	//后序遍历
	//BinaryPostOrder(A);

	//层序遍历
	//BinaryLevelOrder(A);

	printf("结点的个数为 %d\n", BinaryTreeNum(A));



}

int main()
{
	TestBinaryTree();
	return 0;
}