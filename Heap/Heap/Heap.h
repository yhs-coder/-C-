#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include<string.h>
#include<math.h>

typedef int HPDataType;  //���д�����ݵ�����

typedef struct Heap
{
	HPDataType* a; //���ڴ�����ݵ�����
	int size;  //��¼�������е�Ԫ�ظ���
	int capacity; //��¼�ѵ�����
}HP;

//��ʼ��
void HeapInit(HP* php, HPDataType* a, int n);

//���ٶ�
void HeapDestroy(HP* php);

//�ѵ����ϵ����㷨
void AdjustUp(HPDataType* a, int child);

//�ѵ����µ����㷨
void AdjustDown(int* a, int n, int parent);

//��������
void Swap(int* p1, int* p2);

//��ӡ��
void HeapPrint(HP* php);

//�ѵĲ���
void HeapPush(HP* php, HPDataType x);

//�ѵ�ɾ��
void HeapPop(HP* php);

//��ȡ�ѵ�����
HPDataType HeapTop(HP* php);

//��ȡ�ѵ����ݸ���
int HeapSize(HP* php);

//�ѵ��п�
bool HeapEmpty(HP* php);

//�ѵ������㷨
void HeapUp(HP* php);

