#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>


typedef double DataType; //结点权值的数据类型

typedef struct HTNode // 单个结点的信息
{
	DataType weight;	//权值
	int parent;	//父节点
	int lc, rc;	//左右孩子
}HTNode,* HuffmanTree;

typedef char**  HuffmanCode; //二级字符指针存储的元素类型

//在下标为1到i-1的范围找到权值最小的两个值下标，其中s1的权值小于s2的权值
void Select(HuffmanTree* HT, int n, int* s1, int* s2);

//创建哈夫曼树
void CreateHuffmanTree(HuffmanTree* HT, DataType* w, int n);

//生成哈夫曼编码
void HuffmanCoding(HuffmanTree HT, HuffmanCode* HC, int n);
