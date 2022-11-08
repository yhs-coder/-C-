#define _CRT_SECURE_NO_WARNINGS
#include"Sort.h"
#include<stdlib.h>
#include<time.h>

PrintArray(int* a, int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}
void TestQuickSort()
{
	int a[] = { 39,38,65,97,76,13,27,49 }; 
	int n = sizeof(a) / sizeof(a[0]);
	//QuickSort1(a, 0, n - 1);
	//PartSort2(a, 0, n - 1);
	//PartSort3(a, 0, n - 1);
	//QuickSort2(a, 0, n - 1);
	//QuickSort3(a, 0, n - 1);
	//printf("Index: %d\n", GetMidIndex(a, 0, n - 1));
	
	//快速排序：非递归实现
	QuickSortNonR(a, 0, n - 1);

	PrintArray(a, n);
}

void TestInsertSort()
{
	int a[] = { 49,38,65,97,76,13,27,49 };
	int n = sizeof(a) / sizeof(a[0]);
	InsertSort(a, n);
	PrintArray(a, n);

}

void TestShellSort()
{
	int a[] = { 49,38,65,97,76,13,27,49 };
	int n = sizeof(a) / sizeof(a[0]);
	ShellSort(a, n);
	PrintArray(a, n);
}



void TestOP()
{
	srand(time(0));
	const int N = 100000;
	int* a1 = (int*)malloc(sizeof(int) * N);
	int* a2 = (int*)malloc(sizeof(int) * N);
	int* a3 = (int*)malloc(sizeof(int) * N);
	int* a4 = (int*)malloc(sizeof(int) * N);
	int* a5 = (int*)malloc(sizeof(int) * N);
	int* a6 = (int*)malloc(sizeof(int) * N);
	//int* a7 = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; i++)
	{
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i]= a1[i];
		a4[i]= a1[i];
		a5[i]= a1[i];
		a6[i]= a1[i];
	}
	//clock(),计时函数，返回程序启动到函数调用占用CPU的时间
	int begin1 = clock();
	InsertSort(a1, N);
	int end1 = clock();

	int begin2 = clock();
	//ShellSort(a1, N);
	int end2 = clock();

	int begin3 = clock();
	//SelectSort(a1, N);
	int end3 = clock();

	int begin4 = clock();
	//HeapSort(a1, N);
	int end4 = clock();

	int begin5 = clock();
	//QuickSortNonR(a5,0,N-1);
	QuickSort1(a5, 0, N - 1);

	int end5 = clock();

	int begin6 = clock();
	//MergeSort(a1, N);
	int end6 = clock();
	printf("InsertSort:%d\n", end1 - begin1);
	//printf("ShellSort:%d\n", end2 - begin2);
	//printf("SelectSort:%d\n", end3 - begin3);
	//printf("HeapSort:%d\n", end4 - begin4);
	printf("QuickSort:%d\n", end5 - begin5);
	//printf("MergeSort:%d\n", end6 - begin6);

	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);

}

int main()
{
	//TestQuickSort();
	//TestInsertSort();
	//TestShellSort();

	TestOP();
	return 0;
}