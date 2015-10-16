/*
本代码提供特定格式的文本解析功能.

*/


/*
$$作用:
输入一个待查询药物"名称"
输出:涉及中成药名称,成分,毒理 信息.

$$返回值:
0:未找到该药物.
1:找到了该药物.
2:数据库文件无法打开.

$$参数:
IN const char cQName[]
包含有待查找"药物名称"的字符串数组.

OUT  char cNames[]
如果查询成功,则将该药物涉及中成药名称放在其中.

OUT char cComponents[]
如果查询成功,则将药物成分放在其中.

OUT char cToxicology[]
如果查询成功,则将毒理信息放在其中.

*/
int QueryInfromation
	(
		IN  char* cQName,
		OUT char* cNames,
		OUT char* cComponents,
		OUT char* cToxicology
	);

