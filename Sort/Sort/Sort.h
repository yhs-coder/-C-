#pragma once

#include<stdio.h>
#include"Stack.h"

//插入排序
void InsertSort(int* a, int n);

//希尔排序(也叫缩小增量法）
void ShellSort(int* a, int n);

void Swap(int* p1, int* p2);
/*
	快速排序递归实现的三种方法：

	优化：
	1.小区间优化
	2.三数取中
*/
//挖坑法
void QuickSort1(int* a, int  begin, int end);
//左右指针法
void QuickSort2(int* a, int  begin, int end);

//前后指针法(类似于快慢指针）
void QuickSort3(int* a, int  begin, int end);

//快速排序的优化
//1.三数取中
int GetMidIndex(int* a, int left, int right);


//快速排序的非递归实现
//三种方法的单趟排序封装

//挖坑法
int PartSort1(int* a, int left, int right);
//左右指针法
int PartSort2(int* a, int left, int right);
//前后指针法
int PartSort3(int* a, int left, int right);

void QuickSortNonR(int* a, int  begin, int end);





