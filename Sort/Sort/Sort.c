#define _CRT_SECURE_NO_WARNINGS
#include"Sort.h"
void InsertSort(int* a, int n)
{
	/*
		插入排序的基本思想：
		将有序序列后面的元素，插入到有序序列中，使其有序，持续插入后面元素，直到整个序列有序。

		令第一个元素为有序序列，让其后面的元素依次插入到该有序序列中，保持有序，直到整个序列为有序！
	*/
	int i;
	//注意：进行n-1次比较，当i=n-1时,tmp=a[n],数组越界啦！！！！！所以一定要注意比较的次数
	for (i = 0; i < n-1; i++) 
	{
		int end = i; //有序序列最后一个元素的下标
		int tmp = a[end + 1];//待插入的元素
		
		//插入元素和有序序列中的元素进行比较，直到比较到第一个
		while (end >= 0)
		{
			if (tmp < a[end]) //小与有序序列的最后一个元素
			{
				a[end + 1] = a[end]; //将元素向后移动
				end--;
			}
			else //找到插入的位置
			{
				break;
			}
		}
		/*
			代码执行到此位置，会有两种情况：
			1.待插入的元素比当前有序序列中的所有元素小（即插入到了第一位）（while循环结束）
			2.待插入元素找到应插入的位置（break跳出循环）
		*/
		a[end + 1] = tmp;	
	}
}


void ShellSort(int* a, int n)
{
	/*
		希尔排序：先进行预排序，当增量gap为1时再进行直接插入排序，完成排序。

		基本思想：首先取序列一半长度作为增量gap,每个元素距离为gap当作一组，依次对每个组进行插入排序；
				  接着再取一半前面的增量gap，进行以上的操作......直到最后gap为1时，进行最后的直接插入序，
				  完成排序
	*/
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 2;
		int i = 0;
		//每趟需要比较的次数
		for (i = 0; i < n-gap; i++)
		{
			int end = i;
			int tmp = a[end + gap];
			//对每组进行插入排序
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end]; 
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
}




void QuickSort(int* a, int  left, int right)
{
	int begin, end;
	begin = left; 
	end = right;
	int key = a[begin]; 
	int pivot = begin;//坑的下标

	if (left >= right)
		return;
	while (begin < end)
	{

		//从右边开始，将小于坑的指，放到左边的坑中
		while (begin<end && a[end]>=key)
			end--;
		
		//右边找到小值，填入坑中，坑的下标移到end
		a[pivot] = a[end];
		pivot = end;
		//当坑被填后，从做左边开始，将大于key的值放入右边的坑
		while (begin < end && a[begin] <= key)
			begin++;

		a[pivot] = a[begin];
		pivot = begin;
	}
	//将一开始的key填入中间的坑中，此时key的左边比key小，key的右边比key大
	pivot = begin;
	a[pivot] = key;

	//分而治之，依次 left  key   right
	QuickSort(a, left, pivot - 1);
	QuickSort(a, pivot+1, right);

}