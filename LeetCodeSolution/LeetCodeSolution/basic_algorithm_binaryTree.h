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
	int topDown(TreeNode* root, int depth);  // 自顶向下
	int bottomUp(TreeNode* root);  // 自底向上
	int maxDepthLevel(TreeNode* root);  // 层序遍历

	// 迭代
	int maxDepthIteration(TreeNode* root);	
	int maxDepthIterationRefer(TreeNode* root);

	// 对称树的判断
	bool isSymmetricIteration(TreeNode* root);  // 迭代
	bool isSymmetric(TreeNode* root);  // 递归
	bool isLeftEqualRight(TreeNode* left, TreeNode* right);  // 递归辅助函数

	// 路径总和
	bool hasPathSum(TreeNode* root, int sum);  // 递归

	// 由遍历结果重建树
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder);  // 前序和中序
	TreeNode* helper(TreeNode* root, vector<int> left, vector<int>right);
private:
	std::vector<int> ans;
	std::vector<std::vector<int>> levelAns;
	int maxdepth=0;
	TreeNode myNode{1};
	TreeNode* ansTree = &myNode;
	
};
#endif // !__basic_algorithm_binaryTree_




#pragma once
