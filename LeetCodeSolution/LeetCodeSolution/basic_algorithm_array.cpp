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

* 函数算法： 比较两天的价格，如果第二天比今天价格高，今天买入，如果第二天比今天价格低且之前已买入股票，今天卖出
* 注意： 1、由于价格可能为0，所以标记已经买入股票不能用持有股票价值计算，改用了一个flag标记；
		 2、如果最后一天的价格高，则已最后一天价格卖出
* 算法分析：时间复杂度：O(n)  8ms， 80.18%
			
* 
**/
int CArray::maxProfit(vector<int>& prices) {
	int in = 0, flag = 0, profit = 0;
	if (prices.empty())
		return 0;
	for (int i = 0; i < prices.size() - 1; ++i)
	{
		if (!flag && prices[i] < prices[i + 1])  // !in表示此时没有买入，下一个数变大
		{
			in = prices[i];  // 此时买入
			flag = 1;
		}
		if (flag && prices[i] > prices[i + 1])  // 此时买入了，且下一个数变小
		{
			flag = 0; // 此时卖出
			profit = prices[i] - in + profit;  // 计算此时利润
			in = 0;  // 清空仓库
		}
		if (flag && i == prices.size() - 2)  // 此时到了数组最后但是还没有卖出
		{
			flag = 0; // 以最后一天的价格卖出
			profit = prices[i + 1] - in + profit;  // 计算此时利润
			in = 0;  // 清空仓库
		}
	}
	return profit;

}