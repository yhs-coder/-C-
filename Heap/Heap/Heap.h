#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include<string.h>
#include<math.h>

typedef int HPDataType;  //堆中存放数据的类型

typedef struct Heap
{
	HPDataType* a; //用于存放数据的数组
	int size;  //记录堆中已有的元素个数
	int capacity; //记录堆的容量
}HP;

//初始堆
void HeapInit(HP* php, HPDataType* a, int n);

//销毁堆
void HeapDestroy(HP* php);

//堆的向上调整算法
void AdjustUp(HPDataType* a, int child);

//堆的向下调整算法
void AdjustDown(int* a, int n, int parent);

//交换函数
void Swap(int* p1, int* p2);

//打印堆
void HeapPrint(HP* php);

//堆的插入
void HeapPush(HP* php, HPDataType x);

//堆的删除
void HeapPop(HP* php);

//获取堆的数据
HPDataType HeapTop(HP* php);

//获取堆得数据个数
int HeapSize(HP* php);

//堆的判空
bool HeapEmpty(HP* php);

//堆的升序算法
void HeapUp(HP* php);

