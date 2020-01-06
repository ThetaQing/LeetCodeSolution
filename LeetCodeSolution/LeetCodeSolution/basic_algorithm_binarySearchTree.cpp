#include "basic_algorithm_binarySearchTree.h"
#include <iostream>
#include <stack>
using namespace std;


/***************�ļ�˵��**************
* �ļ�����basic_algorithm_binarySearchTree.cpp
* �ļ�˵������Դ��LeetCode����������ģ��
https://leetcode-cn.com/explore/learn/card/introduction-to-data-structure-binary-search-tree/
* ֪ʶ�㣺
	���������������������ʣ�ÿ���ڵ��е�ֵ������ڻ��������������е��κ�ֵ����С�ڻ�������Ҳ������е��κ�ֵ��
	ͨ������������Եõ�һ����������������
**/


/******************����˵��**************
* ��������bool isValidBST(TreeNode* root)
* �������������ĸ��ڵ�
* ��������ֵ���Ƿ��Ƕ��������������ҽ����Ƕ���������ʱ����true
* ����������98. ����һ�����������ж����Ƿ���һ����Ч�Ķ�����������
* ���������������������������Ƚϵõ���������������Ƿ�Ϊһ����������
* ������Ϣ��20ms��49.58%

**/

bool CBinarySearch::isValidBST(TreeNode* root)
{
	if (root == NULL)
		return 1;
	stack<TreeNode*> nodeStack;
	TreeNode* currNode = root, *leftNode, *rightNode;

	
	while (!nodeStack.empty() || currNode)
	{
		// �������
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
	// ���������ж�
	for (int i = 1; i < nodeVec.size(); ++i)
	{
		if (nodeVec[i] > nodeVec[i - 1])
			continue;
		else
			return 0;
	}
	return 1;

}

