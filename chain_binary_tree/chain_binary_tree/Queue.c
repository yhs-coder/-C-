#define _CRT_SECURE_NO_WARNINGS
#include"Queue.h"

void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = NULL;
	pq->tail = NULL;
}


void QueueDestroy(Queue* pq)
{
	assert(pq);
	QueueNode* cur = pq->head;
	while(cur)
	{
		QueueNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->head = pq->tail = NULL;
}


void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
	assert(newNode);
	newNode->data = x;
	newNode->next = NULL;
	if (pq->head == NULL)
	{
		pq->head = pq->tail = newNode;
	}
	else
	{
		pq->tail->next = newNode;
		pq->tail = newNode;
	}
}

void QueuePop(Queue* pq)
{
	assert(pq);
	//����Ϊ��
	assert(!QueueEmpty(pq));
	QueueNode* next = pq->head->next;
	free(pq->head);
	pq->head = next;

	//���裡����
	//���ڵ�ֻʣһ��ʱ��һ��Ҫ��tail��Ϊ�գ������Ұָ�����⣡����
	////��Ϊ��ʹ�ռ䱻�ͷ��ˣ�pq->tail��Ȼָ����һ���ڴ��ַ��
	if (pq->head == NULL)
	{
		pq->tail = NULL;
	}
}

bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->head == NULL;
}

QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->head->data;
}

QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->tail->data;
}

int QueueSize(Queue* pq)
{
	assert(pq);
	int count = 0;
	QueueNode* cur = pq->head;
	while (cur)
	{
		count++;
		cur = cur->next;
	}
	return count;
}

