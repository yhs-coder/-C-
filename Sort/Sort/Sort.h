#pragma once

#include<stdio.h>
#include"Stack.h"

//��������
void InsertSort(int* a, int n);

//ϣ������(Ҳ����С��������
void ShellSort(int* a, int n);

void Swap(int* p1, int* p2);
/*
	��������ݹ�ʵ�ֵ����ַ�����

	�Ż���
	1.С�����Ż�
	2.����ȡ��
*/
//�ڿӷ�
void QuickSort1(int* a, int  begin, int end);
//����ָ�뷨
void QuickSort2(int* a, int  begin, int end);

//ǰ��ָ�뷨(�����ڿ���ָ�룩
void QuickSort3(int* a, int  begin, int end);

//����������Ż�
//1.����ȡ��
int GetMidIndex(int* a, int left, int right);


//��������ķǵݹ�ʵ��
//���ַ����ĵ��������װ

//�ڿӷ�
int PartSort1(int* a, int left, int right);
//����ָ�뷨
int PartSort2(int* a, int left, int right);
//ǰ��ָ�뷨
int PartSort3(int* a, int left, int right);

void QuickSortNonR(int* a, int  begin, int end);





