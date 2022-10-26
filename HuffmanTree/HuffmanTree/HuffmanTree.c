#define _CRT_SECURE_NO_WARNINGS
#include"HuffmanTree.h"

void Select(HuffmanTree* HT, int n, int* s1, int* s2)
{
	int min=1;

	//找到第一个最小值

	//让第一个值成为最小值
	for (int i = 1; i <= n; i++)
	{
		if ((*HT)[i].parent == 0)
		{
			min = i;
			break;
		}
	}
	
	//后面根据权值和父节点是否为空，以及是否下于最小值，判断最小值
	for (int i = min + 1; i <= n; i++)
	{
		if ((*HT)[i].parent == 0 && (*HT)[i].weight < (*HT)[min].weight)
		{
			min = i;
		}
	}
	*s1 = min;

	//找到第二个最小值

	//找一个不等于*s1的值作为默认最小值
	//避免*s2找不到第二小的值
	for (int i = 1; i <= n; i++)
	{
		if ((*HT)[i].parent == 0 && i != (*s1))
		{
			min = i;
			break;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if ((*HT)[i].parent == 0 && (*HT)[i].weight < (*HT)[min].weight && i != (*s1))
		{
			min = i;
		}
	}
	*s2 = min;//第二个最小值给s2
}



void CreateHuffmanTree(HuffmanTree* HT, DataType* w,int n)
{
	int m = 2 * n - 1; //哈夫曼树的总结点数
	//开m+1个结点，因为下标为0的HTNode不存储数据
	*HT = (HuffmanTree)calloc(m + 1, sizeof(HTNode));

	if (*HT == NULL)
	{
		printf("calloc fail\n");
		exit(-1);
	}

	//
	for (int i = 1; i <= n; i++)
	{
		(*HT)[i].weight = w[i - 1];  //依次赋权值给n个结点
	}

	//构建哈夫曼树
	for (int i = n + 1; i <= m; i++)
	{
		//选择权值最小的s1,s2,生成他们的父节点
		int s1,s2;

		//在下标为1到i-1的范围内找到权值最小的两个值得下标，其中S1的权值小于s2的权值
		Select(HT,i-1,&s1,&s2);

		(*HT)[i].weight = (*HT)[s1].weight + (*HT)[s2].weight;
		(*HT)[s1].parent = i;
		(*HT)[s2].parent = i;
		(*HT)[i].lc = s1;
		(*HT)[i].rc = s2;

	}

	//打印哈夫曼树中各结点之间的关系
	printf("哈夫曼树为:>\n");
	printf("下标  权值  父节点  左孩子   右孩子\n");
	printf("0                                  \n");
	for (int i = 1; i <= m; i++)
	{
		printf("%-4d  %-6.2lf  %-6d  %-6d  %-6d\n",
			i, (*HT)[i].weight, (*HT)[i].parent, (*HT)[i].lc, (*HT)[i].rc
		);
	}

}



void HuffmanCoding(HuffmanTree HT, HuffmanCode* HC, int n)
{
	//HuffmanCoding(HT, &HCO, n);

	//根据下标，开n+1个空间，用于存储n个数据的哈夫曼编码，注意：下标为0的空间不用
	*HC = (HuffmanCode*)malloc(sizeof(char*) * (n + 1));
	if (*HC == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}

	//辅助空间，编码最长为n,前n-1个用于存储编码，最后一个用于存放'\0'
	char* code = (char*)malloc(sizeof(char) * n);
	if (code == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	int start = n - 1;
	code[start] = '\0';

	//依次生成每个数据的哈夫曼编码
	for (int i = 1; i <= n; i++)
	{
		
		start = n - 1; 	//每次生成数据的哈夫曼编码之前，先将start指针指向'\0'
		int c = i;//找到第i个数据 （i是数组里数据对应的下标）
		int p = HT[c].parent;//找到该数据的父结点
		while (p) //直至父结点为0，即父结点为根结点时停止
		{
			if (HT[p].lc == c)//如果该结点是父结点的左孩子，则编码为0，否则为1
			{
				code[--start] = '0';
			}
			else
			{
				code[--start] = '1';
			}
			c = p;//继续往上比较，生成编码
			p = HT[c].parent; //c的父节点
		}

	
		//char** HC;HC[i]=*(HC+1);//一级字符指针
		//在字符指针数组（二级字符指针）里，对应下标开辟空间，用于存储第i个数据的编码
		(*HC)[i] = (char*)malloc(sizeof(char) * (n - start));
		if ((*HC)[i] == NULL)
		{
			exit(-1);
		}

		//从start位置开始code里面的编码，拷贝一份给字符指针数组
		strcpy((*HC)[i], &code[start]);
	}
	free(code);//释放空间
}