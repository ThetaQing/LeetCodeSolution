#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// 4ms£¬95.83%
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	for (int i1 = m - 1, i2 = n - 1, i3 = m + n - 1; i3 >= 0; --i3)
	{
		if (i1 >= 0 && i2 >= 0)
		{
			if (nums1[i1] > nums2[i2])
			{
				nums1[i3] = nums1[i1];
				i1 -= 1;
			}
			else
			{
				nums1[i3] = nums2[i2];
				i2 -= 1;
			}
		}
		else if (i1 < 0 && i2 >= 0)
		{
			nums1[i3] = nums2[i2];
			i2 -= 1;
		}
		else if (i2 < 0 && i1 >= 0)
		{
			nums1[i3] = nums1[i1];
			i1 -= 1;
		}
	}
}