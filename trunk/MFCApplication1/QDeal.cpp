#include "stdafx.h"

#include "QDeal.h"


#include <iostream>
#include <fstream>

using namespace std;

//解析查询请求

//按照请求解析文件

//返回结果

/*
数据库格式为:
{药物名称A;中成药1，中成药2;蛋白;导致某毒性某衰竭;}回车{药物名称B;中成药3，中成药1;蛋白;导致某毒性某衰竭;}



如果条目某项不存在,则在数据中用*号表示.

每个条目最后都跟着“;}”

建议：如果欲图解析更多,例如通过中成药名称名称解析出所涉及的东西.第二项涉及中成药名录如果存在(不为*)，则两项之前用中文符号“、“进行了分隔（最后一个子项没有“、“）。注意，其他项目中也可能存在“、”。

2015年10月15日 18:45:35
冰刃科学家

*/






int QueryInfromation( char* cQName, char* cNames, char* cComponents, char* cToxicology)
{

	ifstream in("中药毒性数据库.dat");
	if (!in)
	{
		cout << "无法打开数据库文件" << endl;
		return 2;
	}

	char cData[2048] = { '\0' };//药物名字



	while (in)
	{

		char c = in.get();
		if (in)
		{
			//cout << c;
			if (c == '{')
			{
				//读取第一个字段并匹配,失败
				in.getline(cData, 1024, ';');//用';'作为分隔
				if (0 == strcmp(cData, cQName))
				{
					//填充各属性并结束查询.

					//返回 涉及中成药名称
					in.getline(cData, 2047, ';');//用';'作为分隔
					strcpy_s(cNames,2047,cData);

					//返回 有害成分
					in.getline(cData, 2047, ';');//用';'作为分隔
					strcpy_s(cComponents, 2047, cData);
					
					//返回 作用机理及毒性
					in.getline(cData, 2047, ';');//用';'作为分隔
					strcpy_s(cToxicology, 2047, cData);

					in.close();
					return 1;
				}
				else
				{
					//继续找到下一个
					//system("pause");
				}
			}
		}


	}
	in.close();
	//没找到返回0

	return 0;

}





