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
* 函数算法： 双指针法：
			1、放置两个指针 i 和 j，其中 i 是慢指针，而 j 是快指针。
			2、只要 nums[i] = nums[j]，我们就增加 j 以跳过重复项。
			3、当我们遇到 nums[j] ！= nums[i]时，跳过重复项的运行已经结束，因此我们必须把它（nums[j]）的值复制到 nums[i + 1]。
			4、递增 i，接着我们将再次重复相同的过程，直到 j 到达数组的末尾为止。
* 算法分析：时间复杂度：O(n)  24ms ，92.3%
			空间复杂度：O(1)  9.9m，81.34%
* 易错点：当输入为空的时候要单独考虑返回0，否则会返回1.
* 个人总结：和前一个算法最大的不同在于，该算法一次性解决同一个重复的数，并且是将新的数直接覆盖重复的数，减少了移动元素的时间和多次重复项的处理时间。
**/
int CArray::removeDuplicates(vector<int>& nums)
{
	if (nums.empty())
		return 0;
	int i = 0;
	for ( int j = 1; j < nums.size();++j)
	{
		if (nums[j] != nums[i])  // 直到出现没有重复的元素
		{
			i += 1;
			nums[i] = nums[j];
		}	
		
	}
	nums.erase(nums.begin() + i + 1, nums.end());  // 如果要求原数组相应发生变化的话
	return i + 1;

}