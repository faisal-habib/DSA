/*
Resources:
https://iishanto.com/avl-tree-bangla-tutorial-1/
https://www.geeksforgeeks.org/avl-tree-set-1-insertion/

Delettion->
https://www.guru99.com/avl-tree.html#11
https://www.geeksforgeeks.org/avl-tree-set-2-deletion/
Problems:
https://practice.geeksforgeeks.org/problems/avl-tree-insertion/1#
https://practice.geeksforgeeks.org/problems/avl-tree-deletion/1
*/

#include <iostream>
#include<queue>
using namespace std;

#define NULL 0
#define MAX(a, b) ( (a > b) ? (a) : (b) )

typedef struct AVL_TREE
{
    int value;
    struct AVL_TREE* left, * right;
    int height;
} AVL_NODE;

AVL_NODE* root;

AVL_NODE* _createNode(int num)
{
    AVL_NODE* newNode = new AVL_NODE();
    newNode->height = 1;
    newNode->value = num;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int _getMinimumValue(AVL_NODE* root)	// left most value of the tree will be min value
{
    if (root == NULL) return INT_MAX;
    if (root->left == NULL) return root->value;

    return _getMinimumValue(root->left);
}

int _getMaximumValue(AVL_NODE* root)	// right most value of the tree will be mac value
{
    if (root == NULL) return INT_MAX;
    if (root->right == NULL) return root->value;

    return _getMaximumValue(root->right);
}

// this function returns total number of nodes in the bst
int _getTreeSize(AVL_NODE* root)
{
    if (root == NULL) return 0;

    return (1 + _getTreeSize(root->left) + _getTreeSize(root->right));
}

int _getHeight(AVL_NODE* root)
{
    if (root == NULL) return 0;
    return root->height;
}

int _getBalanceFactor(AVL_NODE* root)
{
    if (root == NULL) return 0;
    return (_getHeight(root->left) - _getHeight(root->right));
}

AVL_NODE* _leftRotation(AVL_NODE* root)
{
    if (root == NULL) return root;

    AVL_NODE* newRootNode = root->right;
    AVL_NODE* tmpNode = newRootNode->left;

    // performing rotation
    newRootNode->left = root;
    root->right = tmpNode;

    // updating height
    root->height = 1 + MAX(_getHeight(root->left), _getHeight(root->right));
    newRootNode->height = 1 + MAX(_getHeight(newRootNode->left), _getHeight(newRootNode->right));

    return newRootNode;
}

AVL_NODE* _rightRotation(AVL_NODE* root)
{
    if (root == NULL) return root;

    AVL_NODE* newRootNode = root->left;
    AVL_NODE* tmpNode = newRootNode->right;

    // performing rotation
    newRootNode->right = root;
    root->left = tmpNode;

    // updating height
    root->height = 1 + MAX(_getHeight(root->left), _getHeight(root->right));
    newRootNode->height = 1 + MAX(_getHeight(newRootNode->left), _getHeight(newRootNode->right));

    return newRootNode;
}

AVL_NODE* _insertIntoAvlTree(AVL_NODE* root, int num)
{
    if (root == NULL) return _createNode(num);
    else if (num < root->value) root->left = _insertIntoAvlTree(root->left, num);
    else if (num > root->value) root->right = _insertIntoAvlTree(root->right, num);
    else return root;   // considering there'll be no duplicate value. So returning the tree as it was.

    root->height = 1 + MAX(_getHeight(root->left), _getHeight(root->right));

    int balanceFactor = _getBalanceFactor(root);    // diff between height of left sub tree & height of right sub tree


    if (balanceFactor > 1)
    {
        if (num < root->left->value)	// L-L  (ex. 30, 20, 10)
        {
            return _rightRotation(root);
        }
        else if (num > root->left->value)	// L-R  (ex. 30, 10, 20)
        {
            root->left = _leftRotation(root->left);
            return _rightRotation(root);
        }

    }
    else if (balanceFactor < -1)
    {
        if (num > root->right->value)	// R-R  (ex. 10, 20, 30)
        {
            return _leftRotation(root);
        }
        else if (num < root->right->value)	// R-L  (ex. 10, 30, 20)
        {
            root->right = _rightRotation(root->right);
            return _leftRotation(root);
        }
    }

    return root;
}

AVL_NODE* _deleteNodeFromAvlTree(AVL_NODE* root, int num)
{
    // first perform delete operation exactly like bst
    if (root == NULL) return NULL;
    else if (num < root->value) root->left = _deleteNodeFromAvlTree(root->left, num);
    else if (num > root->value) root->right = _deleteNodeFromAvlTree(root->right, num);
    else
    {
        // node contains no child (leaf node)
        if (root->left == NULL && root->right == NULL)
        {
            delete(root);
            root = NULL;
        }
        // node has only left child
        else if (root->left != NULL && root->right == NULL)
        {
            AVL_NODE* tmp = root->left;
            delete(root);
            root = tmp;
        }
        // node has only right child
        else if (root->left == NULL && root->right != NULL)
        {
            AVL_NODE* tmp = root->right;
            delete(root);
            root = tmp;
        }
        // node has both left & right child
        else
        {
            int minValOfRightSubTree = _getMinimumValue(root->right);
            root->value = minValOfRightSubTree;
            /// delete the node with min value from right sub tree
            root->right = _deleteNodeFromAvlTree(root->right, minValOfRightSubTree);
        }
    }

    if (root == NULL) return root;

    /// update height and balance factor like insert operation
    root->height = 1 + MAX(_getHeight(root->left), _getHeight(root->right));

    int balanceFactor = _getBalanceFactor(root);    /// diff between height of left sub tree & height of right sub tree
    if (balanceFactor < -1)
    {
        /// deletion was done from left sub tree. so height of right sub tree got bigger
        int balanceFactoreOfRightSubTree = _getBalanceFactor(root->right);

        //case 1: Ex. 10->30->20 . R-L roation requires.
        if (balanceFactoreOfRightSubTree == 1)
        {
            root->right = _rightRotation(root->right);
            return _leftRotation(root);
        }
        //case 2: Ex. 10->20->30 . R-R roation requires.
        else if (balanceFactoreOfRightSubTree == -1)
        {
            return _leftRotation(root);
        }
        //case 2: Ex. 10->30->20->35 . R-R/R-L any of rotation can be performed.
        else if (balanceFactoreOfRightSubTree == 0)
        {
            return _leftRotation(root);
        }
    }
    else if (balanceFactor > 1)
    {
        /// deletion was done from right sub tree. so height of left sub tree got bigger
        int balanceFactoreOfLeftSubTree = _getBalanceFactor(root->left);

        //case 1: Ex. 30->20->10 . L-L roation requires.
        if (balanceFactoreOfLeftSubTree == 1)
        {
            return _rightRotation(root);
        }
        //case 2: Ex. 30->10->20 . L-R roation requires.
        else if (balanceFactoreOfLeftSubTree == -1)
        {
            root->left = _leftRotation(root->left);
            return _rightRotation(root);
        }
        //case 2: Ex. 30->10->5->20 . L-R/L-L any of rotation can be performed.
        else if (balanceFactoreOfLeftSubTree == 0)
        {
            return _rightRotation(root);
        }
    }

    return root;
}

AVL_NODE* _searchInAvlTree(AVL_NODE* root, int num)
{
    if (root == NULL || root->value == num) return root;
    else if (num < root->value) return _searchInAvlTree(root->left, num);
    else return _searchInAvlTree(root->right, num);
}

/**
// iterative search function
AVL_NODE* _searchInAvlTree(AVL_NODE* root, int num)
{
	AVL_NODE* curr = root;
	while (curr && curr->value != num)
	{
		if (num <= curr->value) curr = curr->left;
		else curr = curr->right;
	}
	return curr;
}
*/

void _levelOrderTraversal(AVL_NODE* root)
{
    if (root == NULL)
    {
        cout << "-->Empty tree!" << endl;
        return;
    }

    queue<AVL_NODE*>q;
    q.push(root);

    cout << "-->Level order traversal: ";
    while (!q.empty())
    {
        AVL_NODE* currNode = q.front();
        q.pop();

        cout << currNode->value << " ";
        if (currNode->left) q.push(currNode->left);
        if (currNode->right) q.push(currNode->right);
    }
    cout << endl;
}

void _inOrder(AVL_NODE* root)
{
    if (root == NULL) return;
    _inOrder(root->left);
    cout << root->value << " ";
    _inOrder(root->right);
}

void _showOperation()
{
    cout << "------------------------------" << endl;
    cout << "1. Insert new value into AVL tree" << endl;
    cout << "2. Delete given value from AVL tree" << endl;
    cout << "3. Print min value of AVL tree" << endl;
    cout << "4. Print max value of AVL tree" << endl;
    cout << "5. Print all values of AVL tree in sorted order" << endl;
    cout << "6. Search values in AVL tree" << endl;
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
            root = _insertIntoAvlTree(root, num);
        }
        else if (operation == 2)
        {
            cout << "Give a value to delete: ";
            cin >> num;
            root = _deleteNodeFromAvlTree(root, num);
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
            if (num == INT_MIN) cout << "-->Tree is empty!";
            else cout << "-->Max: " << num << endl;
        }
        else if (operation == 5)
        {
            cout << "-->Tree values in sorted order: ";
            _inOrder(root);
            cout << endl;
        }
        else if (operation == 6)
        {
            cout << "Give a value to search: ";
            cin >> num;
            AVL_NODE* node = _searchInAvlTree(root, num);
            if (node == NULL) cout << "\n-->Given value is not present in the AVL tree" << endl;
            else cout << "\n-->Given value is present in the BST" << endl;
        }
        else if (operation == 7) cout << "\n-->Tree size: " << _getTreeSize(root) << endl;
        else if (operation == 8) cout << "\n-->Tree height: " << _getHeight(root) << endl;
        else if (operation == 9) break;

        _levelOrderTraversal(root);
    }
}

/*
insert values:
10
20
30
25
28
27
5

level order output: 25 10 28 5 20 27 30
*/

/*
		30
	   /   \
	10		40
	/\
   5  20

		10
	   /  \
	  5	  30
		  /\
		20  35
*/
