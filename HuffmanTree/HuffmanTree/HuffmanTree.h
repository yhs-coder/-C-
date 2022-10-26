#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>


typedef double DataType; //���Ȩֵ����������

typedef struct HTNode // ����������Ϣ
{
	DataType weight;	//Ȩֵ
	int parent;	//���ڵ�
	int lc, rc;	//���Һ���
}HTNode,* HuffmanTree;

typedef char**  HuffmanCode; //�����ַ�ָ��洢��Ԫ������

//���±�Ϊ1��i-1�ķ�Χ�ҵ�Ȩֵ��С������ֵ�±꣬����s1��ȨֵС��s2��Ȩֵ
void Select(HuffmanTree* HT, int n, int* s1, int* s2);

void CreateHuffmanTree(HuffmanTree* HT, DataType* w, int n);

void HuffmanCoding(HuffmanTree HT, HuffmanCode* HC, int n);
