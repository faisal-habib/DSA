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
/*   "*&" -> references to pointers (call by reference)
https://www.geeksforgeeks.org/reference-to-a-pointer-in-c-with-examples-and-applications/
*/
LL *insertAtFirst(LL *head, LL *&tail, int val)    // O(1)
{
    LL *node = create(val);
    if(!head)
    {
        head = tail = node;
        return head;
    }

    node->next = head;
    head = node;    // created new node will be updated head of the list
    return head;
}
LL *insertAtLast(LL *head, LL *&tail, int val) // O(1)
{
    LL *node = create(val);
    if(!head)
    {
        head = tail = node;
        return head;
    }

    tail->next = node;
    tail = tail->next;
    return head;
}
LL *deleteFirstNode(LL *head, LL *&tail)   // O(1)
{
    if(!head) return NULL;
    if(!head->next) // list contains 1 node only
    {
        LL *tmp = head;
        head = tail = NULL;
        delete(tmp);
        return NULL;
    }
    // when list contains multiple nodes
    LL *tmp = head;
    head = head->next;
    delete(tmp);
    return head;
}
LL *deleteLastNode(LL *head, LL *&tail)    // O(N)
{
    if(!head) return NULL;
    if(!head->next) // list contains 1 node only
    {
        LL *tmp = head;
        head = tail = NULL;
        delete(tmp);
        return NULL;
    }

    LL *curr = head;
    while(curr->next->next) curr = curr->next;    // traversing to the 2nd node from last
    LL *tmp = curr->next; // keeping last node in tmp
    curr->next = NULL;
    tail = curr;    // changing tail node
    delete(tmp);
    return head;
}
LL *deleteFirstOccurrance(LL *head, LL *&tail, int val)    // O(N)
{
    if(!head) return NULL;
    if(head->val==val)
    {
        LL *tmp = head;
        head = head->next;
        if(!head) tail = NULL;  // when list contains 1 node only
        delete(tmp);
        return head;
    }
    LL *curr = head;
    while(curr->next && curr->next->val!=val)
    {
        curr = curr->next;
    }
    if(curr->next)
    {
        LL *tmp = curr->next;
        curr->next = curr->next->next;
        if(!curr->next) tail = curr;    // deleted node was tail node, so changing the tail node to it's previous node
        delete(tmp);
    }
    return head;
}
LL *deleteAllOccurrance(LL *head, LL *& tail, int val)    // O(N)
{
    if(!head) return NULL;
    int dummyValue = -1000; // set a value which is out of possible input range
    LL *dummyNode = create(dummyValue);
    dummyNode->next = head;
    LL *curr = dummyNode;
    while(curr && curr->next)
    {
        if(curr->next->val==val)
        {
            LL *prev = curr;
            curr = curr->next;
            while(curr && curr->val==val)
            {
                LL *tmp = curr;
                curr = curr->next;
                delete(tmp);
            }
            prev->next = curr;
            if(!curr) tail = prev;  // deletion occurred till last node
            else tail = curr;
        }
        else
        {
            curr = curr->next;
            tail = curr;
        }
    }

    head = dummyNode->next;
    if(!head) tail = head;
    delete(dummyNode);
    return head;
}
LL *reverseList(LL *head, LL *&tail)    // O(N)
{
    LL *curr = head, *nextNode = NULL, *prev = NULL;
    tail = head;
    while(curr)
    {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
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
void showAllOperation()
{
    cout<<"1. Insert value at first position"<<endl;
    cout<<"2. Insert value at last position"<<endl;
    cout<<"3. Delete first node"<<endl;
    cout<<"4. Delete last node"<<endl;
    cout<<"5. Delete first occurrence of a value"<<endl;
    cout<<"6. Delete all occurrences of a value"<<endl;
    cout<<"7. Reverse the list"<<endl;
    cout<<"8. Terminate"<<endl;
    cout<<"---------------------------------"<<endl;
}
int main()
{
    int operationNumber, value;
    LL *head = NULL, *tail = NULL;
    while(true)
    {
        showAllOperation();
        cin>>operationNumber;
        if(operationNumber==1)
        {
            cout<<"Give a value to insert: ";
            cin>>value;
            head = insertAtFirst(head, tail, value);
        }
        else if(operationNumber==2)
        {
            cout<<"Give a value to insert: ";
            cin>>value;
            head = insertAtLast(head, tail, value);
        }
        else if(operationNumber==3)
        {
            head = deleteFirstNode(head, tail);
        }
        else if(operationNumber==4)
        {
            head = deleteLastNode(head, tail);
        }
        else if(operationNumber==5)
        {
            cout<<"Give a value to delete: ";
            cin>>value;
            head = deleteFirstOccurrance(head, tail, value);
        }
        else if(operationNumber==6)
        {
            cout<<"Give a value to delete: ";
            cin>>value;
            head = deleteAllOccurrance(head, tail, value);
        }
        else if(operationNumber==7)
        {
            head = reverseList(head, tail);
        }
        else
        {
            break;
        }
        printList(head);
    }
    return 0;
}

