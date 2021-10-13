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

		/* ������������� */
		void traverse(TreeNode<T>* root) {
			// ǰ�����
			traverse(root->left);
			// �������
			traverse(root->right);
			// �������
		}
		// ���壺count(root) ������ root Ϊ�������ж��ٽڵ�
		int count(TreeNode<T>* root) {
			// base case
			if (root == nullptr) return 0;
			// �Լ����������Ľڵ��������������Ľڵ���
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
