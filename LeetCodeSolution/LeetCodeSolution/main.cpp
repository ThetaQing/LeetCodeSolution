
#include <iostream>
#include <bitset>
#include "windows.h"
#include<cmath>
#include <vector>
#include "basic_algorithm_linkedList.h"
#include "basic_algorithm_string.h"
#include "basic_algorithm_binaryTree.h"
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
	TreeNode root(1), Node2(2), Node3(3);
	vector<int> result;
	root.left = NULL;
	root.right = &Node2;
	Node2.left = &Node3;
	CBinaryTree myTree;
	result = myTree.postorderTraversal(&root);
	std::system("pause");
	return 0;
}