#ifndef __basic_algorithm_binarySearchTree_
#define __basic_algorithm_binarySearchTree_
#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};

class CBinarySearch
{
public:
	bool isValidBST(TreeNode* root);




private:
	vector<int> nodeVec;
};


#endif

#pragma once
