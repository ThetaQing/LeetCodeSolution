
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
	vector<int> num1{ 2,7,11,15 };
	vector<int>num2{ 2, 2, 3, 4, 1 };
	//vector<int> result;
	vector<vector<int>> board = {
		{1,2,3},
		{4,5,6},
		{7,8,9}

	};
	myClass.rotate(board);
	
	for (auto i : board)
	{
		for (auto j : i)
			cout << j << "\t";
		cout << endl;
	}
	
	
	std::system("pause");
	return 0;
}