
#ifndef  basic_algorithm_string_
#define basic_algorithm_string_
#include <string>
#include <iostream>
using namespace std;
class CString
{
public:
	bool isAnagram(string s, string t);  // 判断两个字符是否是异位词
	int firstUniqChar(string s);  
	bool isAnagram2(string s, string t);  // 找到字符串中第一个无重复的字符；
	bool isPalindrome(string s);  
	bool isPalindrome2(string s); 
	bool isPalindrome3(string s);  // 判断是否是回文数
	int myAtoi(string str);  
	int myAtoi2(string str);  // 字符串转整数
	string nextString(string s);
	string nextString2(string s);
	string countAndSay(int n);
	string longestCommonPrefix(std::vector<string>& strs);
};



#endif // ! basic_algorithm_string_


#pragma once
