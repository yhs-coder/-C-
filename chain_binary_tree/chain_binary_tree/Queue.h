#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>
#include"BinTree.h"


typedef BTNode*  QDataType;

typedef struct QueueNode
{
	QDataType  data;
	struct QueueNode* next;

}QueueNode;
typedef struct Queue
{
	QueueNode* head;//∂”Õ∑
	QueueNode* tail;//∂”Œ≤
}Queue;

void QueueInit(Queue* pq);
void QueueDestroy(Queue* pq);
void QueuePush(Queue* pq, QDataType x);
void QueuePop(Queue* pq);
QDataType QueueFront(Queue* pq);
QDataType QueueBack(Queue* pq);
int QueueSize(Queue* pq);
bool QueueEmpty(Queue* pq);