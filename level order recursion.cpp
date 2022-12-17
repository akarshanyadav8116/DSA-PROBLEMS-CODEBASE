#include <bits/stdc++.h>
using namespace std;

class node {
public:
	int data;
	node *left, *right;

	node(int v)
	{
	    data = v;
	    left = NULL;
	    right = NULL;
	}
};

void printCurrentLevel(node* root, int level);

int height(node* node);
node* newNode(int data);


void printLevelOrder(node* root)
{
	int h = height(root);
	int i;
	for (i = 1; i <= h; i++)
		printCurrentLevel(root, i);
}

void printCurrentLevel(node* root, int level)
{
	if (root == NULL)
		return;
	if (level == 1)
		cout << root->data << " ";
	else if (level > 1) {
		printCurrentLevel(root->left, level - 1);
		printCurrentLevel(root->right, level - 1);
	}
}

int height(node* node)
{
	if (node == NULL)
		return 0;
	else {
		int lheight = height(node->left);
		int rheight = height(node->right);

		if (lheight > rheight) {
			return (lheight + 1);
		}
		else {
			return (rheight + 1);
		}
	}
}
/* Driver code*/
int main()
{
	node* root = new node(1);
	root->left = new node(2);
	root->right = new node(3);
	root->left->left = new node(4);
	root->left->right = new node(5);

	cout << "Level Order traversal of binary tree is \n";
	printLevelOrder(root);

	return 0;
}

// This code is contributed by rathbhupendra
