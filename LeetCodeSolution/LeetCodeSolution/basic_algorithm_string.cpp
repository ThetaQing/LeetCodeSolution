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


bool CString::isAnagram2(string s, string t) {

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

/*****************函数说明*****************
* 函数名：bool isPalindrome(string s)
* 函数参数：字符串
* 函数返回值：真、假，当且仅当字符串是回文串的时候输出真
* 问题描述：给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

			说明：本题中，我们将空字符串定义为有效的回文串。
* 解决方案：
		一、
			1、定义两个整型变量，分别从头、尾开始记录；
			2、因为不区分大小写，所以字母之间以距离起始字母的距离做标记，比如：
				if s[i] = 'd'
				then temp1 = s[i] - 'a';
				if s[i] = 'D'
				then temp1 = s[i] - 'A'
			3、当时数字时，以其ASCII码作为标记
			4、比较两个变量，如果不相等返回0。
		* 测试信息：
			8ms，86.36%
		二、
			1、筛选字母和数字的部分（isalnum函数）
			2、与32做或运算
			（a是在A基础上加0b100000,即十进制的32，所以大小写字母与32做或运算结果一样）

		* 测试信息：执行用时 :20 ms, 在所有 cpp 提交中击败了11.14%的用户
					内存消耗 :9.5 MB, 在所有 cpp 提交中击败了12.50%的用户
		三、
			针对思路二的起始，将思路一中判断分区用自带的宏定义实现
			比如：('A' <= s[i] && s[i] <= 'Z') || ('a' <= s[i] && s[i] <= 'z' )|| ('0' <= s[i] && s[i] <= '9')
			改为：isalnum(s[i])
		* 测试信息：执行用时 :4 ms, 在所有 cpp 提交中击败了98.85%的用户
					内存消耗 :9.2 MB, 在所有 cpp 提交中击败了57.95%的用户
**/

bool CString::isPalindrome(string s) {
	if (s.size() <= 1)
		return 1;
	int temp1, temp2;
	for (int i = 0, j = s.size() - 1; i <= j; )
	{
		if (('A' <= s[i] && s[i] <= 'Z') || ('a' <= s[i] && s[i] <= 'z' )|| ('0' <= s[i] && s[i] <= '9'))  // 只考虑字母和数字
		{	// 分区
			if ('A' <= s[i] && s[i] <= 'Z')  
				temp1 = s[i] - 'A';
			else if ('a' <= s[i] && s[i] <= 'z')
				temp1 = s[i] - 'a';
			else
				temp1 = s[i];

		}
		else
		{
			++i;
			continue;  // 如果不是有效字符，移向下一个
		}
		if (('A' <= s[j] && s[j] <= 'Z' )|| ('a' <= s[j] && s[j] <= 'z' )||( '0' <= s[j] && s[j] <= '9'))
		{
			// 分区
			if ('A' <= s[j] && s[j] <= 'Z')
				temp2 = s[j] - 'A';
			else if ('a' <= s[j] && s[j] <= 'z')
				temp2 = s[j] - 'a';
			else
				temp2 = s[j];
		}
		else
		{
			--j;
			continue;  // 如果不是有效字符，移向下一个
		}

		if (temp1 != temp2)  // 如果不相等，及时返回
			return 0;
		else  // 如果相等，进行下一个比较
		{
			++i;
			--j;
		}
	}
	return 1;
}

bool CString::isPalindrome2(string s)
{
	string str;
	for (char c : s)
	{
		if (isalnum(c)) str += c;  // 表示是否是字母或数字
	}
	for (int l = 0, r = str.size() - 1; l < r; ++l, --r)
	{
		auto temp1 = str[l] | 32;  // 表示或运算
		auto temp2 = str[r] | 32;  // A和a在二进制上的变化相当于A增加了0b100000(二进制表示32),所以与32做或运算时大小字母结果一样
		if ((str[l] | 32) != (str[r] | 32)) return false;

	}
	return true;
}
	
bool CString::isPalindrome3(string s)
{
	if (s.size() <= 1)
		return 1;
	int temp1, temp2;
	for (int i = 0, j = s.size() - 1; i <= j; )
	{
		if (isalnum(s[i]))  // 只考虑字母和数字
		{	// 分区
			if (isupper(s[i]))
				temp1 = s[i] - 'A';
			else if (islower(s[i]))
				temp1 = s[i] - 'a';
			else
				temp1 = s[i];

		}
		else
		{
			++i;
			continue;  // 如果不是有效字符，移向下一个
		}
		if (isalnum(s[j]))
		{
			// 分区
			if (isupper(s[j]))
				temp2 = s[j] - 'A';
			else if (islower(s[j]))
				temp2 = s[j] - 'a';
			else
				temp2 = s[j];
		}
		else
		{
			--j;
			continue;  // 如果不是有效字符，移向下一个
		}

		if (temp1 != temp2)  // 如果不相等，及时返回
			return 0;
		else  // 如果相等，进行下一个比较
		{
			++i;
			--j;
		}
	}
	return 1;
}
