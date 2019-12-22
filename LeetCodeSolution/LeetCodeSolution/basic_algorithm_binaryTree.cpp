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
* 测试信息：4ms
**/
// 前序遍历，先访问根节点，再访问左节点，最后右节点
vector<int>CBinaryTree::preorderTraversal(TreeNode* root) {

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