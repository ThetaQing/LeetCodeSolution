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
* �����㷨�� �õ�i�����i-1�������бȽϣ������ɾ��ǰһ����
			 ��ʱָ�벻��Ҫ�ƶ�����Ϊ���鳤�ȼ�С������Ҳ����ƶ���һ��λ��
			 ����ʱ��nums[i]������δ�仯ǰ��nums[i+1]��
			 �������ȣ��ƶ�ָ�뵽��һ��λ�ã�ֱ�����
* �㷨������ִ���ٶ�����LeetCode����ʱ��260ms��12.32%			

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
			// i����Ҫ�����仯���Ѿ��ƶ��ˣ���Ϊ���ȷ����˱仯��������֮�仯
		}
		else
		{
			i += 1;

		}

	}
	return len;

}