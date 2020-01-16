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
	// ǰ��
	std::vector<int> preorderTraversal(TreeNode* root);  // ����
	std::vector<int> preorderTraversalRefer(TreeNode* root);  // �ο�����
	std::vector<int> preorderTraversal2(TreeNode* root);  // �ݹ�
	// ����
	std::vector<int> inorderTraversal(TreeNode* root);  // ����
	std::vector<int> inorderTraversalRefer(TreeNode* root);  // �ο�����
	std::vector<int> inorderTraversal2(TreeNode* root);  // �ݹ�
	// ����
	std::vector<int> postorderTraversal(TreeNode* root);  // ����
	std::vector<int> postorderTraversalRefer(TreeNode* root);  // �ο�����
	std::vector<int> postorderTraversal2(TreeNode* root);  // �ݹ�
	// ����
	std::vector<std::vector<int>> levelOrder(TreeNode* root);  // ����
	std::vector<std::vector<int>> levelOrder2(TreeNode* root);  // �ݹ�
	std::vector<std::vector<int>> levelHelper(TreeNode* root, int level);  // �ݹ鸨������

	// ���������
	int maxDepth(TreeNode* root);
	// �õݹ�������
	int topDown(TreeNode* root, int depth);  // �Զ�����
	int bottomUp(TreeNode* root);  // �Ե�����
	int maxDepthLevel(TreeNode* root);  // �������

	// ����
	int maxDepthIteration(TreeNode* root);	
	int maxDepthIterationRefer(TreeNode* root);

	// �Գ������ж�
	bool isSymmetricIteration(TreeNode* root);  // ����
	bool isSymmetric(TreeNode* root);  // �ݹ�
	bool isLeftEqualRight(TreeNode* left, TreeNode* right);  // �ݹ鸨������

	// ·���ܺ�
	bool hasPathSum(TreeNode* root, int sum);  // �ݹ�

	// �ɱ�������ؽ���
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder);  // ǰ�������
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
