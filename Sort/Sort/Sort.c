#define _CRT_SECURE_NO_WARNINGS
#include"Sort.h"

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