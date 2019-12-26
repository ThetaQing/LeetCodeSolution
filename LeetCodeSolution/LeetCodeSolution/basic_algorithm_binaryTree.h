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

	std::vector<int> preorderTraversal(TreeNode* root);  // ����
	std::vector<int> preorderTraversalRefer(TreeNode* root);  // ����
	std::vector<int> preorderTraversal2(TreeNode* root);  // �ݹ�
	std::vector<int> inorderTraversal(TreeNode* root);
	std::vector<int> inorderTraversalRefer(TreeNode* root);
	std::vector<int> inorderTraversal2(TreeNode* root);

	std::vector<int> postorderTraversal(TreeNode* root);
	std::vector<int> postorderTraversal2(TreeNode* root);
	vector<vector<int>> levelOrder(TreeNode* root);
private:
	std::vector<int> ans;
	std::vector<std::vector<int>> levelAns;
};
#endif // !__basic_algorithm_binaryTree_




#pragma once
