#include <unordered_map>
#include <iostream>
#include<string>
#include <algorithm>
#include "basic_algorithm_string.h"
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
	一、
		1、遍历字符串，将其分别加入到两个哈希表中
		2、遍历字符串，查询哈希表中的存储的该字符出现的次数是否一致，不一致返回false
		3、退出循环后，返回true，说明两个哈希表元素组成和出现次数一致
	* 测试信息：
		20ms  49.71%
	二、
		1、定义一个数组计数，用s串计数+1，t串计数-1
		2、遍历数组，如果出现非0部分，说明不匹配
	* 测试信息：
		执行用时 :8 ms, 在所有 cpp 提交中击败了97.04%的用户
		内存消耗 :9.6 MB, 在所有 cpp 提交中击败了5.31%的用户
	三、
		1、定义一个数组计数，用s串计数+1，t串计数-1
		2、遍历s串，+1计数；
		3、遍历t串，-1计数，并判断一旦有<0的返回false；
		（因为定义了如果两个串长度不等提前返回，所以有>0的就一定有<0的）
		4、退出循环，返回true
*/
bool CString::isAnagram(string s, string t) 
{
	int n1 = s.size(), n2 = t.size();
	if (n1 == 0 && n2 == 0)
		return 1;
	if (n1 != n2 || n1 == 0 || n2 == 0)
		return 0;
	int len = min(26, n1);
	unordered_map<char, int>smap(len), tmap(len);  // 定义哈希
	for (int i = 0; i < n1; ++i)
	{
		smap[s[i]] += 1;  // s串关键字
		tmap[t[i]] += 1;  // t串关键字
	}
	for (int i = 0; i < s.size(); ++i)
	{
		if (smap[s[i]] != tmap[s[i]])  // 如果相同关键字的值不相同说明不匹配
			return 0;
	}
	return 1;
}


bool isAnagram2(string s, string t) {

	int n1 = s.size(), n2 = t.size();
	if (n1 == 0 && n2 == 0)
		return 1;
	if (n1 != n2 || n1 == 0 || n2 == 0)
		return 0;

	int *my_array = new int[26]();  // 定义数组

	for (int i = 0; i < n1; ++i)
	{
		my_array[s[i] - 'a'] += 1;  // s串+1计数
		my_array[t[i] - 'a'] -= 1;  // t串-1计数
	}
	for (int i = 0; i < 26; ++i)
	{
		
		if (my_array[i] != 0)  // 如果最后有不为0 的，说明不匹配
			return 0;
	}
	return 1;

}




/****************函数说明*****************
* 函数名：int firstUniqChar(string s)
* 函数参数：字符组成的string
* 函数返回：找到第一个不重复的字符
* 问题描述：给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。
* 算法思路：
			1、将所有字符添加到哈希表中，如果该字符有重复，该关键字的值变为-1，否则是该字符的索引；
			2、遍历哈希表，第一个值不为-1的关键字即为第一个不重复的字符。
	
* 测试信息：
19.04%

*/
//
int CString::firstUniqChar(string s)
{
	// 哈希表
	if (s.size() < 1)
		return 0;

	unordered_map<char, int> mymap;
	for (int i = 0; i < s.size(); ++i)
	{
		if (mymap.count(s[i]))  // 如果能够找到该字符，证明有重复
			mymap[s[i]] = -1;  // 将该关键字的计数变为0
		else
			mymap[s[i]] = i;  // 记录索引

	}
	for (int i = 0; i < s.size(); ++i)
	{
		if (mymap[s[i]] != -1)
			return mymap[s[i]];
	}
	return 0;
}

//未成功

bool isPalindrome(string s) {
	if (s.size() <= 1)
		return 1;
	int temp1, temp2;
	for (int i = 0, j = s.size() - 1; i < j; )
	{
		if (('A' <= s[i] <= 'Z' || 'a' <= s[i] <= 'z' || '0' <= s[i] <= '9'))  // 只考虑字母和数字
		{
			if ('A' <= s[i] <= 'Z')
				temp1 = s[i] - 'A';
			else if ('a' <= s[i] <= 'z')
				temp1 = s[i] - 'a';
			else
				temp1 = s[i] - '1';

		}
		else
		{
			++i;
			continue;
		}
		if ('A' <= s[j] <= 'Z' || 'a' <= s[j] <= 'z' || '0' <= s[j] <= '9')
		{
			if ('A' <= s[j] <= 'Z')
				temp2 = s[j] - 'A';
			else if ('a' <= s[j] <= 'z')
				temp2 = s[j] - 'a';
			else
				temp2 = s[j] - '1';
		}
		else
		{
			--j;
			continue;
		}

		if (temp1 != temp2)
			return 0;
	}
	return 1;
}

