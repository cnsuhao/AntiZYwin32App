#include "stdafx.h"

#include "QDeal.h"


#include <iostream>
#include <fstream>

using namespace std;

//������ѯ����

//������������ļ�

//���ؽ��

/*
���ݿ��ʽΪ:
{ҩ������A;�г�ҩ1���г�ҩ2;����;����ĳ����ĳ˥��;}�س�{ҩ������B;�г�ҩ3���г�ҩ1;����;����ĳ����ĳ˥��;}



�����Ŀĳ�����,������������*�ű�ʾ.

ÿ����Ŀ��󶼸��š�;}��

���飺�����ͼ��������,����ͨ���г�ҩ�������ƽ��������漰�Ķ���.�ڶ����漰�г�ҩ��¼�������(��Ϊ*)��������֮ǰ�����ķ��š����������˷ָ������һ������û�С���������ע�⣬������Ŀ��Ҳ���ܴ��ڡ�������

2015��10��15�� 18:45:35
���п�ѧ��

*/






int QueryInfromation( char* cQName, char* cNames, char* cComponents, char* cToxicology)
{

	ifstream in("��ҩ�������ݿ�.dat");
	if (!in)
	{
		cout << "�޷������ݿ��ļ�" << endl;
		return 2;
	}

	char cData[2048] = { '\0' };//ҩ������



	while (in)
	{

		char c = in.get();
		if (in)
		{
			//cout << c;
			if (c == '{')
			{
				//��ȡ��һ���ֶβ�ƥ��,ʧ��
				in.getline(cData, 1024, ';');//��';'��Ϊ�ָ�
				if (0 == strcmp(cData, cQName))
				{
					//�������Բ�������ѯ.

					//���� �漰�г�ҩ����
					in.getline(cData, 2047, ';');//��';'��Ϊ�ָ�
					strcpy_s(cNames,2047,cData);

					//���� �к��ɷ�
					in.getline(cData, 2047, ';');//��';'��Ϊ�ָ�
					strcpy_s(cComponents, 2047, cData);
					
					//���� ���û�������
					in.getline(cData, 2047, ';');//��';'��Ϊ�ָ�
					strcpy_s(cToxicology, 2047, cData);

					in.close();
					return 1;
				}
				else
				{
					//�����ҵ���һ��
					//system("pause");
				}
			}
		}


	}
	in.close();
	//û�ҵ�����0

	return 0;

}





