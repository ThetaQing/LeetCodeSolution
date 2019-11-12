#include "basic_algorithm_array.h"
#include <iostream>
#include <vector>;
using namespace std;
using std::vector;
/*************�ļ�˵��***********
* �ļ����� basic_algorithm_array.cpp
* �ļ����ܣ�ʵ��LeetCode�����㷨�����鲿��
* �� ��CArray��
**/

/*************����˵��*********
* ��������int removeDuplicates(vector<int>& nums)
* ���������� һ���������飬�����е����������ظ�
* ��������ֵ��ȥ���ظ�Ԫ��֮������鳤��
* �����㷨�� ˫ָ�뷨��
			1����������ָ�� i �� j������ i ����ָ�룬�� j �ǿ�ָ�롣
			2��ֻҪ nums[i] = nums[j]�����Ǿ����� j �������ظ��
			3������������ nums[j] ��= nums[i]ʱ�������ظ���������Ѿ�������������Ǳ��������nums[j]����ֵ���Ƶ� nums[i + 1]��
			4������ i���������ǽ��ٴ��ظ���ͬ�Ĺ��̣�ֱ�� j ���������ĩβΪֹ��
* �㷨������ʱ�临�Ӷȣ�O(n)  24ms ��92.3%
			�ռ临�Ӷȣ�O(1)  9.9m��81.34%
* �״�㣺������Ϊ�յ�ʱ��Ҫ�������Ƿ���0������᷵��1.
* �����ܽ᣺��ǰһ���㷨���Ĳ�ͬ���ڣ����㷨һ���Խ��ͬһ���ظ������������ǽ��µ���ֱ�Ӹ����ظ��������������ƶ�Ԫ�ص�ʱ��Ͷ���ظ���Ĵ���ʱ�䡣
**/
int CArray::removeDuplicates(vector<int>& nums)
{
	if (nums.empty())
		return 0;
	int i = 0;
	for ( int j = 1; j < nums.size();++j)
	{
		if (nums[j] != nums[i])  // ֱ������û���ظ���Ԫ��
		{
			i += 1;
			nums[i] = nums[j];
		}	
		
	}
	nums.erase(nums.begin() + i + 1, nums.end());  // ���Ҫ��ԭ������Ӧ�����仯�Ļ�
	return i + 1;

}