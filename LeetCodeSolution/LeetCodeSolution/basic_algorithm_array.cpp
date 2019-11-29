﻿#include "basic_algorithm_array.h"
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
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
/****************函数说明*****************
* 函数名：containsDuplicate(vector<int>& nums) 
* 函数参数：vector数组
* 函数返回值：布尔值，当输入数组中有重复元素时返回true，否则返回false
* 题目描述：217. 给定一个整数数组，判断是否存在重复元素。

如果任何值在数组中出现至少两次，函数返回 true。如果数组中每个元素都不相同，则返回 false。
* 实现思路：先排序，再比较两个相邻的数
* 时间复杂度：决定于排序算法的时间复杂度
* 其他说明：还可以用哈希表

**/
bool CArray::containsDuplicate(vector<int>& nums) {
	if (nums.size() <= 1)
		return false;
	sort(nums.begin(), nums.end());  // 排序

	int i = 1;  // 索引
	while (i < nums.size())
	{
		if (!(nums[i] - nums[i - 1]))  // 如果等于0，返回true
			return true;
		else
			i += 1;
	}
	return false;


}
/****************函数说明*****************
* 函数名：int singleNumber(vector<int>& nums)
* 函数参数：vector数组
* 函数返回值：返回那个只出现一次的元素
* 题目描述：136. 给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

说明：

你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
* 实现思路：异或运算
* 时间复杂度：O(n)
* 其他说明：还可以用哈希表

**/
int CArray::singleNumber(vector<int>& nums) {
	if (nums.size() < 1)
		throw "list index out of range";
	
	// 异或运算
	int num = 0;
	for (int i = 0; i < nums.size(); ++i)
	{
		num = num ^ nums[i];
	}
	return num;
}

/*******************函数说明*********************
* 函数名：vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
* 函数参数：两个整型数组
* 函数返回值：这两个数组的交集
* 求解思路：
		1、排序；
		2、定义两个指针，如果不相等，将小数组的指针向前移动，如果相等，push这个元素，两个指针同时移动；
		3、返回结果数组。
* 题目描述：
	350. 给定两个数组，编写一个函数来计算它们的交集。
* 提交结果：
	68.80%，12ms，9MB
**/

vector<int> CArray:: intersect(vector<int>& nums1, vector<int>& nums2)
{
	vector<int> result;  // 结果数组
	if (nums1.size() == 0 || nums2.size() == 0)
		return result;
	sort(nums1.begin(), nums1.end());
	sort(nums2.begin(), nums2.end());
	for (int i = 0, j = 0; i < nums1.size() && j < nums2.size();)
	{
		if (nums1[i] < nums2[j])  // 第一个数组i位置的数小于第二个数组j位置的数
			++i;  // 向前移动第一个数组指针
		else if (nums1[i] > nums2[j])
			++j;  // 否则的话移动第二个数组指针
		else
		{
			result.push_back(nums1[i]);  // 如果两者相等，push该元素
			++i;
			++j;  // 移动指针
		}

	}
	return result;
}
/*****************函数说明*************
* 函数名：vector<int> intersectRefer(vector<int>& nums1, vector<int>& nums2)
* 函数说明：和上面intersect函数是同一题，参考的网上题解，这是我原本的思路，只是没想到这样做的时间竟然比第一种解法更快，find函数是循环查找所有元素直到找到
* 实现方法：遍历第一个数组，对第一个数组中的每个元素在第二个数组中查找，如果找到push到结果数组中。
**/
vector<int> CArray:: intersectRefer(vector<int>& nums1, vector<int>& nums2)
{
	vector<int> res;
	vector<int>::iterator it;
	for (int i = 0; i < nums1.size(); i++)
	{
		it = find(nums2.begin(), nums2.end(), nums1[i]);
		if (it != nums2.end())//查找到元素
		{
			res.push_back(*it);
			nums2.erase(it);//删除元素
		}
	}
	return res;
}
/******************函数说明**********************
* 函数名：vector<int> plusOne(vector<int>& digits)
* 函数参数：由整数组成的数组，每个元素只存储单个数字
* 函数返回值：数组表示的整数+1后的数用数组表示
* 问题描述：
	给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。

	最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。

	你可以假设除了整数 0 之外，这个整数不会以零开头。
* 测试信息：
执行用时 :12 ms, 在所有 cpp 提交中击败了6.92%的用户
内存消耗 :8.6 MB, 在所有 cpp 提交中击败了10.91%的用户

**/

vector<int> CArray::plusOne(vector<int>& digits) {
	vector<int> result;
	int flag = 0;
	if (digits.size() == 0)
	{
		result.push_back(1);
		return result;
	}
	reverse(digits.begin(), digits.end());  // 反转
	if (digits[0] == 9)  // 如果个位数=9，进位标志置1.个位变为0
	{
		result.push_back(0);
		flag = 1;
	}
	else  // 否则直接最后一位+1
	{
		result.push_back(digits[0] + 1);
		for (int i = 1; i < digits.size(); ++i)
			result.push_back(digits[i]);

		reverse(result.begin(), result.end());
		return result;
	}
	// 如果个位是9
	for (int i = 1; i < digits.size(); ++i)
	{		
		if (digits[i] == 9 && flag)  // 如果有进位并且该位为9
		{
			result.push_back(0);
			flag = 1;
		}
		else if(flag)  // 进位到此为止
		{
			result.push_back(digits[i] + 1);
			for (int j = i+1; j < digits.size(); ++j)
				result.push_back(digits[j]);  // 将其他部分复制过来
			reverse(result.begin(), result.end());
			return result;
			
		}
		

			
	}
	if (flag)  // 循环到最后还有进位标志，说明全部都是9，有位数进位
	{		
		result.push_back(1);
	}
	reverse(result.begin(), result.end());
	return result;



}
/***************函数说明*************
* 测试结果：
	执行用时 :4 ms, 在所有 cpp 提交中击败了86.44%的用户
	内存消耗 :8.4 MB, 在所有 cpp 提交中击败了75.63%的用户

**/
vector<int> CArray::plusOne2(vector<int>& digits) {
	vector<int> result = digits;

	if (digits.size() == 0)
	{
		result.push_back(1);
		return result;
	}
	
	if (digits[digits.size() - 1] != 9)
	{
		result[result.size() - 1] = digits[digits.size() - 1] + 1;
		return result;
	}
	else
	{
		result[result.size() - 1] = 0;
		for (int i = digits.size() - 2; i >= 0; --i)
		{
			if (digits[i] == 9)
			{
				result[i] = 0;
			}
			else 
			{
				result[i] = digits[i] + 1;
				break;  // 该位不为9，不会再产生进位了，退出循环
			}

		}
		if (result[0] == 0)  // 如果首位为0，表示还有进位未处理
			result.insert(result.begin(), 1);
	}
	
	return result;

}