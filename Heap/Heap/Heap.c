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

	//申请一个n个空间，用于复制a的数据，进行堆的初始化
	HPDataType* tmp = (HPDataType*)malloc(n*sizeof(HPDataType));
	if (tmp == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}

	php->a = tmp;

	//将a的数据拷贝到堆中
	memcpy(php->a, a, n * sizeof(HPDataType));
	php->size = n;
	php->capacity=n;


	//建堆 
	int i = 0;
	for (i = (n - 1 - 1) / 2; i >= 0; i--)// 等于0 是因为根结点也要进行向下调整
	{
		AdjustDown(php->a,php->size, i);
	}
}
void HeapDestroy(HP* php)
{
	assert(php);
	free(php->a); //释放动态分配的空间
	php->a = NULL; 
	php->size = 0;
	php->capacity = 0;
}

void AdjustDown(int* a, int n, int parent)
{
	
	//用child记录左右孩子中值较小的孩子结点的下标
	int child = parent * 2 + 1;//先默认其左孩子的值较小
	while (child < n)  //孩子结点的下标不超过n
	{
		//当右孩子存在且右孩子比左孩子小
		if (child+1<n && a[child + 1] < a[child])
		{
			child++;//让较小值改为右孩子
		}

		//左右孩子中较小的值比父节点小
		if (a[child] < a[parent])
		{
			//将父结点与子结点进行交换
			Swap(&a[child], &a[parent]);

			//继续向下进行调整
			parent = child;
			child = parent * 2 + 1;
		}

		//满足堆的条件
		else 
		{
			break;
		}
	}
}

void AdjustUp(HPDataType* a, int child)
{
	/*
		思路：（小堆）
		1.比较插入的目标结点与父节点的值
		2.如果目标结点小于其父结点，则交换两者的位置
		3.将原结点父结点的位置当作目标结点，继续向上进行调整
		4.当目标结点为根节点 或者 当目标结点大于父结点时，说明堆已经创建完成
	*/

	//获得父结点的下标
	int parent = (child - 1) / 2;
	while (child > 0) //调整到根结点时停止
	{
		if (a[child] < a[parent]) //孩子结点的值小于父结点的值
		{
			//交换孩子结点与父结点的位置
			Swap(&a[child], &a[parent]);

			//继续向上进行调整
			child =parent;
			parent = (child - 1) / 2;
		}
		else//已成堆
		{
			break;
		}
	}

}

//求结点树为n的二叉树的深度
int depth(int n)
{
	assert(n >= 0);

	if (n > 0)
	{
		/*	
			一开始令h=1,即2^1=2,设m=2^h
			由 2^h  -1 =n，得m-1=n
			当m<n+1,令高度加1，直到m>=n+1，说明已经达到最深处，此时停止
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

	//按照物理结构进行打印
	int i = 0;
	for (i = 0; i < php->size; i++)
	{
		printf("%d ", php->a[i]);
	}
	printf("\n");


	//按照树形结构进行打印
	int h = depth(php->size);
	int N = (int)pow(2, h) - 1; //算出与该二叉树深度是相同的满二叉树的结点总数
	int space = N - 1; //记录每一行的空格数
	int row = 1; //当前打印的行数
	int pos = 0; //待打印的下标
	while (1)
	{
		//打印前面的空格
		int i = 0; 
		for (i = 0; i < space; i++)
		{
			printf(" ");
		}
		//打印数据和间距
		int count = (int)pow(2,row - 1); //每一行的结点总数
		//printf("2^0 = %d", (int)pow(2, row - 1));
		while (count--)
		{
			printf("%d",php->a[pos++]); //打印数据
			if (pos >= php->size) //最后一行数据打印完成
			{
				printf("\n");
				return;
			}
			int distance = (space + 1) * 2;//两个数之间的空格数
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

	//判断空间是否足够
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

	//对插入的数据，向上进行调整
	AdjustUp(php->a, php->size-1);
	
}


void HeapPop(HP* php)
{
	/*
		堆的删除，删除的是堆顶，如果直接删除堆顶，会导致其它父结点与孩子结点关系混乱，须重新建堆
		导致其复杂度变大

		堆顶的删除思路：
		1.首先让堆顶和最后一个数据交换
		2.删除最后一个结点
		3.再让堆进行向下调整，这样时间复杂度就为 logN
	*/
	assert(php);
	assert(!HeapEmpty(php));
	//让堆顶和最后一个结点位置交换
	Swap(&php->a[0], &php->a[php->size - 1]);

	///删除最后一个结点（也就是删除堆顶的数据）
	php->size--;

	//堆进行向下调整
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
	*   在堆中实现升序
		思路：
		1.先创建一个大堆
		2.交换堆顶和最后一个结点位置
		3.让前n-1个结点进行向下调整算法
		4.直到最后只剩一个堆顶，即只剩一个结点停止
	*/
	assert(php);
	assert(!HeapEmpty(php));
	int i = 0;

	//用大堆方式向上调整
	for (i = (php->size - 1 - 1) / 2; i >= 0; i--)
	{
		MaxHeap(php->a, i, php->size);
	}

	//进行升序处理
	
	//记录要处理结点数
	int end = php->size;
	
	while (end > 0)
	{
		Swap(&php->a[0], &php->a[end - 1]);
		--end;//一定要end--,避免最后一个结点被处理
		MaxHeap(php->a, 0, end); //进行向下调整
	}
	
}