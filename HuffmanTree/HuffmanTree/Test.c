#define _CRT_SECURE_NO_WARNINGS
#include"HuffmanTree.h"

int main()
{

	int n = 0;
	printf("���������ݸ���:>");
	scanf("%d", &n);

	//wΪ���Ȩֵ��Ԫ��
	DataType* w = (DataType*)malloc(sizeof(DataType) * n);

	if (w == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	printf("����������:>");
	for (int i = 0; i < n; i++)
	{
		scanf("%lf", &w[i]);
	}
	HuffmanTree HT=NULL;
	CreateHuffmanTree(&HT, w, n);//������������

	//��������������
	HuffmanCode HC = NULL;
	HuffmanCoding(HT, &HC, n);
	for (int i = 0; i <= n; i++)//��ӡ����������
	{
		printf("����%.2lf�ı���Ϊ:%s\n", HT[i].weight, HC[i]);
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