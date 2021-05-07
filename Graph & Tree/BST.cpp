/*
Resources:
https://iishanto.com/binary-search-tree-bengali-tutorial/
https://www.geeksforgeeks.org/relationship-number-nodes-height-binary-tree/
https://www.geeksforgeeks.org/write-a-c-program-to-find-the-maximum-depth-or-height-of-a-tree/
https://afteracademy.com/blog/find-the-height-of-a-binary-tree
https://afteracademy.com/blog/binary-search-tree-introduction-operations-and-applications
https://www.freecodecamp.org/news/binary-search-trees-bst-explained-with-examples/
*/

#include <iostream>
using namespace std;


#define NULL 0
#define MAX_INT 2147483647
#define MIN_INT -2147483647

typedef struct BST
{
	int value;
	struct BST* left, * right;
}BST_NODE;

BST_NODE* root;

BST_NODE* _createBstNode(int num)
{
	BST_NODE* newNode = new BST_NODE();
	newNode->value = num;
	newNode->left = newNode->right = NULL;
	return newNode;
}

BST_NODE* _insertIntoBst(BST_NODE* root, int num)
{
	if (root == NULL) return _createBstNode(num);
	else if (num <= root->value)
	{
		root->left = _insertIntoBst(root->left, num);
	}
	else
	{
		root->right = _insertIntoBst(root->right, num);
	}
	return root;
}

int _getMinimumValue(BST_NODE* root)
{
	if (root == NULL) return INT_MAX;
	if (root->left == NULL) return root->value;

	return _getMinimumValue(root->left);
}

int _getMaximumValue(BST_NODE* root)
{
	if (root == NULL) return INT_MIN;
	if (root->right == NULL) return root->value;

	return _getMaximumValue(root->right);
}

BST_NODE* _searchInBst(BST_NODE* root, int num)
{
	if (root == NULL || root->value == num) return root;
	else if (num < root->value) return _searchInBst(root->left, num);
	else return _searchInBst(root->right, num);
}

/*
// iterative search function
BST_NODE* _searchInBst(BST_NODE* root, int num)
{
	BST_NODE* curr = root;
	while (curr && curr->value != num)
	{
		if (num <= curr->value) curr = curr->left;
		else curr = curr->right;
	}
	return curr;
}
*/

BST_NODE* _deleteNodeFromBst(BST_NODE* root, int num)
{
	if (root == NULL) return NULL;	//tree is empty or given number could not be found

	if (num < root->value) root->left = _deleteNodeFromBst(root->left, num);
	else if (num > root->value) root->right = _deleteNodeFromBst(root->right, num);
	else
	{
		// found the number
		// the node contains no child (leaf node)
		if (root->left == NULL && root->right == NULL)
		{
			delete(root);
			root = NULL;
		}
		// the node has only left child
		else if (root->left != NULL && root->right == NULL)
		{
			BST_NODE* tmp = root->left;
			delete(root);
			root = tmp;
		}
		// the node has only right child
		else if (root->left == NULL && root->right != NULL)
		{
			BST_NODE* tmp = root->right;
			delete(root);
			root = tmp;
		}
		// the node has both left & right child
		else
		{
			// find the node with min value from right side of the node, then replace value of this node with that
			int minValue = _getMinimumValue(root->right);
			root->value = minValue;
			// delete the node with min value from right side
			root->right = _deleteNodeFromBst(root->right, minValue);
		}
	}
	return root;
}

// this function returns total number of nodes in the bst
int _getTreeSize(BST_NODE* root)
{
	if (root == NULL) return 0;

	return (1 + _getTreeSize(root->left) + _getTreeSize(root->right));
}

// The height of the binary tree is the longest path from root node to any leaf node in the tree.
// considering height of tree containing only root node is 1
int _getTreeHeight(BST_NODE* root)
{
	if (root == NULL) return 0;

	/*
	* // if we consider height of tree containing only root node is 0
	if(root && root->left==NULL && root->right==NULL) return 0;
	*/

	int lHeight = _getTreeHeight(root->left);
	int rHeight = _getTreeHeight(root->right);
	return (lHeight > rHeight ? (lHeight + 1) : (rHeight + 1));
}

void _inOrder(BST_NODE* root)
{
	if (root == NULL) return;
	_inOrder(root->left);
	cout << root->value << " ";
	_inOrder(root->right);
}

void _showOperation()
{
	cout << "------------------------------" << endl;
	cout << "1. Insert new value into BST" << endl;
	cout << "2. Delete given value from BST" << endl;
	cout << "3. Print min value of BST" << endl;
	cout << "4. Print max value of BST" << endl;
	cout << "5. Print all values of BST" << endl;
	cout << "6. Search values in BST" << endl;
	cout << "7. Print tree size" << endl;
	cout << "8. Print height of tree" << endl;
	cout << "9. Terminate" << endl;
	cout << "------------------------------" << endl;
}

void _init()
{
	root = NULL;
}
int main()
{
	_init();
	int operation, num;

	while (true)
	{
		_showOperation();
		cin >> operation;

		if (operation == 1)
		{
			cout << "Give a value to insert: ";
			cin >> num;
			root = _insertIntoBst(root, num);
		}
		else if (operation == 2)
		{
			cout << "Give a value to delete: ";
			cin >> num;
			root = _deleteNodeFromBst(root, num);
		}
		else if (operation == 3)
		{
			num = _getMinimumValue(root);
			if (num == INT_MAX) cout << "-->Tree is empty!";
			else cout << "-->Min: " << num << endl;
		}
		else if (operation == 4)
		{
			num = _getMaximumValue(root);
			if (num == INT_MIN) cout << "Tree is empty!";
			else cout << "-->Max: " << num << endl;
		}
		else if (operation == 5)
		{
			_inOrder(root);
			cout << endl;
		}
		else if (operation == 6)
		{
			cout << "Give a value to search: ";
			cin >> num;
			BST* node = _searchInBst(root, num);
			if (node == NULL) cout << "\n-->Given value is not present in the BST" << endl;
			else cout << "\n-->Given value is present in the BST" << endl;
		}
		else if (operation == 7) cout << "\n-->Tree size: " << _getTreeSize(root) << endl;
		else if (operation == 8) cout << "\n-->Tree height: " << _getTreeHeight(root) << endl;
		else if (operation == 9) break;
	}
}
