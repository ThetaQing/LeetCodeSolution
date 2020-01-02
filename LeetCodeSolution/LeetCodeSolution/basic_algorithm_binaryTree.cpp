#include "basic_algorithm_binaryTree.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;
/************�ļ�˵��***************
* �ļ�����basic_algorithm_binaryTree.cpp
* ������LeetCode������ר��
https://leetcode-cn.com/explore/learn/card/data-structure-binary-tree/2/traverse-a-tree/


**/



/*********************************************

==============================================

���ı�����
		ǰ������������������������ĵ������ݹ�ʵ��

==============================================


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
	preorderTraversal2(root->left);
	preorderTraversal2(root->right);

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
* �������������
				* 1����ջ����֤�˳�ѭ����ʱ���ǿսڵ㣬��ջ��Ԫ��һ����Ҷ�ӽڵ�
				* 2����ջ��ջ��Ԫ��һ����Ҷ�ӽڵ㣬��ջ�����
				* 3�����½ڵ㣬ȡ��һ��ջ���ڵ㣬����ո���ӵĽڵ�������ڵ����\�ҽڵ㣬������ڵ����\�ҽڵ㸳NULL����������push-popѭ����
				*	 ��󽫵�ǰ�ڵ����Ϊ�����Һ���
			�������ο����磩
				1���Ӹ��ڵ㿪ʼ���ε���������ջ��Ԫ�����������б��У�
				2������ѹ���������к��ӽڵ㣬���մ��ϵ��¡��������ҵ�˳������ѹ��ջ�С�����Ϊ���������˳���Ǵ��µ��ϡ��������ң�Ȼ������б��������

***/
vector<int> CBinaryTree::postorderTraversal(TreeNode* root) {
	TreeNode* currNode = root,*preNode = root;
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
			ans.push_back(currNode->val);  // ��ջ��Ҷ�ӽڵ��ջ
			if (!rootStack.empty())
			{
				preNode = currNode;
				currNode = rootStack.top();
				// �����µ�Ҷ�ӽڵ㣬ɾ���Ѿ������Ľڵ�
				if (preNode == currNode->left)  
					currNode->left = NULL;
				else if (preNode == currNode->right)
					currNode->right = NULL;
				
			}
			currNode = currNode->right;  // ���½ڵ�

		}
			
	}	   	 
	return ans;
}
vector<int> CBinaryTree::postorderTraversalRefer(TreeNode* root)
{
	TreeNode* currNode = root, * tempNode = root;
	stack<TreeNode*> rootStack;	
	if (currNode == NULL)  // ���Ϊ�գ�ֱ�ӷ���
		return ans;

	rootStack.push(currNode);
	while (!rootStack.empty())
	{
		currNode = rootStack.top();  // �ȸ��ڵ�
		rootStack.pop();
		ans.push_back(currNode->val);

		if (currNode->left != NULL)  // �����ڵ㣨���ջ��
			rootStack.push(currNode->left);
		if (currNode->right != NULL)  // ���ҽڵ�
			rootStack.push(currNode->right);
	}
	reverse(ans.begin(), ans.end());  // �������
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

// �������
/******************����˵��**************
* ʵ�ַ���������
		ʹ���������������л���һ�����ڵ�ǰ��Ľڵ��������һ��������һ��Ĵ洢��ÿ�α������Ѷ�ȫ���������ɿն�
		1���Ӹ��ڵ㿪ʼ��ֻҪ��ǰ�㻹��û�б����Ľڵ㣬�ͼ������������洢�ڵ�ֵ�����ýڵ�����ҽڵ����������ӵ�childQueue��
		2����ǰ�������ɺ�����ò���������Ϊ�գ������������뵽��������У������ʱ������׼����һ��ı���
		3����ʼ������һ�㣬���ոո���ӵ�˳��������ҳ��ӣ����ظ�����1��ֻ�ǽ����л���currQueue�����Ե������ӣ�

		���������򻯵ķ���
			Ҳ�����ö��У�ֻʹ��һ���ӣ����ݶ��е������������ӵ�Ԫ�ظ����Դ���ɽ���

		�ݹ飺�������ĸ߶ȣ������б�ĳ��ȱ�ʾ��ǰ��ĸ߶ȣ���levelAns.size() = 1,��ʾ��ǰ���ǵ�һ�㣬levelAns[0]�ͱ�ʾ��һ��Ľڵ�
			1�������ڵ�Ϊ�գ�ֱ�ӷ��أ�
			2�������ǰ��ĸ߶ȴ��ڷ����б�ĳ��ȣ�Ϊ�����б�����һ��Ԫ��Ϊ��һ�εݹ�������ӽڵ㣻
			3��ȡ����ǰ����б�Ϊ���б���Ӹýڵ��Ԫ��ֵ��
			4�������ýڵ�����ҽڵ㡣
		�ݹ�Ĺؼ���������vector������洢���ʣ�����ȡ����level����
* ������Ϣ��12ms��42.55%
**/
vector<vector<int>> CBinaryTree::levelOrder(TreeNode* root) {

	TreeNode* currNode = root;
	queue<TreeNode*> childQueue;  // �洢��ǰ�ڵ���ӽڵ�
	queue<TreeNode*> currQueue;  // �洢��ǰ�����Ĳ�
	currQueue.push(currNode);
	while (currNode != NULL &&(!currQueue.empty() || !childQueue.empty()))
	{
		// ��ʱchildStackΪ�ն�
		while(!currQueue.empty())
		{
			currNode = currQueue.front();
			currQueue.pop();
			ans.push_back(currNode->val);  // ��ǰ���ڵ�
			if (currNode->left != NULL)
				childQueue.push(currNode->left);
			if (currNode->right != NULL)
				childQueue.push(currNode->right);
			
		}
		if (!ans.empty())
			levelAns.push_back(ans);
		ans.clear();  // ��գ���ʼ��һ��
		// ��ʱcurrQueueΪ�ն�
		while (!childQueue.empty())
		{
			currNode = childQueue.front();
			childQueue.pop();
			ans.push_back(currNode->val);
			if (currNode->left != NULL)
				currQueue.push(currNode->left);
			if (currNode->right != NULL)
				currQueue.push(currNode->right);
			

		}
		if (!ans.empty())
			levelAns.push_back(ans);
		ans.clear();  // ��գ���ʼ��һ��


	}

	return levelAns;
}

// �ݹ�ʵ��
vector<vector<int>> CBinaryTree::levelOrder2(TreeNode* root)
{
	TreeNode* currNode = root;
	int level = 0;
	if (currNode == NULL)
		return levelAns;
	levelHelper(currNode, level);
	return levelAns;
}

vector<vector<int>> CBinaryTree::levelHelper(TreeNode* root, int level)  // ��ǰ���ڵ����ڵĲ���
{
	if (root == NULL)
		return levelAns;  // ���Ϊ��ֱ�ӷ���
	if (levelAns.size() == level)
	{
		vector<int>* newVec = new vector<int>();    // �����ǰ�㣨��Ϊ�Ǵ�0��ʼ�������ж�������=�����ڵ��귵���б�ĳ��ȣ����б����һ��Ԫ��
		levelAns.push_back(*newVec);
	}
	// ��������ʱ��������levelAns[level]��temp������һ������������ָ��levelAns[level]��ָ��
	levelAns[level].push_back(root->val);  // ȡ����ǰ���Ӧ�ı�Ϊ�����Ԫ��


	levelHelper(root->left, level + 1);  // �������ҿ�ʼ����
	levelHelper(root->right, level + 1);

	return levelAns;
}

/*********************************************

==============================================

���õݹ�������
		�Զ����£���ÿ���ݹ�㼶�����ǽ����ȷ��ʽڵ�������һЩֵ�����ڵݹ���ú���ʱ����Щֵ���ݵ��ӽڵ㣬���Ա���Ϊ��һ��ǰ�������
		�Ե����ϣ��ڵݹ����ϣ��������ȶ������ӽڵ�ݹ�ص��ú�����Ȼ����ݷ���ֵ�͸��ڵ㱾���ֵ�õ��𰸣����Ա���Ϊ��һ�ֺ��������

==============================================


**/


/*****************����˵��********************
* ��������int maxDepth(TreeNode* root)
* �������������ĸ��ڵ�
* ��������ֵ����������������
* ʵ�ַ�����


**/


int CBinaryTree::maxDepth(TreeNode* root)
{
	if (!root)  // ������ڵ�Ϊ��
		return maxdepth;
	
	// maxdepth = topDown(root, 1);
	maxdepth = bottomUp(root);
	return maxdepth;
}
// �Զ�����
// 20ms��17.38
int CBinaryTree::topDown(TreeNode* root, int depth)
{
	if (!root)  // ������ڵ�Ϊ��
		return depth;
	int leftDepth = 0, rightDepth = 0;
	leftDepth = topDown(root->left, depth + 1);  // ��Ϊ�յ�ʱ����ȼ�1
	rightDepth = topDown(root->right, depth + 1);  

	return max(leftDepth, rightDepth);

}
// �Ե�����
// 20ms�� 17.38%
int CBinaryTree::bottomUp(TreeNode* root)
{
	if (!root)
		return 0;
	int leftDepth = 0, rightDepth = 0;

	leftDepth = bottomUp(root->left) + 1;  // ÿ����һ�� + 1
	rightDepth = bottomUp(root->right) + 1;

	return max(leftDepth, rightDepth);
}

// �����������������2428s��
int CBinaryTree::maxDepthLevel(TreeNode * root)
{
	vector<vector<int>>ans = levelHelper(root, 0);
	maxdepth = ans.size();
	
	return maxdepth;
	

}
/***************************


* ���������
	�ο��𰸵�����˼��
	�����е��鷳
	��ʵ��ǰ������Լ�ʵ�ֵ�ʱ��˼��һ�£���ÿ���ڵ��������ڵ㶼ѹջ��Ȼ���ٳ�ջ����ջ��ʱ������ѹ�ҽڵ㣬û���ҽڵ������ջ
* ������Ϣ��
ִ����ʱ :12 ms, ������ C++ �ύ�л�����73.50%���û�
�ڴ����� :19 MB, ������ C++ �ύ�л�����89.72%���û�

***/
int CBinaryTree::maxDepthIteration(TreeNode* root) {
	int depth = 0;
	TreeNode* currNode = root;
	stack<pair<TreeNode*,int>>nodeStack;
	pair<TreeNode*, int> nodePair;
	while (currNode != NULL || !nodeStack.empty())
	{
		while (currNode != NULL)
		{
			depth += 1;
			nodePair.first = currNode;
			nodePair.second = depth;
			nodeStack.push(nodePair);  // ��ǰ�ڵ���ջ
			currNode = currNode->left;

		}
		maxdepth = max(depth, maxdepth);
		if (!nodeStack.empty())  // ���ջ��Ϊ��
		{
			// ��ջ
			currNode = nodeStack.top().first;			
			depth = nodeStack.top().second;
			nodeStack.pop();
			if(currNode->right)
				currNode = currNode->right;
			else if (!nodeStack.empty())
			{
				// ��ջ
				currNode = nodeStack.top().first;
				depth = nodeStack.top().second;
				nodeStack.pop();
				
				// ����Ϊ�ҽڵ�
				currNode = currNode->right;
			}
			else
			// ����Ϊ�ҽڵ�
			currNode = currNode->right;
		}
	}
	return maxdepth;

}
// ִ����ʱ :12 ms, ������ C++ �ύ�л�����73.50 %���û�
// �ڴ����� :19.2 MB, ������ C++ �ύ�л�����69.52 %���û�
// �������磬ʵ������ǰ�������˼�룬�����ڵ�ѹ�ӽڵ�
int CBinaryTree::maxDepthIterationRefer(TreeNode* root)
{
	int depth = 0;
	TreeNode* currNode = root;
	stack<pair<TreeNode*, int>>nodeStack;  // ����Ԫ�������Ե�ջ
	pair<TreeNode*, int> nodePair;  // �������ԣ���һ��Ԫ�������Ľڵ㣬�ڶ���Ԫ���Ǹýڵ��ֵ
	if (root == NULL)
		return 0;
	// �����Ϊ�����Ļ����Ӹ��ڵ㿪ʼ��ջ����ջ��ͬʱ�����ҷǿսڵ㶼ѹջ
	nodePair.first = currNode;
	nodePair.second = 1;
	nodeStack.push(nodePair);
	while (!nodeStack.empty())
	{
		// ȡ��ջ��Ԫ��
		nodePair = nodeStack.top();
		nodeStack.pop();
		depth = nodePair.second;
		currNode = nodePair.first;

		// �Ƚ������Ϣ��ȡ���ֵ
		maxdepth = max(maxdepth, depth);  

		// �����ҷǿսڵ�ѹջ
		if(currNode->left)
			nodeStack.push(make_pair(currNode->left, depth + 1));
		if(currNode->right)
			nodeStack.push(pair<TreeNode*, int>(currNode->right, depth + 1));
	}
	return maxdepth;
}