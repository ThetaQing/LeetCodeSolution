
#include <iostream>
#include "solution.h"
# include "basic_algorithm_array.h"
using namespace std;

int main()
{
	CArray temp;
	std::vector<int> vec = { 2,4,3,0,1};
	temp.rotate(vec,7);
	for (auto i : vec)
	{
		cout << i << "\t";
	}

	system("pause");
	return 0;
}