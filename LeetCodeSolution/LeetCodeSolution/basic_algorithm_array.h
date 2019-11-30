#ifndef __BASIC_ALGORITHM_ARRAY_H__
#define __BASIC_ALGORITHM_ARRAY_H__
#include <vector>
class CArray
{
public:
	int removeDuplicates(std::vector<int>& nums);
	int maxProfit(std::vector<int>& prices);
	void rotate(std::vector<int>& nums, int k);
	bool containsDuplicate(std::vector<int>& nums);
	int singleNumber(std::vector<int>& nums);
	std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2);
	std::vector<int> intersectRefer(std::vector<int>& nums1, std::vector<int>& nums2);
	std::vector<int> plusOne(std::vector<int>& digits);
	std::vector<int> plusOne2(std::vector<int>& digits);
	std::vector<int> plusOneRefer(std::vector<int>& digits);
	void moveZeroes(std::vector<int>& nums);
};

#endif // !__BASIC_ALGORITHM_ARRAY_H__
#pragma once
