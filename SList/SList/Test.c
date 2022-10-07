#define _CRT_SECURE_NO_WARNINGS
#include"SList.h"

void SListTest1()
{
	SLNode* s1 = (SLNode*)malloc(sizeof(SLNode));
	s1->data = 1;
	s1->next = NULL;
	SListPrint(s1);
}
// SListPushBack

void SListTest2()
{
	SLNode* sl = NULL;
	SListPushBack(&sl, 1);
	SListPushBack(&sl, 2);
	SListPushBack(&sl, 3);
	SListPushBack(&sl, 4);
	//SListPushFront(&sl, 5);
	//SListPushFront(&sl, 6);
	//SListPushFront(&sl, 7);
	//SListPushFront(&sl, 8);
	SListPrint(sl);
	//SListPopBack(&sl);
	//SListPopBack(&sl);
	//SListPopBack(&sl);
	//SListPopBack(&sl);

	SListPrint(sl);
}

void SListTest3()
{
	SLNode* sl = NULL;
	SListPushBack(&sl, 1);
	SListPushBack(&sl, 2);
	SListPushBack(&sl, 3);
	SListPushBack(&sl, 4);
	SListPrint(sl);
	SListPopFront(&sl);
	SListPopFront(&sl);
	SListPopFront(&sl);
	SListPopFront(&sl);
	SListPrint(sl);

}

void SListTest4()
{
	SLNode* sl = NULL;
	SListPushBack(&sl, 1);
	SListPushBack(&sl, 2);
	SListPushBack(&sl, 2);
	SListPushBack(&sl, 2);
	SListPushBack(&sl, 3);
	SListPushBack(&sl, 4);
	SListPrint(sl);
	SLNode* pos = SListFind(sl,2);

	//����
	int i = 1;
	while (pos)
	{
		printf("��%d��pos�ڵ㣺 %p -> %d\n", i++, pos, pos->data);
		pos = SListFind(pos->next, 2);
	}

	//�޸�
	pos = SListFind(sl, 3);
	if (pos)
	{
		pos->data = 30;
	}
	SListPrint(sl);
}


void SListTest5()
{
	SLNode* sl = NULL;
	SListPushBack(&sl, 1);
	SListPushBack(&sl, 2);
	SListPushBack(&sl, 2);
	SListPushBack(&sl, 2);
	SListPushBack(&sl, 3);
	SListPushBack(&sl, 4);
	SListPrint(sl);
	SLNode* pos = SListFind(sl, 4);
	SListInsert(&sl, pos, 40);
	SListPrint(sl);


}

void SListTest6()
{
	SLNode* sl = NULL;
	SListPushBack(&sl, 1);
	SListPushBack(&sl, 2);
	SListPushBack(&sl, 6);
	SListPushBack(&sl, 2);
	SListPushBack(&sl, 3);
	SListPushBack(&sl, 4);
	SListPrint(sl);
	SLNode* pos = SListFind(sl, 2);
	SListEase(&sl, pos);
	 pos = SListFind(sl, 3);
	SListEaseAfter(&sl, pos);
	SlistDestory(&sl); //�ͷŶ�̬���ڴ�ռ�
	SListPrint(sl);

}
void SListTest7()
{
	SLNode* sl = NULL;
	SListPushBack(&sl, 1);
	SListPushBack(&sl, 2);
	SListPushBack(&sl, 6);
	SListPushBack(&sl, 2);
	SListPushBack(&sl, 3);
	SListPushBack(&sl, 2);
	SListPrint(sl);
	SListEaseAll(&sl,2);
	SListPrint(sl);
	SlistDestory(&sl); //�ͷŶ�̬���ڴ�ռ�

}

int main()
{

	//SListTest1();
	//SListTest2();
	//SListTest3();
	//SListTest4();
	//SListTest5();
	//SListTest6();
	SListTest7();

	return 0;
}