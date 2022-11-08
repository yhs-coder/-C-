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
		��������Ļ���˼�룺
		���������к����Ԫ�أ����뵽���������У�ʹ�����򣬳����������Ԫ�أ�ֱ��������������

		���һ��Ԫ��Ϊ�������У���������Ԫ�����β��뵽�����������У���������ֱ����������Ϊ����
	*/
	int i;
	//ע�⣺����n-1�αȽϣ���i=n-1ʱ,tmp=a[n],����Խ������������������һ��Ҫע��ȽϵĴ���
	for (i = 0; i < n-1; i++) 
	{
		int end = i; //�����������һ��Ԫ�ص��±�
		int tmp = a[end + 1];//�������Ԫ��
		
		//����Ԫ�غ����������е�Ԫ�ؽ��бȽϣ�ֱ���Ƚϵ���һ��
		while (end >= 0)
		{
			if (tmp < a[end]) //С���������е����һ��Ԫ��
			{
				a[end + 1] = a[end]; //��Ԫ������ƶ�
				end--;
			}
			else //�ҵ������λ��
			{
				break;
			}
		}
		/*
			����ִ�е���λ�ã��������������
			1.�������Ԫ�رȵ�ǰ���������е�����Ԫ��С�������뵽�˵�һλ����whileѭ��������
			2.������Ԫ���ҵ�Ӧ�����λ�ã�break����ѭ����
		*/
		a[end + 1] = tmp;	
	}
}


void ShellSort(int* a, int n)
{
	/*
		ϣ�������Ƚ���Ԥ���򣬵�����gapΪ1ʱ�ٽ���ֱ�Ӳ��������������

		����˼�룺����ȡ����һ�볤����Ϊ����gap,ÿ��Ԫ�ؾ���Ϊgap����һ�飬���ζ�ÿ������в�������
				  ������ȡһ��ǰ�������gap���������ϵĲ���......ֱ�����gapΪ1ʱ����������ֱ�Ӳ�����
				  �������
	*/
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 2;
		int i = 0;
		//ÿ����Ҫ�ȽϵĴ���
		for (i = 0; i < n-gap; i++)
		{
			int end = i;
			int tmp = a[end + gap];
			//��ÿ����в�������
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
	int pivot = begin;//�ӵ��±�

	if (left >= right)
		return;
	while (begin < end)
	{

		//���ұ߿�ʼ����С�ڿӵ�ָ���ŵ���ߵĿ���
		while (begin<end && a[end]>=key)
			end--;
		
		//�ұ��ҵ�Сֵ��������У��ӵ��±��Ƶ�end
		a[pivot] = a[end];
		pivot = end;
		//���ӱ���󣬴�����߿�ʼ��������key��ֵ�����ұߵĿ�
		while (begin < end && a[begin] <= key)
			begin++;

		a[pivot] = a[begin];
		pivot = begin;
	}
	//��һ��ʼ��key�����м�Ŀ��У���ʱkey����߱�keyС��key���ұ߱�key��
	pivot = begin;
	a[pivot] = key;

	//�ֶ���֮������ left  key   right
	QuickSort(a, left, pivot - 1);
	QuickSort(a, pivot+1, right);
	//���ʹ�÷ǵݹ�ķ������൱�ڰѵݹ�ʵ�ֵĲ��裬��취�÷ǵݹ�ķ�ʽȥ����

}

void QuickSort1(int* a, int  begin, int end)
{
	if (begin >= end)
		return;
	//�Ż�������ȡ��
	int midIndex = GetMidIndex(a, begin, end); //��ȡ��С���е������±�
	Swap(&a[begin], &a[midIndex]);//����������������˵������н���

	int left = begin; 
	int right = end;
	int key = a[left];//keyֵ�����ʹkey��ߵ�ֵ��keyС���ұߵ�ֵ��key��
	while (left < right)
	{
		//���keyֵȡ��������ߵ�ֵ���Ǿ��ȴ��ұ߿�ʼ
		//���keyֵȡ�������ұߵ�ֵ���Ǿ��ȴ���߿�ʼ

		//right���������ұ�keyС��ֵ
		while (left < right && a[right]>key)
			right--;

		//��end��ֵ�Ƶ�keyλ�ã����
		a[left] = a[right]; 

		//left�������ң��ұ�key���ֵ
		while (left < right && a[left] < key)
			left++;

		//���
		a[right] = a[left ];
		
	}

	int meeti = left; //left��right��������
	a[meeti] = key; //��key�������

	//[left,meeti-1]  meeti  [meeti+1,right]
	
	//С�����Ż�
	//����������Ż�
	if (meeti - 1 - left > 10)
		QuickSort1(a, begin, meeti - 1); //��key�������н��д˲���
	else
		InsertSort(a + left, meeti - 1 - left + 1);
	if(right-(meeti+1)>10)
		QuickSort1(a, meeti + 1, end);//��key�������н��д˲���
	else
		InsertSort(a + meeti+1, right-(meeti+1)+1);

}

void QuickSort2(int* a, int  begin, int end)
{
	if (begin >= end)
		return;
	//�Ż�������ȡ��
	int midIndex = GetMidIndex(a, begin, end); //��ȡ��С���е������±�
	Swap(&a[begin], &a[midIndex]);//����������������˵������н���
	int left = begin; //������ָ��
	int right = end;	//������ָ��
	int keyi = left;	//ѡ����ߵ�ֵ��key

	while (left < right)
	{
		//���key������ߵ�ֵ����right����
		//���key�����ұߵ�ֵ����left����

		//right���������ұ�keyС��ֵ���ҵ�����ͣ��
		while (left<right && a[right]>=a[keyi])
			right--;

		//left���������ұ�key���ֵ���ҵ�����ͣ��
		while (left < right && a[left] <= a[keyi])
			left++;

		//����left��right��ֵ
		if (left < right)
		{
			Swap(&a[left], &a[right]);
		}
	}
	//left��right��������
	int meeti = left;
	//����key���������ֵ
	Swap(&a[keyi], &a[meeti]);
	//left  key  right
	QuickSort2(a, begin, meeti - 1); //��key�������н��д˲���
	QuickSort2(a, meeti +1,end); //��key�������н��д˲���
}


void QuickSort3(int* a, int  begin, int end)
{
	/*
	*	����˼�룺��key��ߵ�ֵ��keyС����key�ұߵ�ֵ��key��֮���ٷֶ���֮
		ǰ��ָ�뷨��
		1.ѡ����������ҵ�ֵ����key
		2.����prev��cur��prevָ����Ԫ�أ�curָ��prev����һλ��
		3.���cur����key����һֱ�������ߣ�������С��key��ֵʱ����prev++,�����ߣ�Ȼ�󽻻����ߵ�ֵ
		4.cur�����������Ĳ�����ֱ��cur�������������飬��ָ��Խ������

	*/
	
	
	if (begin >= end)
		return;

	//�Ż�������ȡ��
	int midIndex = GetMidIndex(a, begin, end); //��ȡ��С���е������±�
	Swap(&a[begin], &a[midIndex]);//����������������˵������н���


	int prev = begin;
	int cur = prev + 1;
	int keyi = begin;
	while (cur <= end)//curδԽ�������
	{
		if (a[cur] < a[keyi] && ++prev != cur)//a[cur]С��a[keyi],����prev��cur����ͬһλ���򽻻�
		{
			Swap(&a[cur], &a[prev]);
		}
		cur++;
	}
	
	
	//���������������У�����key��prevλ�õ�ֵ
	int meeti = prev;
	Swap(&a[keyi], &a[meeti]); 
	//��ʱ left  key  right

	QuickSort3(a,begin,meeti-1);//����key��������ִ�д˲���
	QuickSort3(a, meeti + 1, end);//����key��������ִ�д˲���

}

int GetMidIndex(int* a, int left, int right)
{
	int middle = (left + right) / 2;  //ȡ�м�λ�õ��±�
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
	int middle = (left + right) / 2;  //ȡ�м�λ�õ��±�
	
	if (a[left] < a[right])
	{
		//��������� 
		//1.a[right]Ϊ���ֵ	
		if (a[right] > a[middle])
		{
			//�Ƚ���a[left]��a[middle]
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
		//a[left]Ϊ���ֵ
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
	int midIndex = GetMidIndex(a, left, right); //��ȡ��С���е������±�
	Swap(&a[left], &a[midIndex]);//����������������˵������н���

	int key = a[left];//keyֵ�����ʹkey��ߵ�ֵ��keyС���ұߵ�ֵ��key��
	while (left < right)
	{
		//���keyֵȡ��������ߵ�ֵ���Ǿ��ȴ��ұ߿�ʼ
		//���keyֵȡ�������ұߵ�ֵ���Ǿ��ȴ���߿�ʼ

		//right���������ұ�keyС��ֵ
		while (left < right && a[right]>key)
			right--;

		//��end��ֵ�Ƶ�keyλ�ã����
		a[left] = a[right];

		//left�������ң��ұ�key���ֵ
		while (left < right && a[left] < key)
			left++;

		//���
		a[right] = a[left];

	}

	int meeti = left; //left��right��������
	a[meeti] = key; //��key�������
	return meeti; //����key�ĵ�ǰλ��
}

int PartSort2(int* a, int left, int right)
{
	//�Ż�������ȡ��
	int midIndex = GetMidIndex(a, left, right); //��ȡ��С���е������±�
	Swap(&a[left], &a[midIndex]);//����������������˵������н���
	int keyi = left;	//ѡ����ߵ�ֵ��key

	while (left < right)
	{
		//���key������ߵ�ֵ����right����
		//���key�����ұߵ�ֵ����left����

		//right���������ұ�keyС��ֵ���ҵ�����ͣ��
		while (left < right && a[right] >= a[keyi])
			right--;

		//left���������ұ�key���ֵ���ҵ�����ͣ��
		while (left < right && a[left] <= a[keyi])
			left++;

		//����left��right��ֵ
		if (left < right)
		{
			Swap(&a[left], &a[right]);
		}
	}
	//left��right��������
	int meeti = left;
	//����key���������ֵ
	Swap(&a[keyi], &a[meeti]);
	return meeti;
}

int PartSort3(int* a, int left, int right)
{
	//�Ż�������ȡ��
	int midIndex = GetMidIndex(a, left, right); //��ȡ��С���е������±�
	Swap(&a[left], &a[midIndex]);//����������������˵������н���


	int prev = left;
	int cur = prev + 1;
	int keyi = left;
	while (cur <= right)//curδԽ�������
	{
		if (a[cur] < a[keyi] && ++prev != cur)//a[cur]С��a[keyi],����prev��cur����ͬһλ���򽻻�
		{
			Swap(&a[cur], &a[prev]);
		}
		cur++;
	}


	//���������������У�����key��prevλ�õ�ֵ
	int meeti = prev;
	Swap(&a[keyi], &a[meeti]);
	return meeti;//����key�ĵ�ǰλ��
}


void QuickSortNonR(int* a, int  begin, int end)
{
	ST st; //����ջ
	StackInit(&st);//��ջ��ʼ��
	StackPush(&st, end); //����βԪ�ص��±�
	StackPush(&st, begin);//������Ԫ�ص��±�
	while (!StackEmpty(&st)) //ջΪ���˳�ѭ��
	{
		int left = StackTop(&st); //ȡ��ջ��������L
		StackPop(&st);//��ջ
		int right = StackTop(&st);//ȡ��ջ��������R
		StackPop(&st);//��ջ

		int mid = GetMidIndex(a, left, right);
		Swap(&a[left], &a[mid]);

		//���е�������
		int keyIndex=PartSort3(a, left, right);


		//��Ϊ������ȡleft����ȡright
		//����ջ����ȳ������ԣ��Ȳ��������У��ڲ���������
		if (keyIndex + 1 < right)//key����������Ҫ��������
		{
			StackPush(&st, right);
			StackPush(&st, keyIndex+1);
		}
		if (left < keyIndex - 1) //�����е���������Ҫ��������
		{
			StackPush(&st, keyIndex - 1);
			StackPush(&st, left);
		}

		/*
		* �Լ�д�İ汾��
		int begin1 = left, end1 = key - 1;
		int begin2 = key + 1, end2 = right;
		//�Ƚ�key��������ջ������key�����������ջ
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
	StackDestroy(&st); //����ջ

}
