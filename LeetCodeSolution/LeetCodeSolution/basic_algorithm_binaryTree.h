#ifndef __basic_algorithm_binaryTree_
#define __basic_algorithm_binaryTree_
#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

class CBinaryTree
{
public:

	std::vector<int> preorderTraversal(TreeNode* root);  // µü´ú
	std::vector<int> preorderTraversalRefer(TreeNode* root);  // µü´ú
	std::vector<int> preorderTraversal2(TreeNode* root);  // µÝ¹é
	std::vector<int> inorderTraversal(TreeNode* root);
	std::vector<int> inorderTraversal2(TreeNode* root);
private:
	std::vector<int> ans;
};
#endif // !__basic_algorithm_binaryTree_




#pragma once
