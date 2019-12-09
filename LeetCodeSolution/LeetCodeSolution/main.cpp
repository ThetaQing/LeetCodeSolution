
#include <iostream>
#include <bitset>
#include "windows.h"
#include<cmath>
#include "basic_algorithm_string.h"
using namespace std;

using namespace std;
void heartShaped()
{
	float x, y;
	char heart;
	heart = 'a' ^ 'b';
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);  // 设置颜色输出为红色~~~
	for (y = 1.5f; y > -1.5f; y -= 0.1f)
	{
		for (x = -1.5f; x < 1.5f; x += 0.05f)
		{
			float a = x * x + y * y - 1;
			if ((a * a * a - x * x * y * y * y) <= 0)//心形方程
				cout <<heart;
			else cout << " ";
		}
		cout << endl;
	}
	
}

int int2bit(int n)
{
	bitset<sizeof(int) * 1> bn(n);
	int count=0;
	for (int i = 0; i < sizeof(int) * 1; ++i)
	{
		cout << bn[i];
	}
	return count;
}



int main()
{
	CString myClass;
	
	string s = "aA";
	
	int re= myClass.isPalindrome2(s);
	cout << re << endl;
	std::system("pause");
	return 0;
}