#include "basic_algorithm_binaryTree.h"
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
/************文件说明***************
* 文件名：basic_algorithm_binaryTree.cpp
* 其他：LeetCode二叉树专题
https://leetcode-cn.com/explore/learn/card/data-structure-binary-tree/2/traverse-a-tree/


**/
/*****************函数说明****************
* 函数名： vector<int> preorderTraversal(TreeNode* root)
* 函数参数：TreeNode的根节点
* 函数返回值：返回该树的前序遍历
* 问题描述：给定一个二叉树，返回它的 前序 遍历。
* 解决方案：
		迭代：关键点有两个
			1、用栈的先进后出保存根节点
			2、及时入栈出栈（入栈：每遇到一个根节点就入栈；出栈：当遍历到该节点的右节点的时候，这个节点的所有子节点就完成了，可以出栈了；或者该节点的左节点遍历完了，下一步遍历其右节点的时候出栈）

			实现步骤：
			1、如果是空，直接返回；
			2、如果当前节点不为空，先把该节点入栈并存入输出数组（先遍历根，所以先存根节点），然后检查该节点的左右节点
				(1) 如果左节点不为空，遍历左节点；（左节点比右节点优先遍历）
				(2) 如果左节点为空，右节点不为空，将当前节点出栈，遍历右节点；
				(3) 如果左右节点都为空，这个节点就是叶子节点。
					开始向上一级返回：
					(1) 先把这个叶子节点出栈，如果出栈完后根节点的栈为空，完成所有节点的遍历，返回结果数组；
					(2) 如果仍有根节点没有完全遍历（rootStack不为空），取出并出栈上一级的根节点，并检查该根节点的右节点是否为空，如果为空，继续取上一级根节点；
					(3) 直到取出一个右节点不为空，将该右节点作为遍历节点继续；
					(4) 如果没有不为空的右节点，说明所有节点遍历完了，返回结果数组。
		迭代（参考答案）
			从根节点开始，每次弹出当前遍历的节点，并把当前节点的非空子节点入栈，先压右孩子再压左孩子
		递归
			先将根节点值保存，再遍历左节点，最后遍历右节点

* 测试信息：4ms
**/
// 前序遍历，先访问根节点，再访问左节点，最后右节点
vector<int> CBinaryTree::preorderTraversal(TreeNode* root) {

	vector<int> ans;
	if (root == NULL)
		return ans;  // 如果该节点是空节点直接返回空
	stack<TreeNode*> rootStack;  // 存储没有遍历完的根节点
	TreeNode* currNode = root, *rootNode = root;
	while (currNode != NULL)
	{
		rootStack.push(currNode);  // 保存当前根节点
		ans.push_back(currNode->val);  // 先保存根节点

		if (currNode->left == NULL)  // 如果左节点不为空，遍历左节点
			if (currNode->right == NULL)  // 如果右节点不为空，遍历右节点
			{
				if (!rootStack.empty())  // 左右都为空，如果还有没有完成遍历的根节点
				{
					rootStack.pop();  // 先把当前节点pop出来
					if (!rootStack.empty())  // 如果还有节点没有遍历完的话
					{
						rootNode = rootStack.top();
						rootStack.pop();  // 取出上一个根节点
						while (rootNode->right == NULL)  // 直到取出一个有效的右节点
						{
							if (!rootStack.empty())  // 如果全部根节点都已经出栈了，说明没有可以继续遍历的根节点了
							{
								rootNode = rootStack.top();
								rootStack.pop();  // 取出上一个根节点
							}
							else
								return ans;  // 如果全部都是空节点了就可以返回了
						}
						// 退出循环时，当前根节点的右节点不为空
						currNode = rootNode->right;
					}
					else
						return ans;
					
				}
				else
					return ans;
			}
			else
			{
				rootStack.pop();  // 已经在访问右边节点了，完成全部访问了 
				currNode = currNode->right;

			}
		else
			currNode = currNode->left;
		
	}
	return ans;


}

vector<int> CBinaryTree::preorderTraversalRefer(TreeNode* root) {

	vector<int> ans;
	if (root == NULL)
		return ans;  // 如果该节点是空节点直接返回空
	stack<TreeNode*> rootStack;  // 存储没有遍历完的根节点
	TreeNode* currNode = root;
	rootStack.push(root);
	while (!rootStack.empty())
	{
		// 每次弹出的那个就是当前节点
		currNode = rootStack.top();  // 保存当前根节点
		rootStack.pop();

		ans.push_back(currNode->val);  // 先保存根节点

		// 然后再对左右孩子压栈，先压右孩子，再压左孩子
		if (currNode->right != NULL)
			rootStack.push(currNode->right);
		if (currNode->left != NULL)
			rootStack.push(currNode->left);	

	}
	return ans;


}
// 前序遍历，递归实现
vector<int> CBinaryTree::preorderTraversal2(TreeNode* root) {
	// static vector<int> ans;  // 测试的时候静态变量不行，然而我还没有搞清楚为什么,定义在类里面是没问题的
	if (root == NULL)
		return ans;
	ans.push_back(root->val);
	preorderTraversal(root->left);
	preorderTraversal(root->right);

}
/*****************函数说明*******************
* 函数名：vector<int> inorderTraversal(TreeNode* root)
* 函数参数：TreeNode结构的树的根节点
* 函数返回值：该数的中序遍历
* 实现方案：
	迭代：
		1、一直遍历左节点直到最后一个左节点；
		2、保存没有左节点的根节点的值，开始遍历其右枝；
		3、如果右节点也为空，取出上一级根节点（这里要将该根节点的左节点赋空）


**/
vector<int> CBinaryTree:: inorderTraversal(TreeNode* root)  // 迭代
{
	stack<TreeNode*> rootStack;
	TreeNode* currNode = root;
	
	
	while (currNode != NULL)
	{
		if (currNode->left != NULL)  // 如果当前节点存在左节点，将当前节点入栈，指针移向它的左节点
		{
			rootStack.push(currNode);
			currNode = currNode->left;
		}
		else  // 此时该节点不再有左节点
		{
			ans.push_back(currNode->val);  // 该节点是没有左节点的根节点，可以将节点值入队
			if (currNode->right != NULL)  // 如果该节点存在右节点，指针移向它的右节点
			{				
				currNode = currNode->right;
			}
			else
			{
				if (!rootStack.empty())  // 不存在右节点，即当前节点是叶子节点，如果此时还有没有完成遍历的左节点，出栈
				{
					currNode = rootStack.top();
					rootStack.pop();					
					currNode->left = NULL;
				}  // 因为左边已经遍历完了
				else
					break;
			}
		}
	}
	return ans;
	// 退出循环后就是左节点的最后一个叶子节点
}
// 中序遍历，先左节点，再根节点，后右节点
vector<int> CBinaryTree::inorderTraversal2(TreeNode* root) {
	if (root == NULL)
		return ans;
	// 先左节点
	inorderTraversal(root->left);
	// 再根节点
	ans.push_back(root->val);
	// 最后右节点
	inorderTraversal(root->right);

	return ans;

}