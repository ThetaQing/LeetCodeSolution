#include <unordered_map>
#include <iostream>
#include<string>
using namespace std;
/*************文件说明******************
* 文件名：basic_algorithm_string.cpp
* 文件功能：实现LeetCode初级算法字符串内容

*
*/

/****************函数说明*****************
* 函数名：bool isAnagram(string s, string t) 
* 函数参数：两个字符组成的string
* 函数返回：真、假，当且仅当两个string组成元素完全一样时返回真
* 问题描述：给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
* 算法思路：
	1、遍历字符串，将其分别加入到两个哈希表中
	2、遍历字符串，查询哈希表中的存储的该字符出现的次数是否一致，不一致返回false
	3、退出循环后，返回true，说明两个哈希表元素组成和出现次数一致
* 测试信息：
20ms  49.71%

*/
bool isAnagram(string s, string t) 
{
	int n1 = s.size(), n2 = t.size();
	if (n1 == 0 && n2 == 0)
		return 1;
	if (n1 != n2 || n1 == 0 || n2 == 0)
		return 0;
	int len = min(26, n1);
	unordered_map<char, int>smap(len), tmap(len);
	for (int i = 0; i < n1; ++i)
	{
		smap[s[i]] += 1;
		tmap[t[i]] += 1;
	}
	for (int i = 0; i < s.size(); ++i)
	{
		if (smap[s[i]] != tmap[s[i]])
			return 0;
	}
	return 1;
}