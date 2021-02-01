/**
1. If: The list contains one or fewer elements, return the same list.
2. Else: Divide the list into halves using the splitting function.
3. Sort: Sort the two halves of the list.
4. At the end, merge the sorted lists.

Resources:
https://www.educative.io/edpresso/how-to-sort-a-linked-list-using-merge-sort
https://www.geeksforgeeks.org/merge-sort-for-linked-list/

Problem:
https://practice.geeksforgeeks.org/problems/sort-a-linked-list/1
*/

#include<bits/stdc++.h>
using namespace std;

typedef struct Node
{
    int val;
    struct Node *next;
}LL;

LL *create(int val)
{
    LL *n = new LL; // in c -> LL *n = (LL *)malloc(sizeof(LL));
    n->val = val;
    n->next = NULL;
    return n;
}
LL *insertAtLast(LL *head, int val) // O(N)
{
    LL *node = create(val);
    if(!head) return node;

    LL *curr = head;
    while(curr->next) curr = curr->next;    // traversing to the last node
    curr->next = node;
    return head;
}

LL *_getMiddleNode(LL *root)
{
    LL *slow = root, *fast = root->next;
    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

/*
This function splits the list into 2 halves
If the size of the list is odd, then extra element goes in the first list.
*/
void _splitList(LL *curr, LL *&left, LL *&right)
{
    LL *middleNode = _getMiddleNode(curr);
    left = curr;
    right = middleNode->next;
    middleNode->next = NULL;
}

/* this function merge 2 sorted list */
LL *_merge(LL *left, LL *right)
{
    if(!left) return right;
    if(!right) return left;

    LL *head = NULL, *curr = NULL;
    while(left && right)
    {
        if(left->val < right->val)
        {
            if(!head) head = left, curr = head;
            else curr->next = left, curr = curr->next;
            left = left->next;
        }
        else
        {
            if(!head) head = right, curr = head;
            else curr->next = right, curr = curr->next;
            right = right->next;
        }
    }
    while(left)
    {
        if(!head) head = left, curr = head;
        else curr->next = left, curr = curr->next;
        left = left->next;
    }
    while(right)
    {
        if(!head) head = right, curr = head;
        else curr->next = right, curr = curr->next;
        right = right->next;
    }

    return head;
}

void _mergeSort(LL *&root)
{
    if(!root || !root->next) return ;
    LL *curr = root, *left, *right;

    _splitList(curr, left, right);

    // Recursively sorting two lists.
    _mergeSort(left);
    _mergeSort(right);

    root = _merge(left, right);
}

void printList(LL *head)
{
    if(!head)
    {
        cout<<"********List is empty********"<<endl;
        return ;
    }

    cout<<"--------- Printing List ---------"<<endl;
    LL *curr = head;
    while(curr)
    {
        cout<<curr->val<<" ";
        curr = curr->next;
    }
    cout<<endl;
    cout<<"---------------------------------"<<endl;
}

int main()
{
    int sz, num;
    LL *root = NULL;
    cout<<"Give size of the list: ";
    cin>>sz;
    cout<<"Give elements of list: ";
    for(int i=0;i<sz;i++)
    {
        cin>>num;
        root = insertAtLast(root, num);
    }
    printList(root);
    _mergeSort(root);
    cout<<"after sorting: "<<endl;
    printList(root);
}

/*
6
6 1 -4 3 -2 5
*/
