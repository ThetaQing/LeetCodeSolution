#include "basic_algorithm_binaryTree.h"
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
/************�ļ�˵��***************
* �ļ�����basic_algorithm_binaryTree.cpp
* ������LeetCode������ר��
https://leetcode-cn.com/explore/learn/card/data-structure-binary-tree/2/traverse-a-tree/


**/
/*****************����˵��****************
* �������� vector<int> preorderTraversal(TreeNode* root)
* ����������TreeNode�ĸ��ڵ�
* ��������ֵ�����ظ�����ǰ�����
* ��������������һ������������������ ǰ�� ������
* ���������
		�������ؼ���������
			1����ջ���Ƚ����������ڵ�
			2����ʱ��ջ��ջ����ջ��ÿ����һ�����ڵ����ջ����ջ�����������ýڵ���ҽڵ��ʱ������ڵ�������ӽڵ������ˣ����Գ�ջ�ˣ����߸ýڵ����ڵ�������ˣ���һ���������ҽڵ��ʱ���ջ��

			ʵ�ֲ��裺
			1������ǿգ�ֱ�ӷ��أ�
			2�������ǰ�ڵ㲻Ϊ�գ��ȰѸýڵ���ջ������������飨�ȱ������������ȴ���ڵ㣩��Ȼ����ýڵ�����ҽڵ�
				(1) �����ڵ㲻Ϊ�գ�������ڵ㣻����ڵ���ҽڵ����ȱ�����
				(2) �����ڵ�Ϊ�գ��ҽڵ㲻Ϊ�գ�����ǰ�ڵ��ջ�������ҽڵ㣻
				(3) ������ҽڵ㶼Ϊ�գ�����ڵ����Ҷ�ӽڵ㡣
					��ʼ����һ�����أ�
					(1) �Ȱ����Ҷ�ӽڵ��ջ�������ջ�����ڵ��ջΪ�գ�������нڵ�ı��������ؽ�����飻
					(2) ������и��ڵ�û����ȫ������rootStack��Ϊ�գ���ȡ������ջ��һ���ĸ��ڵ㣬�����ø��ڵ���ҽڵ��Ƿ�Ϊ�գ����Ϊ�գ�����ȡ��һ�����ڵ㣻
					(3) ֱ��ȡ��һ���ҽڵ㲻Ϊ�գ������ҽڵ���Ϊ�����ڵ������
					(4) ���û�в�Ϊ�յ��ҽڵ㣬˵�����нڵ�������ˣ����ؽ�����顣
		�������ο��𰸣�
			�Ӹ��ڵ㿪ʼ��ÿ�ε�����ǰ�����Ľڵ㣬���ѵ�ǰ�ڵ�ķǿ��ӽڵ���ջ����ѹ�Һ�����ѹ����
		�ݹ�
			�Ƚ����ڵ�ֵ���棬�ٱ�����ڵ㣬�������ҽڵ�

* ������Ϣ��4ms
**/
// ǰ��������ȷ��ʸ��ڵ㣬�ٷ�����ڵ㣬����ҽڵ�
vector<int> CBinaryTree::preorderTraversal(TreeNode* root) {

	vector<int> ans;
	if (root == NULL)
		return ans;  // ����ýڵ��ǿսڵ�ֱ�ӷ��ؿ�
	stack<TreeNode*> rootStack;  // �洢û�б�����ĸ��ڵ�
	TreeNode* currNode = root, *rootNode = root;
	while (currNode != NULL)
	{
		rootStack.push(currNode);  // ���浱ǰ���ڵ�
		ans.push_back(currNode->val);  // �ȱ�����ڵ�

		if (currNode->left == NULL)  // �����ڵ㲻Ϊ�գ�������ڵ�
			if (currNode->right == NULL)  // ����ҽڵ㲻Ϊ�գ������ҽڵ�
			{
				if (!rootStack.empty())  // ���Ҷ�Ϊ�գ��������û����ɱ����ĸ��ڵ�
				{
					rootStack.pop();  // �Ȱѵ�ǰ�ڵ�pop����
					if (!rootStack.empty())  // ������нڵ�û�б�����Ļ�
					{
						rootNode = rootStack.top();
						rootStack.pop();  // ȡ����һ�����ڵ�
						while (rootNode->right == NULL)  // ֱ��ȡ��һ����Ч���ҽڵ�
						{
							if (!rootStack.empty())  // ���ȫ�����ڵ㶼�Ѿ���ջ�ˣ�˵��û�п��Լ��������ĸ��ڵ���
							{
								rootNode = rootStack.top();
								rootStack.pop();  // ȡ����һ�����ڵ�
							}
							else
								return ans;  // ���ȫ�����ǿսڵ��˾Ϳ��Է�����
						}
						// �˳�ѭ��ʱ����ǰ���ڵ���ҽڵ㲻Ϊ��
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
				rootStack.pop();  // �Ѿ��ڷ����ұ߽ڵ��ˣ����ȫ�������� 
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
		return ans;  // ����ýڵ��ǿսڵ�ֱ�ӷ��ؿ�
	stack<TreeNode*> rootStack;  // �洢û�б�����ĸ��ڵ�
	TreeNode* currNode = root;
	rootStack.push(root);
	while (!rootStack.empty())
	{
		// ÿ�ε������Ǹ����ǵ�ǰ�ڵ�
		currNode = rootStack.top();  // ���浱ǰ���ڵ�
		rootStack.pop();

		ans.push_back(currNode->val);  // �ȱ�����ڵ�

		// Ȼ���ٶ����Һ���ѹջ����ѹ�Һ��ӣ���ѹ����
		if (currNode->right != NULL)
			rootStack.push(currNode->right);
		if (currNode->left != NULL)
			rootStack.push(currNode->left);	

	}
	return ans;


}
// ǰ��������ݹ�ʵ��
vector<int> CBinaryTree::preorderTraversal2(TreeNode* root) {
	// static vector<int> ans;  // ���Ե�ʱ��̬�������У�Ȼ���һ�û�и����Ϊʲô,��������������û�����
	if (root == NULL)
		return ans;
	ans.push_back(root->val);
	preorderTraversal(root->left);
	preorderTraversal(root->right);

}
/*****************����˵��*******************
* ��������vector<int> inorderTraversal(TreeNode* root)
* ����������TreeNode�ṹ�����ĸ��ڵ�
* ��������ֵ���������������
* ʵ�ַ�����
	������
		1��һֱ������ڵ�ֱ�����һ����ڵ㣻
		2������û����ڵ�ĸ��ڵ��ֵ����ʼ��������֦��
		3������ҽڵ�ҲΪ�գ�ȡ����һ�����ڵ㣨����Ҫ���ø��ڵ����ڵ㸳�գ�


**/
vector<int> CBinaryTree:: inorderTraversal(TreeNode* root)  // ����
{
	stack<TreeNode*> rootStack;
	TreeNode* currNode = root;
	
	
	while (currNode != NULL)
	{
		if (currNode->left != NULL)  // �����ǰ�ڵ������ڵ㣬����ǰ�ڵ���ջ��ָ������������ڵ�
		{
			rootStack.push(currNode);
			currNode = currNode->left;
		}
		else  // ��ʱ�ýڵ㲻������ڵ�
		{
			ans.push_back(currNode->val);  // �ýڵ���û����ڵ�ĸ��ڵ㣬���Խ��ڵ�ֵ���
			if (currNode->right != NULL)  // ����ýڵ�����ҽڵ㣬ָ�����������ҽڵ�
			{				
				currNode = currNode->right;
			}
			else
			{
				if (!rootStack.empty())  // �������ҽڵ㣬����ǰ�ڵ���Ҷ�ӽڵ㣬�����ʱ����û����ɱ�������ڵ㣬��ջ
				{
					currNode = rootStack.top();
					rootStack.pop();  // pop������������ڵ�ĸ��ڵ�					
					currNode->left = NULL;
				}  // ��ڵ��Ѿ��������ˣ�����Ҫ����
				else
					break;
			}
		}
	}
	return ans;

}
vector<int> CBinaryTree::inorderTraversalRefer(TreeNode* root)
{
	stack<TreeNode*> rootStack;
	TreeNode* currNode = root;


	while (currNode != NULL || !rootStack.empty())
	{
		while (currNode != NULL)  // �����ǰ�ڵ������ڵ㣬����ǰ�ڵ���ջ��ָ������������ڵ�
		{
			rootStack.push(currNode);
			currNode = currNode->left;
		}
		
		
		// ����ڵ�ĸ��ڵ�
		currNode = rootStack.top();
		rootStack.pop();
		ans.push_back(currNode->val);

		// ��ʼ�����ýڵ���ҽڵ�
		currNode = currNode->right;  // ��ʱ�Ľڵ����µ��ҽڵ�

	
	}
	return ans;
}
// �������������ڵ㣬�ٸ��ڵ㣬���ҽڵ�
vector<int> CBinaryTree::inorderTraversal2(TreeNode* root) {
	if (root == NULL)
		return ans;
	// ����ڵ�
	inorderTraversal(root->left);
	// �ٸ��ڵ�
	ans.push_back(root->val);
	// ����ҽڵ�
	inorderTraversal(root->right);

	return ans;

}
// ������� ���� ���
/*************����˵��*******************
* 1����ջ����֤�˳�ѭ����ʱ���ǿսڵ㣬��ջ��Ԫ��һ����Ҷ�ӽڵ�
* 2����ջ��ջ��Ԫ��һ����Ҷ�ӽڵ㣬��ջ�����
* 3�����½ڵ㣬ȡ��һ��ջ���ڵ㣬����ո���ӵĽڵ�������ڵ����\�ҽڵ㣬������ڵ����\�ҽڵ㸳NULL����������push-popѭ����
*	 ��󽫵�ǰ�ڵ����Ϊ�����Һ���

***/
vector<int> CBinaryTree::postorderTraversal(TreeNode* root) {
	TreeNode* currNode = root,*tempNode = root;
	stack<TreeNode*> rootStack;
	while (currNode != NULL || !rootStack.empty())
	{
		while (currNode != NULL)
		{
			rootStack.push(currNode);
			if (currNode->left != NULL)
				currNode = currNode->left;
			else
				currNode = currNode->right;
		}
		// �˳�ѭ���������ΪNULL����ջ��Ԫ��ΪҶ�ӽڵ�
		if (!rootStack.empty())
		{
			currNode = rootStack.top();
			rootStack.pop();
			ans.push_back(currNode->val);
			if (!rootStack.empty())
			{
				tempNode = currNode;
				currNode = rootStack.top();
				//currNode = currNode->right;
				if (tempNode == currNode->left)
					currNode->left = NULL;
				else if (tempNode == currNode->right)
					currNode->right = NULL;
				
			}
			currNode = currNode->right;

		}
			
	}	   	 
	return ans;
}

// ������� �ݹ�
vector<int> CBinaryTree::postorderTraversal2(TreeNode* root) {
	if (root == NULL)
		return ans;
	postorderTraversal2(root->left);
	postorderTraversal2(root->right);
	ans.push_back(root->val);
	return ans;
}