#define _CRT_SECURE_NO_WARNINGS

#include"SList.h"

void SListPrint(SLNode* phead)
{
	assert(phead != NULL);
	SLNode* cur = phead;
	while (cur)
	{
		printf("%d -> ", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

//����½ڵ�
SLNode* CreateListNode(SLDataType x)
{
	SLNode* newnode = (SLNode*)malloc(sizeof(SLNode));
	if (newnode == NULL)
	{
		return NULL;
	}
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}

//ʵ��β��
void SListPushBack(SLNode** phead, SLDataType x)
{

	//�������1. ����Ϊ�գ������½ڵ��ͷ�ڵ�
	//		  2. ����Ϊ�գ��ҵ���������һ���ڵ㣬ָ���½ڵ�
	SLNode* newnode = CreateListNode(x);

	if (*phead == NULL)
	{
		*phead = newnode;
	}
	else
	{
		SLNode* tail = *phead;
		while (tail->next)
		{

			tail = tail->next;
		}
		tail->next = newnode;
	}
}

void SListPushFront(SLNode** phead, SLDataType x)
{
	SLNode* newnode = CreateListNode(x);
	newnode->next = *phead;
	*phead = newnode;
}

void SListPopBack(SLNode** phead)
{

	//1. �ҵ�β�ڵ㣬��free()�ͷŵ�
	//2. Ϊ����ɾ����β�ڵ��ǰһ���ڵ㣬����һ��prevǰ���ڵ㣬��prevָ�����һ���ڵ��ÿ�

	//(2)�޽ڵ�����
	assert(*phead != NULL);
	//1. ֻ��һ���ڵ�����
	if ((*phead)->next == NULL)
	{
		free(*phead);
		*phead = NULL;
	}
	//SLNode* tail = *phead;
	//if (tail->next == NULL)
	//{
	//	//���⣺ֻʣһ���ڵ��ʱ��Ϊʲô�ȵ�ֻʣһ���ڵ��ͷ�tail��ԭ�����ڴ�ȴ�����ͷţ�����Ϊʲô�����tailȴ�����ͷ�
	//	��� *phead��ֵ����tail��tail�õ���ͷ�ڵ�ĵ�ַ��tail���Ը���ͷ�ڵ㣬�ͷ� ͷ�ڵ�ָ�����һ���ڵ㣬�����һ�����ͷ�ʱ����ָ��ͷ�ڵ�Ŀռ䱻�ͷţ�����phead��ֵû�иı䣬��Ȼָ��ͷ�ڵ�ĵ�ַ����ʱ���Ұָ�룬���phead��ֵ�������ֵ
	//	free(tail);
	//	tail = NULL;
	//}
	else
	{
		/*
			��һ�֣� ����ǰ���ڵ�
		*/

		//�������������Ͻڵ�����
		/*SLNode* tail = *phead;
		SLNode* prev = NULL;
		while (tail->next)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		tail = NULL;
		prev->next = NULL; //����Ұָ��
		*/

		/*
			�ڶ��֣��ж����������ڵ��Ƿ�Ϊ�գ������жϴ�ʱ�ڵ��Ƿ�Ϊβ�ڵ��ǰһ���ڵ�
		*/
		SLNode* tail = *phead;
		while (tail->next->next)
		{
			tail = tail->next;
		}
		free(tail->next);
		tail->next = NULL;
	}
}

void SListPopFront(SLNode** phead)
{
	assert(*phead != NULL);
	SLNode* next = (*phead)->next;
	free(*phead);
	*phead = next;
}

SLNode* SListFind(SLNode* phead, SLDataType x)
{
	SLNode* cur = phead;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

void SListInsert(SLNode** phead, SLNode* pos, SLDataType x)
{
	SLNode* newnode = CreateListNode(x);
	//posΪ��һ���ڵ� �� ����Ϊ��ʱ
	if (*phead == pos)
	{
		newnode->next = *phead;
		*phead = newnode;
	}
	else
	{
		//�ҵ�pos��ǰһ��λ��
		SLNode* posPrev = *phead;
		while (posPrev->next != pos)
		{
			posPrev = posPrev->next;
		}
		posPrev->next = newnode;
		newnode->next = pos;
	}
}


//ɾ��ָ��λ�õĽڵ�
void SListEase(SLNode** phead, SLNode* pos)
{
	assert(pos);//pos��Ϊ��
	//ɾ����һ���ڵ㣨ͷɾ��
	if (*phead == pos)
	{
		SListPopFront(phead);
	}

	//����ڵ��ɾ��
	else
	{
		SLNode* prev = *phead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = pos->next;
		free(pos);
		pos = NULL;
	}
}

void SListEaseAfter(SLNode** phead, SLNode* pos)
{
	SLNode* next = pos->next;
	pos->next = next->next;
	free(next);
}

void SListEaseAll(SLNode** phead, SLDataType x)
{
	assert(*phead);
	SLNode* cur = *phead;
	SLNode* prev = NULL;
	while (cur)
	{
		//��ͷ�ڵ㴦ɾ��
		if ((*phead)->data == x)
		{
			SListPopFront(phead);
		}
		else if(cur->data == x)
		{
			SLNode* next = cur->next;
			prev->next = next;
			free(cur);
			cur = next;
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}


	}

}


void SlistDestory(SLNode** phead)
{
	assert(phead);
	SLNode* cur = *phead;
	while (cur)
	{
		SLNode* next = cur->next;
		free(cur);
		cur = next;
	}
	//*pheadָ��ͷ�ڵ�ĵ�ַ��ΪNULL;����Ұָ��
	*phead = NULL;
}