
#include <iostream>
#include "solution.h"
using namespace std;

int main()
{
	CSolution temp;
	string s = "RL";
	int count = 0;
	count = temp.balancedStringSplit(s);
	cout << count << endl;
	system("pause");
	return 0;
}