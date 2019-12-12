#include "basic_algorithm_array.h"
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <string>
#include <unordered_map>
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
* 实现过程：（这种实现方法是调用默认构造函数，下一种实现方法是调用的复制构造函数）
		1、结果数组为空，将输入数组翻转；
		2、判断个位是否为9，为9，result数组push 0，进入第三步，否则进入第四步；
		3、从下一位开始遍历数组，如果第i位为9，该位置0，否则进入第四步；
		4、将原数组其他元素复制到result中，翻转result并返回；
		5、如果数组仍然没有返回，说明此时最高位为0，push 1，翻转数组并返回。
* 测试信息：
执行用时 :4 ms, 在所有 cpp 提交中击败了86.44%的用户
内存消耗 :8.6 MB, 在所有 cpp 提交中击败了10.91%的用户

**/

vector<int> CArray::plusOne(vector<int>& digits) {
	vector<int> result;

	if (digits.size() == 0)
	{
		result.push_back(1);
		return result;
	}
	reverse(digits.begin(), digits.end());  // 反转
	if (digits[0] == 9)  // 如果个位数=9，进位标志置1.个位变为0
	{
		result.push_back(0);
		
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
		if (digits[i] == 9)  // 如果有进位并且该位为9
		{
			result.push_back(0);
			
		}
		else   // 进位到此为止
		{
			result.push_back(digits[i] + 1);
			for (int j = i+1; j < digits.size(); ++j)
				result.push_back(digits[j]);  // 将其他部分复制过来
			reverse(result.begin(), result.end());
			return result;
			
		}
		

			
	}
	
	result.push_back(1);

	reverse(result.begin(), result.end());
	return result;



}
/***************函数说明*************
* 函数名:plusOne2(vector<int>& digits)
* 函数说明：和上一个同一题，不同解法
			该解法更简单明了：
				1、复制该数组
				2、判断最后一位，如果不是9，最后一位+1，否则进入第三步；
				3、将该位置为0，开始向前遍历数组其他部分；
				4、若i位不为9，i位数+1后退出循环，否则将i位置0，++i；
				5、回到第4步，直到退出循环；
				6、判断结果数组的第0位，若为0，表示尚有进位，在数组头节点处插入1，返回数组。
* 测试结果：
	执行用时 :4 ms, 在所有 cpp 提交中击败了86.44%的用户
	内存消耗 :8.4 MB, 在所有 cpp 提交中击败了75.63%的用户

**/
vector<int> CArray::plusOne2(vector<int>& digits) {
	vector<int> result = digits;  // 复制输入的数组

	if (digits.size() == 0) 
	{
		result.push_back(1);
		return result;
	}
	
	if (digits[digits.size() - 1] != 9) // 先判断最后一个数，如果不是9，个位+1，直接返回
	{
		result[result.size() - 1] = digits[digits.size() - 1] + 1;
		return result;
	}
	else  // 最后一位为9，表明有进位
	{
		result[result.size() - 1] = 0;  // 将最后一位置0，此时有进位
		for (int i = digits.size() - 2; i >= 0; --i)  // 遍历数组
		{
			if (digits[i] == 9)  // 如果仍为9，该位置0
			{
				result[i] = 0;
			}
			else   // 否则的话，该位+1，进位结束，退出循环
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
/*****************函数说明*******************
* 函数名：vector<int> plusOneRefer(vector<int>& digits)
* 函数说明：参考大佬题解
			一共只有两种情况出现：一种是非9无进位，一种是9+1进位变为0
			所以只要从最后一位开始，每一位+1取除10的余数，如果取余之后不为0，进位结束，返回数组；
			否则继续做+1运算
			如果没有从循环中返回，说明最高位进位变为了0，此时在数组头节点处插入1并返回。
* 算法对比：思路更清晰，代码更简洁
* 测试结果：
	执行用时 :4 ms, 在所有 cpp 提交中击败了86.44%的用户
	内存消耗 :8.6 MB, 在所有 cpp 提交中击败了10.38%的用户

**/
vector<int> CArray::plusOneRefer(vector<int>& digits)
{
	for (int i = digits.size() - 1; i >= 0; --i)
	{
		digits[i] = (digits[i] + 1) % 10;  // 取除10的余数即可
		if (digits[i] != 0)  // 如果该位不为0，表明进位结束
			return digits;
	}
	// 如果没有从循环中返回，表明最高位为0
	digits.insert(digits.begin(), 1);  // 在头节点处插入元素1
	return digits;
}

/************************函数说明***************
* 函数名：void moveZeroes(vector<int>& nums)
* 函数参数：一个整型数组
* 函数返回值：地址返回
* 问题描述：
	给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
	1、必须在原数组上操作，不能拷贝额外的数组。
	2、尽量减少操作次数。
* 求解思路：p、q两个指针，交换0元素（nums[p]）和非0元素(nums[q])的位置
* 测试结果：12ms，9.5mb 战胜98.64%的cpp用户
* 备注：开心，官方认定的最优解~
**/

void CArray::moveZeroes(vector<int>& nums) {
	
	for (int q = 0, p = 0; q < nums.size(); ++q)
	{
		if (nums[p] != 0)  // 找到第一个p为0的位置之前，p、q都是重合的
		{
			
			++p;
		}
		else
		{			
			if (nums[q])
			{
				nums[p] = nums[q];  // 非0元素覆盖0元素
				nums[q] = 0;
				//  swap(nums[p], nums[q]);  // 找到第一个q非零的位置，交换位置,未注释的操作比swap函数操作少一次运算
				
				++p;  // 移动指针
			}
			 // 此时q仍然为0，继续移动

		}
	}

}

/***********************函数说明***************
* 函数名：vector<int> twoSum(vector<int>& nums, int target)
* 函数参数：待查找数组、目标值
* 函数返回值：该数组中那两个和为目标值的整数的索引
* 问题描述：
	给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

	你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。
* 解决思路：
		1、复制该数组记做temp并排序；
		2、双指针i，j，i从小的部分开始一段，j从大的部分开始移动；
		3、当temp[i]+temp[j] < target时，移动小指针，使和增大，否则移动大指针，使和减小
		4、查找两个元素在原数组中的位置并返回。
* 测试结果：
	执行用时 :8 ms, 在所有 cpp 提交中击败了97.91%的用户
	内存消耗 :9.2 MB, 在所有 cpp 提交中击败了84.05%的用户

        
**/

vector<int> CArray:: twoSum(vector<int>& nums, int target)
{
	vector<int> temp = nums;
	sort(temp.begin(), temp.end());
	int i, j;
	for (i = 0, j = temp.size() - 1; j > i;)
	{
		if (temp[i] + temp[j] > target)
			--j;
		else if (temp[i] + temp[j] < target)
			++i;
		else
			break;
	}
	auto item1 = find(nums.begin(), nums.end(), temp[i]);  // 在原数组中找到这个元素
	auto index1 = std::distance(std::begin(nums), item1);  // 计算这个元素在原数组中的位置
	int temp_num = nums[index1];  // 暂存这个数据
	nums[index1] = INT_MAX;// 将该位置的数据置为一个不可能影响查找temp[j]的数，即，大于target的数INT_MAX一定不会被出现在结果中
	auto item2 = find(nums.begin(), nums.end(), temp[j]);	// 找第二个元素
	auto index2 = std::distance(std::begin(nums), item2);  // 找第二个元素的下标
	nums[index1] = temp_num;  // 还原该数组的nums[index1]的值
	temp.clear();
	if (index1 < index2)  
	{
		temp.push_back(index1);
		temp.push_back(index2);
	}
	else
	{
		temp.push_back(index2);
		temp.push_back(index1);
	}
	return temp;
}
/*******************函数说明*****************
* 函数名：vector<int> twoSumRefer(vector<int>& nums, int target)
* 函数说明：和上一个twoSum函数是对同一个题的不同解法
* 函数实现：一遍哈希表
			1、定义变量；
			2、遍历数组，并将已经遍历的数组元素存入哈希表中，其中元素值作为哈希表的关键字，索引作为哈希表的值；
			3、每遍历一个元素，判断当前元素是否已经存在于哈希表中，如果存在，说明求解完成，push索引，否则继续遍历。
		
* 测试信息：
	执行用时 :4 ms, 在所有 cpp 提交中击败了99.82%的用户
	内存消耗 :9.9 MB, 在所有 cpp 提交中击败了44.75%的用户
	

**/


vector<int> CArray::twoSumRefer(vector<int>& nums, int target)
{
	vector<int> ans(2, -1);
	unordered_map<int, int> hash;
	for (int i = 0; i < nums.size(); ++i)
	{
		int r = target - nums[i];  // r就是两者的差
		if (hash.count(r)) // 在容器中搜索键为r的元素，并返回找到的元素数，由于unordered_map中不允许重复的键，所以存在返回1，否则返回0
			// 如果存在，说明已经找到，数组元素就是哈希表的关键字，其索引是哈希表的元素值
		{
			ans[0] = hash[r];
			ans[1] = i;
			return ans;
		}
		hash[nums[i]] = i;  // 有一个关键字为nums[i]的数对，值（索引）是i
	}
	return ans;
}
/*****************函数说明******************
* 函数名：bool isValidSudoku(vector<vector<char>>& board) 
* 函数参数：9*9的整型矩阵
* 函数返回值：判断该9*9的矩阵是否能构成一个数独
* 问题描述;
		判断一个 9x9 的数独是否有效。只需要根据以下规则，验证已经填入的数字是否有效即可。

		数字 1-9 在每一行只能出现一次。
		数字 1-9 在每一列只能出现一次。
		数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。

		说明:

		一个有效的数独（部分已被填充）不一定是可解的。
		只需要根据以上规则，验证已经填入的数字是否有效即可。
		给定数独序列只包含数字 1-9 和字符 '.' 。
		给定数独永远是 9x9 形式的。
* 求解思路：
		1、定义数组元素是哈希表的三个数组分别表示行、列、子数独
		2、计算子块的索引：bindex = (i / 3) * 3 + j / 3,每个bindex表示一个子块
		3、遍历该矩阵，分别将存储在行、列、子块数组中并判断是否能在当前行、列、子块中找到当前元素，如果能返回false；
		4、循环正常结束，返回true。
* 测试结果：
执行用时 :24 ms, 在所有 cpp 提交中击败了38.67%的用户
内存消耗 :12.1 MB, 在所有 cpp 提交中击败了8.85%的用户
**/

bool CArray::isValidSudoku(vector<vector<char>>& board) 
{
	vector<unordered_map<int, int>> row(9), col(9), block(9);
	for (int i = 0; i < 9; ++i) 
	{
		for (int j = 0; j < 9; ++j) 
		{
			int bindex = (i / 3) * 3 + j / 3;  // 计算子块的索引
			char cur = board[i][j];  // 此时的元素值
			if (cur == '.')  
				continue;  // 跳过后续步骤
			if (row[i].count(cur) || col[j].count(cur) || block[bindex].count(cur))  // 如果再同一行、同一列、同一个子块内找到了当前元素，返回false
				return false;
			row[i][cur] = 1;  // 将当前元素加入哈希表
			col[j][cur] = 1;
			block[bindex][cur] = 1;  // 第bindex块数独的当前元素
		}
	}
	return true;
}
/********************************
* 函数说明：和isValidSudoku函数是同一题，不同之处在于表示行、列的哈希表在每次循环前都会重新定义，不再是定义9个表，节省一部分空间
* 测试结果：
执行用时 :24 ms, 在所有 cpp 提交中击败了38.67%的用户
内存消耗 :11.1 MB, 在所有 cpp 提交中击败了75.97%的用户
*/
bool CArray::isValidSudoku2(vector<vector<char>>& board) {
	vector<unordered_map<int, int>> block(9);
	for (int i = 0; i < 9; ++i) {
		unordered_map<int, int>row, col;
		for (int j = 0; j < 9; ++j) {
			int bindex = (i / 3) * 3 + j / 3;
			int cur = board[i][j] - '0';
			int ver = board[j][i] - '0';
			if (board[i][j] != '.')
			{
				if (row.count(cur)  || block[bindex].count(cur))  
					return false;
				row[cur] = 1;
				block[bindex][cur] = 1;
			}
			if (board[j][i] != '.')
			{
				if (col.count(ver))
					return false;
				col[ver] = 1;
			}
			
			
		}
	}
	return true;
}
// 暂未成功
void CArray::rotate(vector<vector<int>>& matrix) {
	int n = matrix.size();
	vector<unordered_map<int, int>> flag;
	for (int i = 0; i < n-i; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (!flag[j].count(n - i - 1))
			{
				swap(matrix[i][j], matrix[j][n - i - 1]);
				flag[j][n - i - 1] = 1;
			}
		}
	}
	
}






