#define _CRT_SECURE_NO_WARNINGS
#include"HuffmanTree.h"

int main()
{

	int n = 0;
	printf("请输入数据个数:>");
	scanf("%d", &n);

	//w为存放权值的元素
	DataType* w = (DataType*)malloc(sizeof(DataType) * n);

	if (w == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	printf("请输入数据:>");
	for (int i = 0; i < n; i++)
	{
		scanf("%lf", &w[i]);
	}
	HuffmanTree HT=NULL;
	CreateHuffmanTree(&HT, w, n);//构建哈夫曼树

	//构建哈夫曼编码
	HuffmanCode HC = NULL;
	HuffmanCoding(HT, &HC, n);
	for (int i = 0; i <= n; i++)//打印哈夫曼编码
	{
		printf("数据%.2lf的编码为:%s\n", HT[i].weight, HC[i]);
	}
	free(w);

	//HuffmanTree HT=(HuffmanTree)malloc(sizeof(HuffmanTree));
	//if (HT == NULL)
	//{
	//	printf("haha\n");
	//	exit(-1);
	//}
	//HT->lc = 10;
	//HT->rc = 20;
	//HT->parent = 30;
	//printf("%d %d %d ", HT->lc, HT->rc, HT->parent);
	
	
	return 0;
}