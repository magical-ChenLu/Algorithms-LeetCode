#pragma once
#include <cstddef>

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}; 

// Search for a node by its value in BST. return pointer
TreeNode* searchBST(TreeNode* root, int target) {
	if (root->val < target)
		return searchBST(root->right, target);
	else if (root->val > target)
		return searchBST(root->left, target);
	else
		return root;
}

// Construct a BST using the nodes stored in vector
TreeNode* constructBST(vector<int> nodes) {
	int nodeNum = nodes.size();
	int cnt = (nodeNum / 2) - 1 + (nodeNum % 2);

	TreeNode* root = new TreeNode(nodes[0]);
	for (int i = 0; i < cnt; i++) {
		TreeNode* curNode = searchBST(root, nodes[i]);
		curNode->left = new TreeNode(nodes[2 * i + 1]);
		curNode->right = new TreeNode(nodes[2 * i + 2]);
	}

	return root;
}