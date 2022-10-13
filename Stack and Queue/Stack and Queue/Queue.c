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
	//队列为空
	assert(!QueueEmpty(pq));
	QueueNode* next = pq->head->next;
	free(pq->head);
	pq->head = next;

	//警惕！！！
	//当节点只剩一个时，一定要让tail置为空，会造成野指针问题！！！
	////因为即使空间被释放了，pq->tail仍然指向那一块内存地址！
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

