#define _CRT_SECURE_NO_WARNINGS


#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

/*
	˫�����ʵ��
*/

typedef int SLDataType;

typedef struct ListNode
{
	SLDataType data;
	struct ListNode* next;
	struct ListNode* prev;
	
}LTNode;

//��ӡ����
void ListPrint(LTNode* phead);

//��ʼ��������һ���ڱ�λͷ�ڵ�
LTNode* ListInit();

//�����½ڵ�
LTNode* BuyListNode(SLDataType x);

//����β��
void ListPushBack(LTNode* phead, SLDataType x);

//����ͷ��
void ListPushFront(LTNode* phead, SLDataType x);

//βɾ
void ListPopBack(LTNode* phead);

//ͷɾ
void ListPopFront(LTNode* phead);

//����
LTNode* ListFind(LTNode* phead, SLDataType x);

//��posλ��֮ǰ����һ���ڵ�
void ListInsert(LTNode* pos, SLDataType x);

//ɾ��ָ��λ�õĽڵ�
void ListEase( LTNode* pos);

//�ͷ��ڴ���Դ
void ListDestroy(LTNode* phead);

