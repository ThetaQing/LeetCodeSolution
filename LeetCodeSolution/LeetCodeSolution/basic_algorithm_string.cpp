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

/*****************函数说明****************
* 函数名：int myAtoi(string str) 
* 函数参数：待转换字符串
* 函数返回值：返回一个整数，如果字符串能转换成整数，返回该整数，否则返回0
* 问题描述：
	请你来实现一个 atoi 函数，使其能将字符串转换成整数。

	首先，该函数会根据需要丢弃无用的开头空格字符，直到寻找到第一个非空格的字符为止。

	当我们寻找到的第一个非空字符为正或者负号时，则将该符号与之后面尽可能多的连续数字组合起来，作为该整数的正负号；假如第一个非空字符是数字，则直接将其与之后连续的数字字符组合起来，形成整数。

	该字符串除了有效的整数部分之后也可能会存在多余的字符，这些字符可以被忽略，它们对于函数不应该造成影响。

	注意：假如该字符串中的第一个非空格字符不是一个有效整数字符、字符串为空或字符串仅包含空白字符时，则你的函数不需要进行转换。

	在任何情况下，若函数不能进行有效的转换时，请返回 0。
* 解决方案：
	1、定义符号标志和开始查找标志flag（一个变量做两次标志），数组用于存储查找到的所有有效字符
	2、遍历字符串
		当尚且没有非空字符出现时
		(1) 如果是空白字符，continue；
		(2) 如果第一个非空字符是符号位，flag变为1，表示开始搜索连续整数；
		(3) 如果第一个非空字符是其他字符，无法转换，返回0；
		(4) 如果第一个非空字符是数字，flag变为1，表示开始搜索连续整数序列。
		当开始搜索整数时
		(1) 遇到非数字字符退出循环，停止搜索；
		(2) 对于数字字符，入栈。
	3、遍历数组
		首先判断符号位，用flag变量保存；
		在判断是否溢出
		最后转换
	4、返回转换后的整数与符号位的乘积
* 测试信息：
	执行用时 :4 ms, 在所有 cpp 提交中击败了92.60%的用户
	内存消耗 :8.7 MB, 在所有 cpp 提交中击败了75.58%的用户

**/

int CString::myAtoi(string str) 
{
	int n = str.size();
	int result = 0;
	int flag = 0;  //标志位，是否找到有效字符
	vector<char> ans;
	if (str.size() <= 0)
		return 0;
	for (int i = 0; i < n; ++i)
	{
		if (!flag)
		{
			if (isblank(str[i]))
				continue;  // 如果是开头，继续查找

			else if (str[i] == '-' || str[i] == '+')  // 如果非空字符是符号位
			{
				ans.push_back(str[i]);
				flag = 1;
			}
			else if (!isdigit(str[i]))  //  如果不是符号位也不是空白也不是数字，表示不能进行转换
				return 0;
			else if (isdigit(str[i]))  // 如果是数字，添加
			{
				ans.push_back('+');  // 主要是为了对称，在循环的时候可以设起始位置为1，而不是0
				ans.push_back(str[i]);
				flag = 1;
				
			}
			

		}
		else if (flag)  // 如果找到了第一个有效字符
		{
			if (!isdigit(str[i]))  // 下一个不为整数的
				break;  // 如果已经有有效字符了，退出循环
			else if (isdigit(str[i]))
				ans.push_back(str[i]);

		}		
		

	}
	if (ans.size() <= 1)
		return 0;  // 没有找到有效的
	// 判断符号位
	if (ans[0] == '-')
		flag = -1;
	else
		flag = 1;
	for (int i = 1; i < ans.size(); ++i)
	{	
		if (result > INT_MAX / 10)  // 如果大于INT_MAX/10说明该数*10之后超出表达范围
			return (flag>0) ? INT_MAX : INT_MIN;  // 判断符号
		else if (result == INT_MAX / 10)  // 如果等于
		{
			if (ans[i] - '0' >= 8)  // 判断这个位置的数是否大于8，（INT_MAX的个位为7，INT_MIN的个位为8）如果大于8，不能被表示，等于8，刚好表示INT_MIN，返回还是INT_MIN
				return (flag > 0) ? INT_MAX : INT_MIN;		
		}
		result = result * 10 + (ans[i] - '0');
		
	}
	return flag * result;

}

/******************函数说明******************
* 修改信息：
	取消了数组的使用，添加了符号位标志，在遍历字符串的过程中直接进行转换和溢出检测
* 测试信息：
	执行用时 :8 ms, 在所有 cpp 提交中击败了65.27%的用户
	内存消耗 :8.4 MB, 在所有 cpp 提交中击败了88.51%的用户

* 备注：相同的思路，为什么会比第一种方法慢呢，空间使用也没有少多少，emmmm
**/

int CString::myAtoi2(string str)
{
	int n = str.size();
	int result = 0;
	int startFlag = 0;  //标志位，是否找到有效字符
	char symbolFlag = '-';  // 符号标志
	vector<char> ans;
	if (str.size() <= 0)
		return 0;
	for (int i = 0; i < n; ++i)
	{
		if (!startFlag)
		{
			if (isblank(str[i]))
				continue;  // 如果是开头，继续查找

			else if (str[i] == '-' || str[i] == '+')  // 如果非空字符是符号位
			{
				symbolFlag = symbolFlag ^ str[i];  // 初始symbolFlag为'-'，如果是'-'，返回空，否则返回非空
				startFlag = 1;
			}
			else if (!isdigit(str[i]))  //  如果不是符号位也不是空白也不是数字，表示不能进行转换
				return 0;
			else if (isdigit(str[i]))  // 如果是数字，添加
			{
				symbolFlag = '+';
				result = result + str[i] - '0';  // 第一个值
				startFlag = 1;

			}


		}
		else // 开始搜索
		{
			if (!isdigit(str[i]))  // 下一个不为整数的
				break;  // 如果已经有有效字符了，退出循环
			else if (isdigit(str[i]))
			{
				if (result > INT_MAX / 10)  // 如果大于INT_MAX/10说明该数*10之后超出表达范围
					return symbolFlag ? INT_MAX : INT_MIN;  // 判断符号
				else if (result == INT_MAX / 10)  // 如果等于
				{
					if (str[i] - '0' >= 8)  // 判断这个位置的数是否大于8，（INT_MAX的个位为7，INT_MIN的个位为8）如果大于8，不能被表示，等于8，刚好表示INT_MIN，返回还是INT_MIN
						return symbolFlag ? INT_MAX : INT_MIN;
				}
				result = result * 10 + (str[i] - '0');

			}


		}


	}
	if (symbolFlag)
		return result;
	else
		return -1 * result;

}

/********************函数说明*****************
* 函数名：string countAndSay(int n)
* 函数返回值：第n个报数序列
* 问题描述：
	报数序列是一个整数序列，按照其中的整数的顺序进行报数，得到下一个数。其前五项如下：

	1.     1
	2.     11
	3.     21
	4.     1211
	5.     111221
	1 被读作  "one 1"  ("一个一") , 即 11。
	11 被读作 "two 1s" ("两个一"）, 即 21。
	21 被读作 "one 2",  "one 1" （"一个二" ,  "一个一") , 即 1211。

	给定一个正整数 n（1 ≤ n ≤ 30），输出报数序列的第 n 项。

	注意：整数顺序将表示为一个字符串。

* 解决方案：
	1、定义生成下一字符串的函数nextString(),
	2、迭代生成第n个字符串
	3、返回

* 测试信息：
	执行用时 :4 ms, 在所有 cpp 提交中击败了90.24%的用户
	内存消耗 :8.7 MB, 在所有 cpp 提交中击败了78.36%的用户




*/

string CString::countAndSay(int n) {
	string ans = "1";
	
	for (int i = 1; i < n; ++i)
	{
		ans = nextString(ans);
	}
	
	return ans;
}
/************函数说明***************
* 函数名：string nextString(string s)
* 函数参数：该时刻的字符串；
* 函数返回值：根据上述的报数规律得到下一时刻的字符串
* 函数实现：
		1、定义一个数组，每次存储相同字符；定义一个临时变量存储上一时刻的字符；
		2、如果两个时刻的字符相同，继续向mys数组中添加该字符；
		3、如果字符不相同，将前一个字符的统计信息加入到ans字符串中，然后更新temp值并清空数组
		4、如果到了最后一个字符，将该字符的统计信息加入到ans字符串中，并退出
		5、返回ans字符串
***/
string CString::nextString(string s)  // 生成序列
{
	string ans;
	vector<char> mys;
	
	char temp = s[0];
	for (int i = 0; i < s.size(); ++i)
	{
		
		if (temp == s[i])  // 如果是同一个字符
			mys.push_back(s[i]);
		
		else
		{
			int n = mys.size();
			ans.push_back(n + '0');  // n个
			ans.push_back(temp);  // temp表示的字符
			temp = s[i];  // 重新开始
			mys.clear();  // 清空
			mys.push_back(s[i]);
		}
		if (i == s.size() - 1)
		{
			int n = mys.size();
			ans.push_back(n + '0');  // n个
			ans.push_back(temp);  // temp表示的字符
			temp = s[i];  // 重新开始
			mys.clear();  // 清空
			break;
		}
	}
	return ans;
}
// 生成序列
// 更改信息：取消数组使用，直接定义变量存储长度
string CString::nextString2(string s)  // 生成序列
{
	string ans;
	int len = 0;  // 字符长度

	char temp = s[0];
	for (int i = 0; i < s.size(); ++i)
	{

		if (temp == s[i])  // 如果是同一个字符
			len += 1;

		else
		{
			
			ans.push_back(len + '0');  // n个
			ans.push_back(temp);  // temp表示的字符
			temp = s[i];  // 重新开始
			len = 1;
		}
		
	}
	// 最后一个字符
	ans.push_back(len + '0');  // n个
	ans.push_back(temp);  // temp表示的字符
	
	return ans;
}

/**************函数说明***************
* 函数名：string longestCommonPrefix(vector<string>& strs) 
* 函数参数：待查找的字符串数组
* 函数返回值：返回字符串，公共前缀
* 问题描述：
	编写一个函数来查找字符串数组中的最长公共前缀。

	如果不存在公共前缀，返回空字符串 ""。

* 实现方案：
	1、两层循环，外层是控制公共前缀的，当通过内层循环，公共前缀中入栈下一个字符；
		通过第一个字符串控制公共前缀添加新字符
	2、内层循环，检测该数组中所有的字符串是否都含有这个公共前缀
		如果没有查到，pop最后一个字符并返回
* 测试信息：
		4 ms  95.20%
**/

string CString::longestCommonPrefix(vector<string>& strs) {
	
	if (strs.empty())
		return "";
	string ans = "";
	
	int n = strs.size();
	int j = 0;
	while(1)
	{
		
		for (int i = 0; i < n; ++i)
		{
			if (strs[i].find(ans) != 0)  // 查找前缀，如果是公共前缀，那么返回位置为0
			{
				ans.pop_back();  // 如果没有找到，pop最后一个字符并返回
				return ans;
			}

		}
		if (j < strs[0].size())  // 以第一个字符串为公共前缀添加新的字符
			ans.push_back(strs[0][j]);
		else
			break;
		j += 1;  // 下一个字符的位置
	}
	
	
	return ans;
}

