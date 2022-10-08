#define _CRT_SECURE_NO_WARNINGS
#include"List.h"

LTNode* ListInit()
{
	//创建一个哨兵位的头节点
	LTNode* phead = (LTNode*)malloc(sizeof(LTNode));
	assert(phead);
	phead->next = phead;
	phead->prev = phead;
	return phead;

}

void ListPrint(LTNode* phead)
{
	assert(phead);
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

LTNode* BuyListNode(SLDataType x)
{
	LTNode* newNode = (LTNode*)malloc(sizeof(LTNode));
	assert(newNode);
	newNode->data = x;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}

void ListPushBack(LTNode* phead, SLDataType x)
{
	assert(phead);
	
	//LTNode* newNode = BuyListNode(x);
	//LTNode* tail = phead->prev;
	
	////尾插一个新节点
	
	// phead  tail  newNode
	//tail->next = newNode;
	//newNode->prev = tail;

	////新节点链接哨兵位头节点
	//newNode->next = phead;
	//phead->prev = newNode;

	ListInsert(phead,x);
	
}

void ListPushFront(LTNode* phead, SLDataType x)
{
	assert(phead);
	//LTNode* newNode = BuyListNode(x);
	//LTNode* next = phead->next;

	//newNode->next = next;
	//next->prev = newNode;
	
	//phead->next = newNode;
	//newNode->prev = phead;
	ListInsert(phead->next, x);

}

void ListPopBack(LTNode* phead)
{
	assert(phead);
	//链表为空时，不能删除了
	assert(phead->next != phead);
	//LTNode* tail = phead->prev;
	//LTNode* tailPrev = tail->prev;
	//free(tail);
	//tailPrev->next = phead;
	//phead->prev = tailPrev;
	ListEase(phead->prev);

}

void ListPopFront(LTNode* phead)
{
	assert(phead);
	//链表为空
	assert(phead->next != phead);

	//LTNode* next = phead->  next;
	//LTNode* nextNext = next->next;
	//free(next);
	//phead->next = nextNext;
	//nextNext->prev = phead;
	ListEase(phead->next);

}

LTNode* ListFind(LTNode* phead, SLDataType x)
{
	assert(phead);
	LTNode* pos = phead->next;
	while (pos != phead)
	{
		if (pos->data == x)
		{
			return pos;
		}
		pos = pos->next;
	}
	return NULL;
}

void ListInsert(LTNode* pos, SLDataType x)
{
	
	assert(pos);
	LTNode* newNode = BuyListNode(x);
	LTNode* posPrev = pos->prev;


	//posPrev  newNode  pos
	posPrev->next = newNode;
	newNode->prev = posPrev;

	newNode->next = pos;
	pos->prev = newNode;
}

void ListEase(LTNode* pos)
{
	assert(pos);
	LTNode* posPrev = pos->prev;
	LTNode* posNext = pos->next;

	free(pos);
	pos = NULL;
	posPrev->next = posNext;
	posNext->prev = posPrev;

}

void ListDestroy(LTNode* phead)
{
	assert(phead);
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		LTNode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(phead);
	phead=NULL;

}
