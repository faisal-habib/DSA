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
LL *insertAtFirst(LL *head, int val)    // O(1)
{
    LL *node = create(val);
    if(!head) return node;

    node->next = head;
    head = node;    // created new node will be updated head of the list
    return head;
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
LL *deleteFirstNode(LL *head)   // O(1)
{
    if(!head) return NULL;

    LL *tmp = head;
    head = head->next;
    delete(tmp);
    return head;
}
LL *deleteLastNode(LL *head)    // O(N)
{
    if(!head) return NULL;
    if(!head->next) // list has only 1 node
    {
        LL *tmp = head;
        head = NULL;
        delete(tmp);
        return head;
    }

    LL *curr = head;
    while(curr->next->next) curr = curr->next;    // traversing to the 2nd node from last
    LL *tmp = curr->next; // keeping last node in tmp
    curr->next = NULL;
    delete(tmp);
    return head;
}
LL *deleteFirstOccurrance(LL *head, int val)    // O(N)
{
    if(!head) return NULL;
    if(head->val==val)
    {
        LL *tmp = head;
        head = head->next;
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
        delete(tmp);
    }
    return head;
}
LL *deleteAllOccurrance(LL *head, int val)    // O(N)
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
        }
        else
        {
            curr = curr->next;
        }
    }

    head = dummyNode->next;
    delete(dummyNode);
    return head;
}
LL *reverseList(LL *head)    // O(N)
{
    LL *curr = head, *nextNode = NULL, *prev = NULL;

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
    LL *head = NULL;
    while(true)
    {
        showAllOperation();
        cin>>operationNumber;
        if(operationNumber==1)
        {
            cout<<"Give a value to insert: ";
            cin>>value;
            head = insertAtFirst(head, value);
        }
        else if(operationNumber==2)
        {
            cout<<"Give a value to insert: ";
            cin>>value;
            head = insertAtLast(head, value);
        }
        else if(operationNumber==3)
        {
            head = deleteFirstNode(head);
        }
        else if(operationNumber==4)
        {
            head = deleteLastNode(head);
        }
        else if(operationNumber==5)
        {
            cout<<"Give a value to delete: ";
            cin>>value;
            head = deleteFirstOccurrance(head, value);
        }
        else if(operationNumber==6)
        {
            cout<<"Give a value to delete: ";
            cin>>value;
            head = deleteAllOccurrance(head, value);
        }
        else if(operationNumber==7)
        {
            head = reverseList(head);
        }
        else
        {
            break;
        }
        printList(head);
    }
    return 0;
}
