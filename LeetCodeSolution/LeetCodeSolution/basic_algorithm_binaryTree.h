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
	// 前序
	std::vector<int> preorderTraversal(TreeNode* root);  // 迭代
	std::vector<int> preorderTraversalRefer(TreeNode* root);  // 参考网络
	std::vector<int> preorderTraversal2(TreeNode* root);  // 递归
	// 中序
	std::vector<int> inorderTraversal(TreeNode* root);  // 迭代
	std::vector<int> inorderTraversalRefer(TreeNode* root);  // 参考网络
	std::vector<int> inorderTraversal2(TreeNode* root);  // 递归
	// 后序
	std::vector<int> postorderTraversal(TreeNode* root);  // 迭代
	std::vector<int> postorderTraversalRefer(TreeNode* root);  // 参考网络
	std::vector<int> postorderTraversal2(TreeNode* root);  // 递归
	// 层序
	std::vector<std::vector<int>> levelOrder(TreeNode* root);  // 迭代
	std::vector<std::vector<int>> levelOrder2(TreeNode* root);  // 递归
	std::vector<std::vector<int>> levelHelper(TreeNode* root, int level);  // 递归辅助函数

	// 求数的深度
	int maxDepth(TreeNode* root);
	// 用递归解决问题
	int topDown(TreeNode* root, int depth);
	int bottomUp(TreeNode* root);
	// 迭代
	int iteration(TreeNode* root);
private:
	std::vector<int> ans;
	std::vector<std::vector<int>> levelAns;
	int maxdepth=0;
	
};
#endif // !__basic_algorithm_binaryTree_




#pragma once
