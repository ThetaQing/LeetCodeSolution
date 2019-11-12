#include "basic_algorithm_array.h"
#include <iostream>
#include <vector>;
using namespace std;
using std::vector;
/*************文件说明***********
* 文件名： basic_algorithm_array.cpp
* 文件功能：实现LeetCode初级算法中数组部分
* 类 ：CArray类
**/

/*************函数说明*********
* 函数名：int removeDuplicates(vector<int>& nums)
* 函数参数： 一个有序数组，数组中的数可能有重复
* 函数返回值：去除重复元素之后的数组长度
* 函数算法： 用第i数与第i-1个数进行比较，相等则删除前一个数
			 此时指针不需要移动，因为数组长度减小，索引也向后移动了一个位置
			 即此时的nums[i]是数组未变化前的nums[i+1]。
			 如果不相等，移动指针到下一个位置，直到最后。
* 算法分析：执行速度慢，LeetCode运行时间260ms，12.32%			

**/
int CArray::removeDuplicates(vector<int>& nums)
{
	int len = nums.size();

	for (int i = 1; i < len; )
	{
		if (i >= 1 && nums[i] == nums[i - 1])
		{
			nums.erase(nums.begin() + i - 1);
			len = nums.size();
			// i不需要发生变化就已经移动了，因为长度发生了变化，索引随之变化
		}
		else
		{
			i += 1;

		}

	}
	return len;

}