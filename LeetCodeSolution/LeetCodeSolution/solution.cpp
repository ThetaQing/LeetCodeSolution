#include <stack>
#include <iostream>
#include <string>
#include "solution.h"
using namespace std;


int CSolution:: balancedStringSplit(std::string s)
{
	stack <char> temp_stack;
	int count = 0;  //计数
	for (int i = 0; i < s.size(); ++i)
	{
		if (temp_stack.empty())
		{
			temp_stack.push(s[i]);
		}
		else
		{
			if (s[i] == temp_stack.top())
				temp_stack.push(s[i]);
			else
				temp_stack.pop();
		}
		// 如果是空，+1，注意这里要放在pop和push的后面
		if (temp_stack.empty())
			count = count + 1;
	}
	return count;

}
int CSolution::add(int i, int j)
{
	return i + j;
}
