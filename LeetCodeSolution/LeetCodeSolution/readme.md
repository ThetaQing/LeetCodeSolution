# 引言
LeetCode

# 一、初级算法
第一部分，初级算法，主要是入门级练习，其中包括初级算法模块、链表模块、二叉树模块。  
## 1.1 数组：[basic_algorithm_array.cpp](https://github.com/ThetaQing/LeetCodeSolution/blob/master/LeetCodeSolution/LeetCodeSolution/basic_algorithm_array.cpp)  
这部分是初级算法模块的[数组](https://leetcode-cn.com/explore/featured/card/top-interview-questions-easy/1/array/)练习内容.  
主要包括：  
  26、从排序数组中删除重复项  
  122、买卖股票的最佳时机 II  
  189、旋转数组  
  217存在重复元素  
  136、只出现一次的数字  
  350、两个数组的交集 II  
  66、加一  
  283、移动零  
  1、两数之和  
  36、有效的数独  
  旋转图像  
    
    
## 1.2 字符串：[basic_algorithm_string.cpp](https://github.com/ThetaQing/LeetCodeSolution/blob/master/LeetCodeSolution/LeetCodeSolution/basic_algorithm_string.cpp)  
这部分是初级算法模块的[字符串](https://leetcode-cn.com/explore/featured/card/top-interview-questions-easy/5/strings/)内容。  
主要包括：  
  344、反转字符串  
  7、整数反转  
  387字符串中的第一个唯一字符  
  242、有效的字母异位词  
  125、验证回文字符串  
  8、字符串转换整数 (atoi)  
  28、实现 strStr()  
  38、报数  
  14、最长公共前缀  
    
## 1.3 链表：[basic_algorithm_linkedList.cpp](https://github.com/ThetaQing/LeetCodeSolution/blob/master/LeetCodeSolution/LeetCodeSolution/basic_algorithm_linkedList.cpp)  
  这部分前六个题是初级算法模块的[链表](https://leetcode-cn.com/explore/featured/card/top-interview-questions-easy/6/linked-list/)内容，后面那部分是[链表模块](https://leetcode-cn.com/explore/learn/card/linked-list/)内容。  
  主要包括：  
  237、删除链表中的节点  
  19、删除链表的倒数第N个节点  
  206、反转链表  
  88、合并两个有序链表  
  234、回文链表  
  141、环形链表  
  142、环形链表 II  
  160、相交链表  
  203、移除链表元素  
  328、奇偶链表
  2、两数相加
  234、回文链表  
  430、扁平化多级双向链表  
  138、复制带随机指针的链表  

## 1.4 二叉树：[basic_algorithm_binaryTree.cpp](https://github.com/ThetaQing/LeetCodeSolution/blob/master/LeetCodeSolution/LeetCodeSolution/basic_algorithm_binaryTree.cpp)  
  这部分是[二叉树模块](https://leetcode-cn.com/explore/learn/card/data-structure-binary-tree/)内容。  
  主要包括;  
  144、二叉树的前序遍历（迭代法、递归法）  
  94、二叉树的中序遍历（迭代法、递归法）  
  145、二叉树的后序遍历（迭代法、递归法）  
  102、二叉树的层序遍历（迭代法、递归法）  
### 1.4.1 数的遍历小结
 * 迭代（官网思路）
  深度优先遍历的迭代都是利用栈的后进先出的性质，广度优先遍历的迭代利用队的先进先出的性质。  
   **先序遍历**：先根节点，再左节点，最后右节点  
    所以从根节点入栈后，对每个节点出栈并打印出栈的这个节点，再压右节点入栈，最后压左节点入栈，直到栈空。   
   **中序遍历**：先左节点，再根节点，最后右节点   
    始终坚持以左为先，先达到最左边，然后打印该节点，最后移向它的右节点。  
    1、先到当前未遍历的树的最左边的最深的节点：只要当前节点不为空，一直对当前节点和它的左节点压栈；  
	2、对栈顶元素出栈并打印，将该节点的右节点视为当前节点进行步骤1.  
   **后序遍历**：先左节点，再右节点，最后根节点  
    1、从根节点开始入栈，再迭代出栈，并对该节点的所有子节点压栈，先压左节点，再压右节点（出栈顺序是：先根、再右、最后左）  
	2、逆向输出  
   **层序遍历**：按层遍历
    根据队列先进先出的性质。
	法一：一个队列，出队个数由初始队的size决定，出完size个节点后输出列表push一次该层节点表  
	法二：两个队列交替进行，直接pop至队为空完成两个层的交接。  
  
 * 递归  
  递归的思路可以简化为三个节点：
   **前序遍历**：先根节点，再左节点，最后右节点  
	所以递归的顺序是，先打印根节点，再递归左节点，最后递归右节点即可。  
   **中序遍历**：先左节点，再根节点，最后右节点  
    所以递归的顺序是，先递归左节点，再打印根节点，最后递归右节点即可。  
   **后序遍历**：先左节点，再右节点，最后根节点  
    所以递归的顺序是，先递归左节点，再递归右节点，最后打印根节点即可。  
   **层序遍历**：按层遍历，稍微有点不同，引入层数  
    层序遍历需要考虑当前层的所有节点，所以引入层数，当层数大于输出列表的长度时，输出列表添加一个新的空表。利用vector的下标索引确定同一层的节点。  
