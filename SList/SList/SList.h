#define _CRT_SECURE_NO_WARNINGS

#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

/*
	单链表的实现

*/

typedef int SLDataType;

//定义链表节点结构
typedef struct SListNode
{
	SLDataType data;
	struct SListNode* next;

}SLNode;

//打印链表
void SListPrint(SLNode* phead);

//创建新节点
SLNode* CreateListNode( SLDataType x);

//链表尾插
void SListPushBack(SLNode** phead, SLDataType x);

//链表头插
void SListPushFront(SLNode** phead, SLDataType x);

//尾删
void SListPopBack(SLNode** phead);

//头删
void SListPopFront(SLNode** phead);

//查找
SLNode* SListFind(SLNode* phead, SLDataType x);

//在pos位置之前插入一个节点
void SListInsert(SLNode** phead, SLNode* pos, SLDataType x);

//删除指定位置的前一个节点
void SListEase(SLNode** phead, SLNode* pos);

//删除指定位置的后一个节点
void SListEaseAfter(SLNode** phead, SLNode* pos);

//删除链表中等于给定值val的所有节点
void SListEaseAll(SLNode** phead, SLDataType x);

//释放内存空间
void SlistDestory(SLNode** phead);