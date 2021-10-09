#pragma once
namespace BinaryTree
{
	template<class T=int>
	class TreeNode
	{
	public:
		TreeNode() :data(0) {};
		TreeNode(T initdata) :data(initdata) {};
		TreeNode* left=nullptr;
		TreeNode* right=nullptr;
		T data;
	};

	template<class T=int>
	class binaryTreePrefab
	{
	public:
		TreeNode<T> root;

		/* 二叉树遍历框架 */
		void traverse(TreeNode<T>* root) {
			// 前序遍历
			traverse(root->left);
			// 中序遍历
			traverse(root->right);
			// 后序遍历
		}
		// 定义：count(root) 返回以 root 为根的树有多少节点
		int count(TreeNode<T>* root) {
			// base case
			if (root == nullptr) return 0;
			// 自己加上子树的节点数就是整棵树的节点数
			return 1 + count(root->left) + count(root->right);
		}
		/// <summary>
		/// Insert a new Node, left is primary,if left and right are both occupied,return fasle then.
		/// </summary>
		/// <param name="parentNode"></param>
		/// <param name="newNode"></param>
		/// <returns>if insertion is success, return ture</returns>
		bool addNode(TreeNode<T>* parentNode,TreeNode<T>* newNode)
		{
			if (!parentNode->left)parentNode->left = newNode;
			else if (!parentNode->right)parentNode->right = newNode;
			else return false;
			return true;
		}
		void flip(TreeNode<T>* root)
		{
			if (!root)return;
			auto temp = root->left;
			root->left = root->right;
			root->right = temp;
			flip(root->left);
			flip(root->right);
		}
	};

}
