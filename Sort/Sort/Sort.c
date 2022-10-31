#define _CRT_SECURE_NO_WARNINGS
#include"Sort.h"

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