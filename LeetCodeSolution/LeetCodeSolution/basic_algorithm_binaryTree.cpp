#include "basic_algorithm_binaryTree.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;
/************文件说明***************
* 文件名：basic_algorithm_binaryTree.cpp
* 其他：LeetCode二叉树专题
https://leetcode-cn.com/explore/learn/card/data-structure-binary-tree/2/traverse-a-tree/


**/



/*********************************************

==============================================

树的遍历：
		前序遍历、中序遍历、后序遍历的迭代、递归实现

==============================================


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
	preorderTraversal2(root->left);
	preorderTraversal2(root->right);

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
					rootStack.pop();  // pop出来的是有左节点的根节点					
					currNode->left = NULL;
				}  // 左节点已经处理完了，所以要赋空
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
		while (currNode != NULL)  // 如果当前节点存在左节点，将当前节点入栈，指针移向它的左节点
		{
			rootStack.push(currNode);
			currNode = currNode->left;
		}
		
		
		// 该左节点的根节点
		currNode = rootStack.top();
		rootStack.pop();
		ans.push_back(currNode->val);

		// 开始遍历该节点的右节点
		currNode = currNode->right;  // 此时的节点是新的右节点

	
	}
	return ans;
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
// 后序遍历 迭代 完成
/*************函数说明*******************
* 解决方案：迭代
				* 1、入栈，保证退出循环的时候是空节点，且栈顶元素一定是叶子节点
				* 2、出栈，栈顶元素一定是叶子节点，出栈并入队
				* 3、更新节点，取下一个栈顶节点，如果刚刚入队的节点是这个节点的左\右节点，将这个节点的左\右节点赋NULL（避免陷入push-pop循环）
				*	 最后将当前节点更新为它的右孩子
			迭代（参考网络）
				1、从根节点开始依次迭代，弹出栈顶元素输出到输出列表中；
				2、依次压入他的所有孩子节点，按照从上到下、从左至右的顺序依次压入栈中。（因为后序遍历的顺序是从下到上、从左至右）然后将输出列表逆向输出

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
		// 退出循环的这个点为NULL，且栈顶元素为叶子节点
		if (!rootStack.empty())
		{
			currNode = rootStack.top();
			rootStack.pop();
			ans.push_back(currNode->val);  // 对栈顶叶子节点出栈
			if (!rootStack.empty())
			{
				preNode = currNode;
				currNode = rootStack.top();
				// 制造新的叶子节点，删除已经遍历的节点
				if (preNode == currNode->left)  
					currNode->left = NULL;
				else if (preNode == currNode->right)
					currNode->right = NULL;
				
			}
			currNode = currNode->right;  // 更新节点

		}
			
	}	   	 
	return ans;
}
vector<int> CBinaryTree::postorderTraversalRefer(TreeNode* root)
{
	TreeNode* currNode = root, * tempNode = root;
	stack<TreeNode*> rootStack;	
	if (currNode == NULL)  // 如果为空，直接返回
		return ans;

	rootStack.push(currNode);
	while (!rootStack.empty())
	{
		currNode = rootStack.top();  // 先根节点
		rootStack.pop();
		ans.push_back(currNode->val);

		if (currNode->left != NULL)  // 最后左节点（后出栈）
			rootStack.push(currNode->left);
		if (currNode->right != NULL)  // 再右节点
			rootStack.push(currNode->right);
	}
	reverse(ans.begin(), ans.end());  // 逆序输出
	return ans;
}
// 后序遍历 递归
vector<int> CBinaryTree::postorderTraversal2(TreeNode* root) {
	if (root == NULL)
		return ans;
	postorderTraversal2(root->left);
	postorderTraversal2(root->right);
	ans.push_back(root->val);
	return ans;
}

// 层序遍历
/******************函数说明**************
* 实现方案：迭代
		使用两个队列来回切换，一个用于当前层的节点遍历，另一个用于下一层的存储，每次遍历都把队全部遍历完变成空队
		1、从根节点开始，只要当前层还有没有遍历的节点，就继续遍历，并存储节点值，将该节点的左右节点从左往右入队到childQueue中
		2、当前层遍历完成后，如果该层结果向量不为空，将该向量加入到结果向量中，清空临时向量，准备下一层的遍历
		3、开始遍历下一层，按照刚刚入队的顺序从左往右出队，并重复步骤1，只是将队列换成currQueue（即对调两个队）

		迭代：更简化的方法
			也是利用队列，只使用一个队，根据队列的容量决定出队的元素个数以此完成交接

		递归：借助数的高度，返回列表的长度表示当前层的高度，如levelAns.size() = 1,表示当前层是第一层，levelAns[0]就表示第一层的节点
			1、当根节点为空，直接返回；
			2、如果当前层的高度大于返回列表的长度，为返回列表新添一个元素为下一次递归遍历其子节点；
			3、取出当前层的列表，为该列表添加该节点的元素值；
			4、遍历该节点的左右节点。
		递归的关键是运用了vector的随机存储性质，可以取出第level个表。
* 测试信息：12ms，42.55%
**/
vector<vector<int>> CBinaryTree::levelOrder(TreeNode* root) {

	TreeNode* currNode = root;
	queue<TreeNode*> childQueue;  // 存储当前节点的子节点
	queue<TreeNode*> currQueue;  // 存储当前遍历的层
	currQueue.push(currNode);
	while (currNode != NULL &&(!currQueue.empty() || !childQueue.empty()))
	{
		// 此时childStack为空队
		while(!currQueue.empty())
		{
			currNode = currQueue.front();
			currQueue.pop();
			ans.push_back(currNode->val);  // 当前根节点
			if (currNode->left != NULL)
				childQueue.push(currNode->left);
			if (currNode->right != NULL)
				childQueue.push(currNode->right);
			
		}
		if (!ans.empty())
			levelAns.push_back(ans);
		ans.clear();  // 清空，开始下一层
		// 此时currQueue为空队
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
		ans.clear();  // 清空，开始下一层


	}

	return levelAns;
}

// 递归实现
vector<vector<int>> CBinaryTree::levelOrder2(TreeNode* root)
{
	TreeNode* currNode = root;
	int level = 0;
	if (currNode == NULL)
		return levelAns;
	levelHelper(currNode, level);
	return levelAns;
}

vector<vector<int>> CBinaryTree::levelHelper(TreeNode* root, int level)  // 当前根节点所在的层数
{
	if (root == NULL)
		return levelAns;  // 如果为空直接返回
	if (levelAns.size() == level)
	{
		vector<int>* newVec = new vector<int>();    // 如果当前层（因为是从0开始，所以判断条件是=）大于当年返回列表的长度，给列表添加一个元素
		levelAns.push_back(*newVec);
	}
	// 不能用临时变量代替levelAns[level]，temp仅仅是一个变量，不是指向levelAns[level]的指针
	levelAns[level].push_back(root->val);  // 取出当前层对应的表，为表添加元素


	levelHelper(root->left, level + 1);  // 从左往右开始遍历
	levelHelper(root->right, level + 1);

	return levelAns;
}

/*********************************************

==============================================

运用递归解决问题
		自顶向下：在每个递归层级，我们将首先访问节点来计算一些值，并在递归调用函数时将这些值传递到子节点，可以被认为是一种前序遍历。
		自底向上：在递归层次上，我们首先对所有子节点递归地调用函数，然后根据返回值和根节点本身的值得到答案，可以被认为是一种后序遍历。

==============================================


**/


/*****************函数说明********************
* 函数名：int maxDepth(TreeNode* root)
* 函数参数：树的根节点
* 函数返回值：返回这棵树的深度
* 实现方案：


**/


int CBinaryTree::maxDepth(TreeNode* root)
{
	if (!root)  // 如果根节点为空
		return maxdepth;
	
	// maxdepth = topDown(root, 1);
	maxdepth = bottomUp(root);
	return maxdepth;
}
// 自顶向下
// 20ms，17.38
int CBinaryTree::topDown(TreeNode* root, int depth)
{
	if (!root)  // 如果根节点为空
		return depth;
	int leftDepth = 0, rightDepth = 0;
	leftDepth = topDown(root->left, depth + 1);  // 不为空的时候深度加1
	rightDepth = topDown(root->right, depth + 1);  

	return max(leftDepth, rightDepth);

}
// 自底向上
// 20ms， 17.38%
int CBinaryTree::bottomUp(TreeNode* root)
{
	if (!root)
		return 0;
	int leftDepth = 0, rightDepth = 0;

	leftDepth = bottomUp(root->left) + 1;  // 每返回一次 + 1
	rightDepth = bottomUp(root->right) + 1;

	return max(leftDepth, rightDepth);
}

// 层序遍历（超级慢，2428s）
int CBinaryTree::maxDepthLevel(TreeNode * root)
{
	vector<vector<int>>ans = levelHelper(root, 0);
	maxdepth = ans.size();
	
	return maxdepth;
	

}
/***************************


* 解决方案：
	参考答案的数对思想
	还是有点麻烦
	其实和前序遍历自己实现的时候思想一致，把每个节点的所有左节点都压栈，然后再出栈，出栈的时候考虑再压右节点，没有右节点继续出栈
* 测试信息：
执行用时 :12 ms, 在所有 C++ 提交中击败了73.50%的用户
内存消耗 :19 MB, 在所有 C++ 提交中击败了89.72%的用户

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
			nodeStack.push(nodePair);  // 当前节点入栈
			currNode = currNode->left;

		}
		maxdepth = max(depth, maxdepth);
		if (!nodeStack.empty())  // 如果栈不为空
		{
			// 出栈
			currNode = nodeStack.top().first;			
			depth = nodeStack.top().second;
			nodeStack.pop();
			if(currNode->right)
				currNode = currNode->right;
			else if (!nodeStack.empty())
			{
				// 出栈
				currNode = nodeStack.top().first;
				depth = nodeStack.top().second;
				nodeStack.pop();
				
				// 更新为右节点
				currNode = currNode->right;
			}
			else
			// 更新为右节点
			currNode = currNode->right;
		}
	}
	return maxdepth;

}
// 执行用时 :12 ms, 在所有 C++ 提交中击败了73.50 %的用户
// 内存消耗 :19.2 MB, 在所有 C++ 提交中击败了69.52 %的用户
// 复现网络，实质上是前序遍历的思想，出根节点压子节点
int CBinaryTree::maxDepthIterationRefer(TreeNode* root)
{
	int depth = 0;
	TreeNode* currNode = root;
	stack<pair<TreeNode*, int>>nodeStack;  // 定义元素是数对的栈
	pair<TreeNode*, int> nodePair;  // 定义数对，第一个元素是树的节点，第二个元素是该节点的值
	if (root == NULL)
		return 0;
	// 如果不为空树的话，从根节点开始出栈，出栈的同时将左右非空节点都压栈
	nodePair.first = currNode;
	nodePair.second = 1;
	nodeStack.push(nodePair);
	while (!nodeStack.empty())
	{
		// 取出栈顶元素
		nodePair = nodeStack.top();
		nodeStack.pop();
		depth = nodePair.second;
		currNode = nodePair.first;

		// 比较深度信息，取最大值
		maxdepth = max(maxdepth, depth);  

		// 对左右非空节点压栈
		if(currNode->left)
			nodeStack.push(make_pair(currNode->left, depth + 1));
		if(currNode->right)
			nodeStack.push(pair<TreeNode*, int>(currNode->right, depth + 1));
	}
	return maxdepth;
}