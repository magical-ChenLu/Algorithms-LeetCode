/* ************************************************************************************
LeetCode #235. 
	Lowest Common Ancestor of a Binary Search Tree

Description:
	Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.
	According to the definition of LCA on Wikipedia:
	¡°The lowest common ancestor is defined between two nodes p and q as the lowest node in T
		that has both p and q as descendants (where we allow a node to be a descendant of itself).¡±

Example:	
	Input: root = [6,2,8,0,4,7,9,-1,1,3,5], p = 2, q = 8
	Output: 6
	Input: root = [6,2,8,0,4,7,9,-1,1,3,5], p = 2, q = 5
	Output: 2
	Note: 1. This program does not support "NULL" as input currently;
		  2. The entered BST must conform to the rules of BST.

Trick:
	Use the property of values between parent and child nodes in a BST.
************************************************************************************ */

#include <assert.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

#include "TreeNode.h"

class Solution {
public:
	/* Solution 1: Recursive Approach
	*	Time Complexity: O(N)
	*	Space Complexity: O(N)
	*/
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		int parentVal = root->val;
		int pVal = p->val;
		int qVal = q->val;

		if ((parentVal < pVal) && (parentVal < qVal))
			return lowestCommonAncestor(root->right, p, q);
		else if ((parentVal > pVal) && (parentVal > qVal))
			return lowestCommonAncestor(root->left, p, q);
		else
			return root;
	}

	/* Solution 2: Iterative Approach
	*	Time Complexity: O(N)
	*	Space Complexity: O(1)
	*/
	TreeNode* lowestCommonAncestorIter(TreeNode* root, TreeNode* p, TreeNode* q) {
		TreeNode* curNode = root;
		int pVal = p->val;
		int qVal = q->val;

		while (curNode != NULL) {
			int parentVal = curNode->val;

			if ((parentVal < pVal) && (parentVal < qVal))
				curNode = curNode->right;
			else if ((parentVal > pVal) && (parentVal > qVal))
				curNode = curNode->left;
			else
				return curNode;
		}

		return NULL;
	}
};

int main() {
	cout << "Lowest Common Ancestor of a Binary Search Tree" << endl;

	vector<int> nodes;	// Store input node values
	int p, q;			// Nodes that need to find LCA
	
	// Read input and store in vector
	cout << "Please insert a BST:" << endl;
	int num = 0;
	do {
		cin >> num;
		nodes.push_back(num);
	} while (getchar() != '\n');

	// Verify input BST nodes
	/*cout << "The input BST:" << endl;
	for (int i = 0; i < nodes.size(); i++) {
		cout << nodes[i] << "\t";
	}
	cout << endl;*/

	cout << "Please specify node p and q:" << endl;
	cin >> p;	cin >> q;

	TreeNode* root = constructBST(nodes);
	TreeNode* pNode = searchBST(root, p);
	TreeNode* qNode = searchBST(root, q);

	Solution sol;
	TreeNode* lca = sol.lowestCommonAncestorIter(root, pNode, qNode);

	cout << "The LCA of nodes " << p << " and " << q << " is " << lca->val << "." << endl;
}