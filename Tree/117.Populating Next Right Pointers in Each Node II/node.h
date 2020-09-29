#pragma once
#include <cstddef>

// Definition for a Node.
class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node* next;

	Node() : val(0), left(NULL), right(NULL), next(NULL) {}

	Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

	Node(int _val, Node* _left, Node* _right, Node* _next)
		: val(_val), left(_left), right(_right), next(_next) {}
};

class BiTree {
public:
	Node* root;
	vector<Node*> nodes;

	BiTree() : root(NULL), nodes(NULL) {}

	// Construct a binary tree using the nodes stored in vector
	BiTree(vector<int> nodeValues) {
		int nodeNum = nodeValues.size();
		int fullLayerNum = floor(sqrt(nodeNum));
		int bottomLeafNum = nodeNum - pow(2, fullLayerNum) + 1;

		int cnt = 0;

		if (!(bottomLeafNum % 2))
			cnt = pow(2, (fullLayerNum - 1)) - 1 + bottomLeafNum / 2;
		else {
			cnt = pow(2, (fullLayerNum - 1)) + bottomLeafNum / 2;
			nodeValues.push_back(666);
		}

		for (int i = 0; i < nodeValues.size(); i++) {
			if (nodeValues[i] == 666)
				nodes.push_back(NULL);
			else
				nodes.push_back(new Node(nodeValues[i]));
		}
		
		for (int i = 0; i < cnt; i++) {
			if (nodes[i]){
				nodes[i]->left = nodes[2 * i + 1];
				nodes[i]->right = nodes[2 * i + 2];
			}
		}

		root = nodes[0];
	}

	void printConnection() {
		cout << "The nodes in each layer are linked in the following order:" << endl;
		int layerHead = 0;
		Node* curNode = nodes[layerHead];

		while (true) {
			if (!curNode) {
				int num = pow(2, layerHead) - 1;
				while (!curNode && num < pow(2, (layerHead+1)) - 2) {
					curNode = nodes[num];
					num++;
				}
			}

			// Print connection list in current layer
			while (curNode) {
				cout << curNode->val << ", ";
				curNode = curNode->next;
			}
			cout << "#" << endl;

			// Move to the head of the next layer
			if (++layerHead > floor(sqrt(nodes.size())))
				break;
			curNode = nodes[pow(2, layerHead) - 1];
		}
	}
};

// 2 1 3 0 7 9 1 2 666 1 0 666 666 8 8 666 666 666 666 7