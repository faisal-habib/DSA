/**
Resources:
https://www.tutorialcup.com/interview/tree/convert-bst-to-min-heap.htm
https://www.techiedelight.com/convert-binary-search-tree-into-min-heap/
https://www.geeksforgeeks.org/convert-bst-min-heap/
https://www.geeksforgeeks.org/in-place-convert-bst-into-a-min-heap/
*/
#include<bits/stdc++.h>
using namespace std;

// Data structure to store a binary tree node
struct Node
{
    int key;
    Node *left, *right;
};

// Function to create a new binary tree node having a given key
Node* newNode(int key)
{
    Node* node = new Node;
    node->key = key;
    node->left = node->right = NULL;

    return node;
}

// Recursive function to insert a key into a BST
Node* insert(Node* root, int key)
{
    // if the root is null, create a new node and return it
    if (root == NULL) {
        return newNode(key);
    }

    // if the given key is less than the root node, recur for the left subtree
    if (key < root->key) {
        root->left = insert(root->left, key);
    }

    // if the given key is more than the root node, recur for the right subtree
    else {
        root->right = insert(root->right, key);
    }

    return root;
}

// Helper function to perform level order traversal on a binary tree
void printLevelOrderTraversal(Node* root)
{
    // base case: empty tree
    if (root == NULL) {
        return;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty())
    {
        int n = q.size();
        while (n--)
        {
            Node* front = q.front();
            q.pop();

            cout << front->key << ' ';

            if (front->left) {
                q.push(front->left);
            }

            if (front->right) {
                q.push(front->right);
            }
        }

        cout << endl;
    }
}

// Function to perform inorder traversal on a given binary tree and
// enqueue all nodes (in encountered order)
void inorder(Node* root, queue<int> &keys)
{
    if (root == NULL) {
        return;
    }

    inorder(root->left, keys);
    keys.push(root->key);
    inorder(root->right, keys);
}

// Function to perform preorder traversal on a given binary tree.
// Assign each encountered node with the next key from the queue
void preorder(Node* root, queue<int> &keys)
{
    // base case: empty tree
    if (root == NULL) {
        return;
    }

    // replace the root's key value with the next key from the queue
    cout<<root->key<<" ";
    root->key = keys.front();
    keys.pop();

    // process left subtree
    preorder(root->left, keys);

    // process right subtree
    preorder(root->right, keys);
}

// Function to convert a BST into a min-heap
void convert(Node* root)
{
    // maintain a queue to store inorder traversal on the tree
    queue<int> keys;

    // fill the queue in an inorder fashion
    inorder(root, keys);

    // traverse tree in preorder fashion, and for each encountered node,
    // dequeue a key and assign it to the node
    cout<<"Pre order: ";
    preorder(root, keys);
    cout<<endl;
}

int main()
{
    vector<int> keys = { 5, 3, 2, 4, 8, 6, 10 };

    /* Construct the following BST
               5
             /   \
            /     \
           3       8
          / \     / \
         /   \   /   \
        2     4 6    10
    */

    Node* root = NULL;
    for (int key: keys) {
        root = insert(root, key);
    }

    convert(root);
    printLevelOrderTraversal(root);

    return 0;
}
