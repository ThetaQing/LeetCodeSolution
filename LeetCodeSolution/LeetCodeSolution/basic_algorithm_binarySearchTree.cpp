#include "basic_algorithm_binarySearchTree.h"
#include <iostream>
#include <stack>
using namespace std;


/***************文件说明**************
* 文件名：basic_algorithm_binarySearchTree.cpp
* 文件说明：来源：LeetCode二叉搜索树模块
https://leetcode-cn.com/explore/learn/card/introduction-to-data-structure-binary-search-tree/
* 知识点：
	二叉搜索树具有以下性质：每个节点中的值必须大于或等于其左侧子树中的任何值，但小于或等于其右侧子树中的任何值。
	通过中序遍历可以得到一个递增的有序序列
**/


/******************函数说明**************
* 函数名：bool isValidBST(TreeNode* root)
* 函数参数：树的根节点
* 函数返回值：是否是二叉搜索树，当且仅当是二叉搜索树时返回true
* 问题描述：98. 给定一个二叉树，判断其是否是一个有效的二叉搜索树。
* 解决方案：中序遍历二叉树，最后比较得到的中序遍历序列是否为一个递增序列
* 测试信息：20ms，49.58%

**/

bool CBinarySearch::isValidBST(TreeNode* root)
{
	if (root == NULL)
		return 1;
	stack<TreeNode*> nodeStack;
	TreeNode* currNode = root, *leftNode, *rightNode;

	
	while (!nodeStack.empty() || currNode)
	{
		// 中序遍历
		while (currNode)
		{
			nodeStack.push(currNode);
			currNode = currNode->left;
		}
		currNode = nodeStack.top();
		nodeStack.pop();

		nodeVec.push_back(currNode->val);

		currNode = currNode->right;
	}
	// 递增序列判断
	for (int i = 1; i < nodeVec.size(); ++i)
	{
		if (nodeVec[i] > nodeVec[i - 1])
			continue;
		else
			return 0;
	}
	return 1;

}

