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
		if (nums[j] != nums[i] )  // 直到出现没有重复的元素
		{
			i += 1;
			if (j - i)  // 优化原地复制的部分
			{
				
				nums[i] = nums[j];
			}
			
						
		}	
		
	}
	nums.erase(nums.begin() + i + 1, nums.end());  // 如果要求原数组相应发生变化的话
	return i + 1;

}
/*************函数说明*********
* 函数名：int maxProfit(vector<int>& prices)
* 函数参数： 一个数组，第i个数表示第i天的股票价格
* 函数返回值：买卖股票所能得到的最大收益
* 问题描述：给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。

			设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。

			注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

			来源：力扣（LeetCode）
			链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii
			著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

* 函数算法：贪心算法，在这里，对于“今天的股价 - 昨天的股价”，得到的结果有 3 种可能：（1）正数（2）0（3）负数，我们只加正数。
* 算法分析：时间复杂度：O(n)  8ms， 80.18%
			
* 
**/
int CArray::maxProfit(vector<int>& prices) {
	int profit = 0;
	if (prices.empty())
		return 0;
	for (int i = 1; i < prices.size(); ++i)
	{
		if (prices[i] - prices[i - 1] > 0)  // 如果是大于0的
		{
			profit = prices[i] - prices[i - 1] + profit;  // 两天相邻的比较，大于就累计利润
		}
	}
	return profit;

}
/*************函数说明*********
* 函数名：rotate(vector<int>& nums, int k)
* 函数参数： 一个数组,翻转步数
* 函数返回值：无，地址返回翻转后的数组
* 问题描述：给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。
			题目来源：https://leetcode-cn.com/problems/rotate-array/

* 函数算法：额外使用空间暂存需要翻转到头部的元素，再从数组尾部向头部依次覆盖新元素
* 算法分析：时间复杂度：O(n)  20ms  92.11%
			空间复杂度：O(k%n)  k为翻转的步数，n为元素个数

* 注意：1、由于翻转次数可能大于数组元素个数，所以取余数
		2、在顺序部分覆盖结束后，将暂存数组的元素提取出来进行覆盖
**/
void CArray::rotate(vector<int>& nums, int k) {
	vector<int> temp;
	int len = nums.size();
	if (len <= 1)
		return;
	for (int i = len - 1; i >= len - k % len; --i)
	{
		temp.push_back(nums[i]);  // 暂存
	}
	for (int i = len - 1; i >= 0; --i)
	{
		if (i >= k%len)
			nums[i] = nums[i - k%len];  // 前len-k个元素向前移动k个位置
		else
			nums[i] = temp[k%len-i-1];  // 暂存的元素放入原数组中
	}

}