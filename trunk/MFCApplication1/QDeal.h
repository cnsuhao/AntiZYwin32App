/*
�������ṩ�ض���ʽ���ı���������.

*/


/*
$$����:
����һ������ѯҩ��"����"
���:�漰�г�ҩ����,�ɷ�,���� ��Ϣ.

$$����ֵ:
0:δ�ҵ���ҩ��.
1:�ҵ��˸�ҩ��.
2:���ݿ��ļ��޷���.

$$����:
IN const char cQName[]
�����д�����"ҩ������"���ַ�������.

OUT  char cNames[]
�����ѯ�ɹ�,�򽫸�ҩ���漰�г�ҩ���Ʒ�������.

OUT char cComponents[]
�����ѯ�ɹ�,��ҩ��ɷַ�������.

OUT char cToxicology[]
�����ѯ�ɹ�,�򽫶�����Ϣ��������.

*/
int QueryInfromation
	(
		IN  char* cQName,
		OUT char* cNames,
		OUT char* cComponents,
		OUT char* cToxicology
	);

