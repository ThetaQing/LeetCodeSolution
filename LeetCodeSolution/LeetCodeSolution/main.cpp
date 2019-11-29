
#include <iostream>
#include <bitset>
#include "basic_algorithm_array.h"
using namespace std;
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
	CArray myClass;
	vector<int> num1{ 9,9,9 };
	vector<int>num2{ 2, 2, 3, 4, 1 };
	vector<int> result;
	result = myClass.plusOne2(num1);
	for (auto i : result)
		cout << i << "\t";
	cout << endl;
	system("pause");
	return 0;
}