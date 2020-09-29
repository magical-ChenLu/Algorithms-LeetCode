/* *********************************************************************************
LeetCode #117
	Populating Next Right Pointers in Each Node II

Description:
	Given a binary tree, Populate each next pointer to point to its next right node. 
	If there is no next right node, the next pointer should be set to NULL.
	Initially, all next pointers are set to NULL.

Follow up:
	1. You may only use constant extra space.
	2. Recursive approach is fine, you may assume implicit stack space
		does not count as extra space for this problem.

Example:
	Input: root = [1,2,3,4,5,null,7]
	Output: [1,#,2,3,#,4,5,7,#]
	Input: [2,1,3,0,7,9,1,2,null,1,0,null,null,8,8,null,null,null,null,7]
	Output: [2,#,1,3,#,0,7,9,1,#,2,1,0,8,8,#,7,#]
	Note: To simplify, input "null" as 666

Constraints:
	1. The number of nodes in the given tree is less than 6000.
	2. $-100 \leq node.val \leq 100$
********************************************************************************* */

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

#include "node.h"
class Solution {
public:
	/* ---------------------------------------------------------------------
	* Find the nearest neighboring brother node for a child node
	* such brother node must be the child of its parent node's right brother
	* ---------------------------------------------------------------------- */
	Node* findNbrBro(Node* parentNode) {
		Node* parentBro = parentNode->next;
		// If the parent node has no right brother 
		if (!parentBro)
			return NULL;

		// Jump across the nodes with no child
		// Warning: parentBro could be NULL after iteration
		//			i.e. parentBro points to the end of one layer
		while (parentBro) {
			if (!(parentBro->left || parentBro->right))
				parentBro = parentBro->next;
			else
				break;
		}

		if (!parentBro) // If parentBro is NULL, return NULL
			return NULL;
		else // Otherwise, return the leftmost child as the nearest neighboring brother node
			return parentBro->left ? parentBro->left : parentBro->right;
	}

	/* ------------------------------------------------------------------------------------------
	* For any parent node, connect two descendant nodes,
	* such descendant nodes could both be its children, or could have one nephew from its brother.
	* This is a recursive function which traverses all nodes taking parentNode as root in a tree.
	* Note:
	*	We adopt a Top-Down and Back-Front approach,
	*	The reason for using a Top-Down strategy is that we need to take care of the parent nodes 
	*		first, set up their "next" pointer, then can we deal with the child nodes;
	*	As for Back-Front, since we are talking about a recursive function, if we go front-back,
	*		we could find ourselve in a situation that the algorithm tends to first connect the 
	*		left-down subtree. So the connections between nodes in the upper layers are established
	*		after those in lower layers. This is where contradiction happens: to connect child nodes,
	*		we need their parents' connections to be complete.
	* ------------------------------------------------------------------------------------------- */
	Node* connectChild(Node* parentNode) {
		// Terminate Condition: parentNode is NULL
		if (!parentNode)
			return NULL;

		// Back-Front strategy! Right nodes connect first!
		if (parentNode->right) {
			parentNode->right->next = findNbrBro(parentNode);
			connectChild(parentNode->right);
		}

		if (parentNode->left) {
			if (parentNode->right)
				parentNode->left->next = parentNode->right;
			else
				parentNode->left->next = findNbrBro(parentNode);

			connectChild(parentNode->left);
		}

		return parentNode;
	}

	Node* connect(Node* root) {
		return connectChild(root);
	}
};

int main() {
	cout << "Populating Next Right Pointers in Each Node" << endl;

	vector<int> nodes;	// Store input node values

	// Read input and store in vector
	cout << "Please insert nodes in a tree:" << endl;
	int num = 0;
	do {
		cin >> num;
		nodes.push_back(num);
	} while (getchar() != '\n');

	BiTree tree = BiTree(nodes);
	
	Solution sol;
	sol.connect(tree.root);

	tree.printConnection();

	return 1;
}