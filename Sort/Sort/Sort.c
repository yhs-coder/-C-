#define _CRT_SECURE_NO_WARNINGS
#include"Sort.h"
void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

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
	//如果使用非递归的方法，相当于把递归实现的步骤，想办法用非递归的方式去代替

}

void QuickSort1(int* a, int  begin, int end)
{
	if (begin >= end)
		return;
	//优化：三数取中
	int midIndex = GetMidIndex(a, begin, end); //获取大小居中的数的下标
	Swap(&a[begin], &a[midIndex]);//将该数与序列最左端的数进行交换

	int left = begin; 
	int right = end;
	int key = a[left];//key值，最后使key左边的值比key小，右边的值比key大
	while (left < right)
	{
		//如果key值取得是最左边的值，那就先从右边开始
		//如果key值取得是最右边的值，那就先从左边开始

		//right从右向左，找比key小的值
		while (left < right && a[right]>key)
			right--;

		//将end的值移到key位置，填坑
		a[left] = a[right]; 

		//left从左向右，找比key大的值
		while (left < right && a[left] < key)
			left++;

		//填坑
		a[right] = a[left ];
		
	}

	int meeti = left; //left和right的相遇点
	a[meeti] = key; //将key填入坑内

	//[left,meeti-1]  meeti  [meeti+1,right]
	
	//小区间优化
	//左区间进行优化
	if (meeti - 1 - left > 10)
		QuickSort1(a, begin, meeti - 1); //对key的左序列进行此操作
	else
		InsertSort(a + left, meeti - 1 - left + 1);
	if(right-(meeti+1)>10)
		QuickSort1(a, meeti + 1, end);//对key的右序列进行此操作
	else
		InsertSort(a + meeti+1, right-(meeti+1)+1);

}

void QuickSort2(int* a, int  begin, int end)
{
	if (begin >= end)
		return;
	//优化：三数取中
	int midIndex = GetMidIndex(a, begin, end); //获取大小居中的数的下标
	Swap(&a[begin], &a[midIndex]);//将该数与序列最左端的数进行交换
	int left = begin; //当作左指针
	int right = end;	//当作右指针
	int keyi = left;	//选最左边的值当key

	while (left < right)
	{
		//如果key是最左边的值，则right先走
		//如果key是最右边的值，则left先走

		//right从右往左找比key小的值，找到了则停下
		while (left<right && a[right]>=a[keyi])
			right--;

		//left从左往右找比key大的值，找到了则停下
		while (left < right && a[left] <= a[keyi])
			left++;

		//交换left和right的值
		if (left < right)
		{
			Swap(&a[left], &a[right]);
		}
	}
	//left和right的相遇点
	int meeti = left;
	//交换key和相遇点的值
	Swap(&a[keyi], &a[meeti]);
	//left  key  right
	QuickSort2(a, begin, meeti - 1); //对key的左序列进行此操作
	QuickSort2(a, meeti +1,end); //对key的右序列进行此操作
}


void QuickSort3(int* a, int  begin, int end)
{
	/*
	*	核心思想：让key左边的值比key小，让key右边的值比key大，之后再分而治之
		前后指针法：
		1.选出最左或最右的值当作key
		2.定义prev，cur，prev指向首元素，cur指向prev的下一位置
		3.如果cur大于key，则一直往下面走，当遇到小于key的值时，让prev++,往后走，然后交换两者的值
		4.cur继续第三步的操作，直到cur遍历完整个数组，即指针越界后结束

	*/
	
	
	if (begin >= end)
		return;

	//优化：三数取中
	int midIndex = GetMidIndex(a, begin, end); //获取大小居中的数的下标
	Swap(&a[begin], &a[midIndex]);//将该数与序列最左端的数进行交换


	int prev = begin;
	int cur = prev + 1;
	int keyi = begin;
	while (cur <= end)//cur未越界则继续
	{
		if (a[cur] < a[keyi] && ++prev != cur)//a[cur]小于a[keyi],并且prev与cur不在同一位置则交换
		{
			Swap(&a[cur], &a[prev]);
		}
		cur++;
	}
	
	
	//当遍历完整个序列，交换key和prev位置的值
	int meeti = prev;
	Swap(&a[keyi], &a[meeti]); 
	//此时 left  key  right

	QuickSort3(a,begin,meeti-1);//对于key的左序列执行此操作
	QuickSort3(a, meeti + 1, end);//对于key的右序列执行此操作

}

int GetMidIndex(int* a, int left, int right)
{
	int middle = (left + right) / 2;  //取中间位置的下标
	//left  middle  right
	if (a[middle] > a[left])
	{
		if (a[middle] < a[right])
			return middle;
		else if (a[right] > a[left])
			return right;
		else
			return left;
	}

	//a[middle]<a[left]
	else
	{
		if (a[middle] > a[right])
			return middle;
		else if (a[right] < a[left])
			return right;
		else
			return left;
	}
}
/*
int GetMidIndex(int* a, int left, int right)
{
	int middle = (left + right) / 2;  //取中间位置的下标
	
	if (a[left] < a[right])
	{
		//两种情况： 
		//1.a[right]为最大值	
		if (a[right] > a[middle])
		{
			//比较下a[left]和a[middle]
			if (a[middle] > a[left])
				return middle;
			else
				return left;
		}
		//2.a[right]<a[middle]
		else
		{
			return right;
		}
	}
	//a[left]>a[right]
	else
	{
		//a[left]为最大值
		if (a[left] > a[middle])
		{
			if (a[middle] > a[right])
				return middle;
			else
				return right;
		}
		//a[left]<a[middle]
		else
		{
			return left;
		}
	}
}*/


int PartSort1(int* a, int left, int right)
{
	int midIndex = GetMidIndex(a, left, right); //获取大小居中的数的下标
	Swap(&a[left], &a[midIndex]);//将该数与序列最左端的数进行交换

	int key = a[left];//key值，最后使key左边的值比key小，右边的值比key大
	while (left < right)
	{
		//如果key值取得是最左边的值，那就先从右边开始
		//如果key值取得是最右边的值，那就先从左边开始

		//right从右向左，找比key小的值
		while (left < right && a[right]>key)
			right--;

		//将end的值移到key位置，填坑
		a[left] = a[right];

		//left从左向右，找比key大的值
		while (left < right && a[left] < key)
			left++;

		//填坑
		a[right] = a[left];

	}

	int meeti = left; //left和right的相遇点
	a[meeti] = key; //将key填入坑内
	return meeti; //返回key的当前位置
}

int PartSort2(int* a, int left, int right)
{
	//优化：三数取中
	int midIndex = GetMidIndex(a, left, right); //获取大小居中的数的下标
	Swap(&a[left], &a[midIndex]);//将该数与序列最左端的数进行交换
	int keyi = left;	//选最左边的值当key

	while (left < right)
	{
		//如果key是最左边的值，则right先走
		//如果key是最右边的值，则left先走

		//right从右往左找比key小的值，找到了则停下
		while (left < right && a[right] >= a[keyi])
			right--;

		//left从左往右找比key大的值，找到了则停下
		while (left < right && a[left] <= a[keyi])
			left++;

		//交换left和right的值
		if (left < right)
		{
			Swap(&a[left], &a[right]);
		}
	}
	//left和right的相遇点
	int meeti = left;
	//交换key和相遇点的值
	Swap(&a[keyi], &a[meeti]);
	return meeti;
}

int PartSort3(int* a, int left, int right)
{
	//优化：三数取中
	int midIndex = GetMidIndex(a, left, right); //获取大小居中的数的下标
	Swap(&a[left], &a[midIndex]);//将该数与序列最左端的数进行交换


	int prev = left;
	int cur = prev + 1;
	int keyi = left;
	while (cur <= right)//cur未越界则继续
	{
		if (a[cur] < a[keyi] && ++prev != cur)//a[cur]小于a[keyi],并且prev与cur不在同一位置则交换
		{
			Swap(&a[cur], &a[prev]);
		}
		cur++;
	}


	//当遍历完整个序列，交换key和prev位置的值
	int meeti = prev;
	Swap(&a[keyi], &a[meeti]);
	return meeti;//返回key的当前位置
}


void QuickSortNonR(int* a, int  begin, int end)
{
	ST st; //创建栈
	StackInit(&st);//对栈初始化
	StackPush(&st, end); //插入尾元素的下标
	StackPush(&st, begin);//插入首元素的下标
	while (!StackEmpty(&st)) //栈为空退出循环
	{
		int left = StackTop(&st); //取出栈顶的数据L
		StackPop(&st);//出栈
		int right = StackTop(&st);//取出栈顶的数据R
		StackPop(&st);//出栈

		int mid = GetMidIndex(a, left, right);
		Swap(&a[left], &a[mid]);

		//进行单趟排序
		int keyIndex=PartSort3(a, left, right);


		//因为上面先取left，再取right
		//根据栈后进先出的特性，先插入右序列，在插入左序列
		if (keyIndex + 1 < right)//key的右序列需要继续排序
		{
			StackPush(&st, right);
			StackPush(&st, keyIndex+1);
		}
		if (left < keyIndex - 1) //该序列的左序列需要继续排序
		{
			StackPush(&st, keyIndex - 1);
			StackPush(&st, left);
		}

		/*
		* 自己写的版本：
		int begin1 = left, end1 = key - 1;
		int begin2 = key + 1, end2 = right;
		//先将key右区间入栈，再让key的左半区间入栈
		if (begin2 < end2)
		{
			StackPush(&st, end2);
			StackPush(&st, begin2);
		}
		if (begin1 < end1)
		{
			StackPush(&st, end1);
			StackPush(&st, begin1);
		}
		*/
	
	}
	StackDestroy(&st); //销毁栈

}
