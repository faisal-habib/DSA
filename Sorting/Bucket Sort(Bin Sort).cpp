/**
Bucket sort/ Bin sort
Concept is similar to counting sort. Difference is , rather than just increasing count of an input, we're keeping the input itself.
So if input is an object instead of just a number, then we'll keep the whole object, and can take advantage of that.

Time :
Best & Average: O(n)
Worst: O(n*n)
Space: O(n+k)
where n is the number of elements in input array and k is the range of input.

Stable
(If duplicate values are given as input, output will maintain given input order)
Not Adaptive
(A sorting algorithm falls into the adaptive sort family if it takes advantage of existing order in its input)

Resources:
https://stackoverflow.com/questions/54808131/how-is-the-time-complexity-of-bucket-sort-onk-if-it-uses-insertion-sort-to-so
https://www.educative.io/edpresso/what-is-bucket-sort
*/

#include<bits/stdc++.h>
using namespace std;

#define MX 50

typedef struct Node
{
    int val;
    struct Node *nxt;
}LL;

LL *create(int val)
{
    LL *n = new LL;
    n->val = val;
    n->nxt = NULL;
    return n;
}

LL *insertAtLast(LL *head, int val)
{
    Node *n = create(val);
    if(!head) return n;

    LL *curr = head;
    while(curr->nxt) curr = curr->nxt;  // here we're traversing the list to insert at the last position. We can optimize it by keeping a tail Node, in that case it'll take much space
    curr->nxt = n;

    return head;
}

LL *deleteFirst(LL *head)
{
    if(!head) return NULL;

    LL *curr = head;
    head = head->nxt;
    delete(curr);

    return head;
}

/*
// approach 1
void bucketSort(int ar[], int sz)   // only works for positive numbers
{
    int mxVal = ar[0], mnVal = ar[0], ind = 0;
    for(int i=0; i<sz; i++)
    {
        mxVal = mxVal>ar[i] ? mxVal:ar[i];
        mnVal = mnVal<ar[i] ? mnVal:ar[i];
    }

    LL *listHead[mxVal+1];  // we can refer this list as bucket or bin
    for(int i=mnVal; i<=mxVal; i++)
    {
        listHead[i] = NULL;
    }

    for(int i=0; i<sz; i++)
    {
        listHead[ar[i]] = insertAtLast(listHead[ar[i]], ar[i]);
    }

    for(int i=mnVal; i<=mxVal; i++)
    {
        while(listHead[i])
        {
            ar[ind++] = i;
            listHead[i] = deleteFirst(listHead[i]);
        }
    }
}
*/

// approach 2
void bucketSort(int ar[], int sz)   // works for both positive & negative numbers
{
    int mxVal = ar[0], mnVal = ar[0], ind = 0;
    for(int i=0; i<sz; i++)
    {
        mxVal = mxVal>ar[i] ? mxVal:ar[i];
        mnVal = mnVal<ar[i] ? mnVal:ar[i];
    }
    int range = mxVal - mnVal + 1;

    LL *listHead[range];  // we can refer this list as bucket or bin
    for(int i=mnVal; i<=mxVal; i++)
    {
        listHead[i-mnVal] = NULL;
    }

    for(int i=0; i<sz; i++)
    {
        listHead[ar[i]-mnVal] = insertAtLast(listHead[ar[i]-mnVal], ar[i]);
    }

    for(int i=mnVal; i<=mxVal; i++)
    {
        while(listHead[i-mnVal])
        {
            ar[ind++] = i;
            listHead[i-mnVal] = deleteFirst(listHead[i-mnVal]);
        }
    }
}
int main()
{
    int ar[MX],sz;
    cout<<"Give size of the array: ";
    cin>>sz;
    cout<<"Give elements of array: ";
    for(int i=0;i<sz;i++) cin>>ar[i];

    bucketSort(ar,sz);
    cout<<"after sorting: ";
    for(int i=0;i<sz;i++) cout<<ar[i]<<" ";
    cout<<endl;
}
/*
5
1 2 -5 4 3

10
3 6 0 5 1 3 7 3 4 1
*/
