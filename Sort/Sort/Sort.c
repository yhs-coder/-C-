#define _CRT_SECURE_NO_WARNINGS
#include"Sort.h"
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

}