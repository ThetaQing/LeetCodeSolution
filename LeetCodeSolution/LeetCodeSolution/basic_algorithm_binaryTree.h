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
	// Ç°Ðò
	std::vector<int> preorderTraversal(TreeNode* root);  // µü´ú
	std::vector<int> preorderTraversalRefer(TreeNode* root);  // ²Î¿¼ÍøÂç
	std::vector<int> preorderTraversal2(TreeNode* root);  // µÝ¹é
	// ÖÐÐò
	std::vector<int> inorderTraversal(TreeNode* root);  // µü´ú
	std::vector<int> inorderTraversalRefer(TreeNode* root);  // ²Î¿¼ÍøÂç
	std::vector<int> inorderTraversal2(TreeNode* root);  // µÝ¹é
	// ºóÐò
	std::vector<int> postorderTraversal(TreeNode* root);  // µü´ú
	std::vector<int> postorderTraversalRefer(TreeNode* root);  // ²Î¿¼ÍøÂç
	std::vector<int> postorderTraversal2(TreeNode* root);  // µÝ¹é
	// ²ãÐò
	std::vector<std::vector<int>> levelOrder(TreeNode* root);  // µü´ú
	std::vector<std::vector<int>> levelOrder2(TreeNode* root);  // µÝ¹é
	std::vector<std::vector<int>> levelHelper(TreeNode* root, int level);  // µÝ¹é¸¨Öúº¯Êý
private:
	std::vector<int> ans;
	std::vector<std::vector<int>> levelAns;
};
#endif // !__basic_algorithm_binaryTree_




#pragma once
