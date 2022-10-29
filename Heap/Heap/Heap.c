#define _CRT_SECURE_NO_WARNINGS
#include"Heap.h"

void Swap(int* p1, int* p2)
{
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void HeapInit(HP* php, HPDataType* a, int n)
{
	assert(php);

	//����һ��n���ռ䣬���ڸ���a�����ݣ����жѵĳ�ʼ��
	HPDataType* tmp = (HPDataType*)malloc(n*sizeof(HPDataType));
	if (tmp == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}

	php->a = tmp;

	//��a�����ݿ���������
	memcpy(php->a, a, n * sizeof(HPDataType));
	php->size = n;
	php->capacity=n;


	//���� 
	int i = 0;
	for (i = (n - 1 - 1) / 2; i >= 0; i--)// ����0 ����Ϊ�����ҲҪ�������µ���
	{
		AdjustDown(php->a,php->size, i);
	}
}
void HeapDestroy(HP* php)
{
	assert(php);
	free(php->a); //�ͷŶ�̬����Ŀռ�
	php->a = NULL; 
	php->size = 0;
	php->capacity = 0;
}

void AdjustDown(int* a, int n, int parent)
{
	
	//��child��¼���Һ�����ֵ��С�ĺ��ӽ����±�
	int child = parent * 2 + 1;//��Ĭ�������ӵ�ֵ��С
	while (child < n)  //���ӽ����±겻����n
	{
		//���Һ��Ӵ������Һ��ӱ�����С
		if (child+1<n && a[child + 1] < a[child])
		{
			child++;//�ý�Сֵ��Ϊ�Һ���
		}

		//���Һ����н�С��ֵ�ȸ��ڵ�С
		if (a[child] < a[parent])
		{
			//����������ӽ����н���
			Swap(&a[child], &a[parent]);

			//�������½��е���
			parent = child;
			child = parent * 2 + 1;
		}

		//����ѵ�����
		else 
		{
			break;
		}
	}
}

void AdjustUp(HPDataType* a, int child)
{
	/*
		˼·����С�ѣ�
		1.�Ƚϲ����Ŀ�����븸�ڵ��ֵ
		2.���Ŀ����С���丸��㣬�򽻻����ߵ�λ��
		3.��ԭ��㸸����λ�õ���Ŀ���㣬�������Ͻ��е���
		4.��Ŀ����Ϊ���ڵ� ���� ��Ŀ������ڸ����ʱ��˵�����Ѿ��������
	*/

	//��ø������±�
	int parent = (child - 1) / 2;
	while (child > 0) //�����������ʱֹͣ
	{
		if (a[child] < a[parent]) //���ӽ���ֵС�ڸ�����ֵ
		{
			//�������ӽ���븸����λ��
			Swap(&a[child], &a[parent]);

			//�������Ͻ��е���
			child =parent;
			parent = (child - 1) / 2;
		}
		else//�ѳɶ�
		{
			break;
		}
	}

}

//������Ϊn�Ķ����������
int depth(int n)
{
	assert(n >= 0);

	if (n > 0)
	{
		/*	
			һ��ʼ��h=1,��2^1=2,��m=2^h
			�� 2^h  -1 =n����m-1=n
			��m<n+1,��߶ȼ�1��ֱ��m>=n+1��˵���Ѿ��ﵽ�������ʱֹͣ
		*/
		int m = 2;
		int height = 1;
		while (m < n + 1)
		{
			m *= 2;
			height++;
		}
		return height;
	}
	else
	{
		return 0;
	}
}
void HeapPrint(HP* php)
{
	assert(php);

	//��������ṹ���д�ӡ
	int i = 0;
	for (i = 0; i < php->size; i++)
	{
		printf("%d ", php->a[i]);
	}
	printf("\n");


	//�������νṹ���д�ӡ
	int h = depth(php->size);
	int N = (int)pow(2, h) - 1; //�����ö������������ͬ�����������Ľ������
	int space = N - 1; //��¼ÿһ�еĿո���
	int row = 1; //��ǰ��ӡ������
	int pos = 0; //����ӡ���±�
	while (1)
	{
		//��ӡǰ��Ŀո�
		int i = 0; 
		for (i = 0; i < space; i++)
		{
			printf(" ");
		}
		//��ӡ���ݺͼ��
		int count = (int)pow(2,row - 1); //ÿһ�еĽ������
		//printf("2^0 = %d", (int)pow(2, row - 1));
		while (count--)
		{
			printf("%d",php->a[pos++]); //��ӡ����
			if (pos >= php->size) //���һ�����ݴ�ӡ���
			{
				printf("\n");
				return;
			}
			int distance = (space + 1) * 2;//������֮��Ŀո���
			while (distance--)
			{
				printf(" ");
			}
		}
		printf("\n");
		row++;
		space = space / 2-1 ;
	}
}

void HeapPush(HP* php, HPDataType x)
{
	assert(php);

	//�жϿռ��Ƿ��㹻
	if (php->size == php->capacity)
	{
		HPDataType* tmp = (HPDataType*)realloc(php->a,2 * php->capacity * sizeof(HPDataType));
		if (tmp == NULL)
		{
			printf("malloc fail.\n");
			exit(-1);
		}
		php->capacity = 2 * php->capacity;
		php->a = tmp;
	}
	php->a[php->size] = x;
	php->size++;

	//�Բ�������ݣ����Ͻ��е���
	AdjustUp(php->a, php->size-1);
	
}


void HeapPop(HP* php)
{
	/*
		�ѵ�ɾ����ɾ�����ǶѶ������ֱ��ɾ���Ѷ����ᵼ������������뺢�ӽ���ϵ���ң������½���
		�����临�Ӷȱ��

		�Ѷ���ɾ��˼·��
		1.�����öѶ������һ�����ݽ���
		2.ɾ�����һ�����
		3.���öѽ������µ���������ʱ�临�ӶȾ�Ϊ logN
	*/
	assert(php);
	assert(!HeapEmpty(php));
	//�öѶ������һ�����λ�ý���
	Swap(&php->a[0], &php->a[php->size - 1]);

	///ɾ�����һ����㣨Ҳ����ɾ���Ѷ������ݣ�
	php->size--;

	//�ѽ������µ���
	AdjustDown(php->a, php->size,0);
}

bool HeapEmpty(HP* php)
{
	assert(php);
	return php->size == 0;
}

HPDataType HeapTop(HP* php)
{
	assert(php);
	assert(!HeapEmpty(php));
	return php->a[0];
}

int HeapSize(HP* php)
{
	assert(php);
	return php->size;
}

void MaxHeap(HPDataType* a,int parent,int n)
{
	int child = parent * 2 + 1;
	while (child <n)
	{
		if (child+1<n &&a[child + 1] > a[child])
		{
			child++;
		}
		if (a[child] > a[parent])
		{
			Swap(&a[child] ,& a[parent]);
			/*child = parent;
			parent = (child - 1) / 2;*/
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapUp(HP* php)
{
	/*
	*   �ڶ���ʵ������
		˼·��
		1.�ȴ���һ�����
		2.�����Ѷ������һ�����λ��
		3.��ǰn-1�����������µ����㷨
		4.ֱ�����ֻʣһ���Ѷ�����ֻʣһ�����ֹͣ
	*/
	assert(php);
	assert(!HeapEmpty(php));
	int i = 0;

	//�ô�ѷ�ʽ���ϵ���
	for (i = (php->size - 1 - 1) / 2; i >= 0; i--)
	{
		MaxHeap(php->a, i, php->size);
	}

	//����������
	
	//��¼Ҫ��������
	int end = php->size;
	
	while (end > 0)
	{
		Swap(&php->a[0], &php->a[end - 1]);
		--end;//һ��Ҫend--,�������һ����㱻����
		MaxHeap(php->a, 0, end); //�������µ���
	}
	
}