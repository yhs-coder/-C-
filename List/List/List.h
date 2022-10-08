#define _CRT_SECURE_NO_WARNINGS


#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

/*
	双链表的实现
*/

typedef int SLDataType;

typedef struct ListNode
{
	SLDataType data;
	struct ListNode* next;
	struct ListNode* prev;
	
}LTNode;

//打印链表
void ListPrint(LTNode* phead);

//初始化，创建一个哨兵位头节点
LTNode* ListInit();

//创建新节点
LTNode* BuyListNode(SLDataType x);

//链表尾插
void ListPushBack(LTNode* phead, SLDataType x);

//链表头插
void ListPushFront(LTNode* phead, SLDataType x);

//尾删
void ListPopBack(LTNode* phead);

//头删
void ListPopFront(LTNode* phead);

//查找
LTNode* ListFind(LTNode* phead, SLDataType x);

//在pos位置之前插入一个节点
void ListInsert(LTNode* pos, SLDataType x);

//删除指定位置的节点
void ListEase( LTNode* pos);

//释放内存资源
void ListDestroy(LTNode* phead);

