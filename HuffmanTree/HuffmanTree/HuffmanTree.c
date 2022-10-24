#define _CRT_SECURE_NO_WARNINGS
#include"HuffmanTree.h"

void Select(HuffmanTree* HT, int n, int* s1, int* s2)
{
	int min=1;

	//�ҵ���һ����Сֵ

	//�õ�һ��ֵ��Ϊ��Сֵ
	for (int i = 1; i <= n; i++)
	{
		if ((*HT)[i].parent == 0)
		{
			min = i;
			break;
		}
	}
	
	//�������Ȩֵ�͸��ڵ��Ƿ�Ϊ�գ��Լ��Ƿ�������Сֵ���ж���Сֵ
	for (int i = min + 1; i <= n; i++)
	{
		if ((*HT)[i].parent == 0 && (*HT)[i].weight < (*HT)[min].weight)
		{
			min = i;
		}
	}
	*s1 = min;

	//�ҵ��ڶ�����Сֵ

	//��һ��������*s1��ֵ��ΪĬ����Сֵ
	//����*s2�Ҳ����ڶ�С��ֵ
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
	*s2 = min;//�ڶ�����Сֵ��s2
}



void CreateHuffmanTree(HuffmanTree* HT, DataType* w,int n)
{
	int m = 2 * n - 1; //�����������ܽ����
	//��m+1����㣬��Ϊ�±�Ϊ0��HTNode���洢����
	*HT = (HuffmanTree)calloc(m + 1, sizeof(HTNode));

	if (*HT == NULL)
	{
		printf("calloc fail\n");
		exit(-1);
	}

	//
	for (int i = 1; i <= n; i++)
	{
		(*HT)[i].weight = w[i - 1];  //���θ�Ȩֵ��n�����
	}

	//������������
	for (int i = n + 1; i <= m; i++)
	{
		//ѡ��Ȩֵ��С��s1,s2,�������ǵĸ��ڵ�
		int s1,s2;

		//���±�Ϊ1��i-1�ķ�Χ���ҵ�Ȩֵ��С������ֵ���±꣬����S1��ȨֵС��s2��Ȩֵ
		Select(HT,i-1,&s1,&s2);

		(*HT)[i].weight = (*HT)[s1].weight + (*HT)[s2].weight;
		(*HT)[s1].parent = i;
		(*HT)[s2].parent = i;
		(*HT)[i].lc = s1;
		(*HT)[i].rc = s2;

	}

	//��ӡ���������и����֮��Ĺ�ϵ
	printf("��������Ϊ:>\n");
	printf("�±�  Ȩֵ  ���ڵ�  ����   �Һ���\n");
	printf("0                                  \n");
	for (int i = 1; i <= m; i++)
	{
		printf("%-4d  %-6.2lf  %-6d  %-6d  %-6d\n",
			i, (*HT)[i].weight, (*HT)[i].parent, (*HT)[i].lc, (*HT)[i].rc
		);
	}

}



void HuffmanCoding(HuffmanTree HT, HuffmanCode* HC, DataType n)
{
	//��n+1���ռ䣬��Ϊ�±�Ϊ0�Ŀռ䲻��
	HC = (char**)malloc(sizeof(char*) * (n + 1));
	if (HC == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}

	//�����ռ䣬�����Ϊn,ǰn-1�����ڴ洢���룬���һ�����ڴ��'\0'
	char* code = (char*)malloc(sizeof(char*) * n);
	if (code == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	int start = n - 1;
	code[start] = '\0';

	//���ɹ���������
	for (int i = 1; i <= n; i++)
	{
		//ÿ���������ݵĹ���������֮ǰ���Ƚ�startָ��ָ��'\0'
		 start = n - 1;
		int c = i;//���ڽ��еĵ�i�����ݵı���
		int p = HT[i].parent;//�ҵ������ݵĸ����
		while (p) //ֱ�������Ϊ0���������Ϊ�����ʱֹͣ
		{
			if (HT[i].lc == c)//����ý��ʱ�丸�������ӣ������Ϊ0������Ϊ1
			{
				code[--start] = '0';
			}
			else
			{
				code[--start] = '1';
			}
			c = p;//�������ϼ�������
			p = HT[c].parent; //c�ĸ��ڵ�
		}

		//�������ڴ洢������ڴ�ռ�
		HC[i] = (char*)malloc(sizeof(char) * (n - start));
		if (HC[i] == NULL)
		{
			exit(-1);
		}
		strcpy(HC[i], & code[start]);
	}
	free(code);//�ͷſռ�
}