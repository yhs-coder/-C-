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

//添加新节点
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

//实现尾插
void SListPushBack(SLNode** phead, SLDataType x)
{

	//分情况：1. 链表为空，创建新节点给头节点
	//		  2. 链表不为空，找到链表的最后一个节点，指向新节点
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

	//1. 找到尾节点，并free()释放掉
	//2. 为了能删除掉尾节点的前一个节点，创建一个prev前驱节点，让prev指向的下一个节点置空

	//(2)无节点的情况
	assert(*phead != NULL);
	//1. 只有一个节点的情况
	if ((*phead)->next == NULL)
	{
		free(*phead);
		*phead = NULL;
	}
	//SLNode* tail = *phead;
	//if (tail->next == NULL)
	//{
	//	//问题：只剩一个节点的时候，为什么等到只剩一个节点释放tail后，原来的内存却不会释放？？？为什么后面的tail却可以释放
	//	解答： *phead赋值给了tail，tail得到的头节点的地址，tail可以根据头节点，释放 头节点指向的下一个节点，当最后一个被释放时，即指向头节点的空间被释放，但是phead的值没有改变，仍然指向头节点的地址，此时造成野指针，因此phead的值成了随机值
	//	free(tail);
	//	tail = NULL;
	//}
	else
	{
		/*
			第一种： 设置前驱节点
		*/

		//两个或两个以上节点的情况
		/*SLNode* tail = *phead;
		SLNode* prev = NULL;
		while (tail->next)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		tail = NULL;
		prev->next = NULL; //避免野指针
		*/

		/*
			第二种：判断向后的两个节点是否为空，可以判断此时节点是否为尾节点的前一个节点
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
	//pos为第一个节点 或 链表为空时
	if (*phead == pos)
	{
		newnode->next = *phead;
		*phead = newnode;
	}
	else
	{
		//找到pos的前一个位置
		SLNode* posPrev = *phead;
		while (posPrev->next != pos)
		{
			posPrev = posPrev->next;
		}
		posPrev->next = newnode;
		newnode->next = pos;
	}
}


//删除指定位置的节点
void SListEase(SLNode** phead, SLNode* pos)
{
	assert(pos);//pos不为空
	//删除第一个节点（头删）
	if (*phead == pos)
	{
		SListPopFront(phead);
	}

	//其余节点的删除
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
		//在头节点处删除
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
	//*phead指向头节点的地址置为NULL;避免野指针
	*phead = NULL;
}