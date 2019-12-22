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
* ������Ϣ��4ms
**/
// ǰ��������ȷ��ʸ��ڵ㣬�ٷ�����ڵ㣬����ҽڵ�
vector<int>CBinaryTree::preorderTraversal(TreeNode* root) {

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