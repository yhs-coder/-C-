#define _CRT_SECURE_NO_WARNINGS

#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

/*
	�������ʵ��

*/

typedef int SLDataType;

//��������ڵ�ṹ
typedef struct SListNode
{
	SLDataType data;
	struct SListNode* next;

}SLNode;

//��ӡ����
void SListPrint(SLNode* phead);

//�����½ڵ�
SLNode* CreateListNode( SLDataType x);

//����β��
void SListPushBack(SLNode** phead, SLDataType x);

//����ͷ��
void SListPushFront(SLNode** phead, SLDataType x);

//βɾ
void SListPopBack(SLNode** phead);

//ͷɾ
void SListPopFront(SLNode** phead);

//����
SLNode* SListFind(SLNode* phead, SLDataType x);

//��posλ��֮ǰ����һ���ڵ�
void SListInsert(SLNode** phead, SLNode* pos, SLDataType x);

//ɾ��ָ��λ�õ�ǰһ���ڵ�
void SListEase(SLNode** phead, SLNode* pos);

//ɾ��ָ��λ�õĺ�һ���ڵ�
void SListEaseAfter(SLNode** phead, SLNode* pos);

//ɾ�������е��ڸ���ֵval�����нڵ�
void SListEaseAll(SLNode** phead, SLDataType x);

//�ͷ��ڴ�ռ�
void SlistDestory(SLNode** phead);