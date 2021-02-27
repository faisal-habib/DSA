#include<bits/stdc++.h>
using namespace std;

#define MX 100

int heap[MX], heapSz;

bool _cmp(int parVal, int childVal)
{
    if(parVal<childVal) return true;
    return false;
}

void _insertIntoMinHeap(int heap[], int &heapSz, int value)
{
    heap[++heapSz] = value;
    int currInd = heapSz, parInd;
    while(currInd>1)
    {
        parInd = currInd>>1;
        if(!_cmp(heap[parInd], heap[currInd]))
        {
            swap(heap[currInd], heap[parInd]);
            currInd = parInd;
        }
        else break;
    }
}

void _deleteTopValueFromHeap(int heap[], int &heapSz)
{
    int topValue = heap[1];
    heap[1] = heap[heapSz];
    heapSz--;
    int parInd = 1;
    while( (parInd<<1)<=heapSz )
    {
        int lChild = parInd<<1, rChild = lChild+1, smallerValInd = parInd;

        if(!_cmp(heap[smallerValInd], heap[lChild])) smallerValInd = lChild;
        if(rChild<=heapSz && !_cmp(heap[smallerValInd], heap[rChild])) smallerValInd = rChild;

        if(smallerValInd!=parInd)
        {
            swap(heap[parInd], heap[smallerValInd]);
            parInd = smallerValInd;
        }
        else break;
    }
}

void _deleteValueFromHeap(int heap[], int &heapSz, int value)
{
    int valInd = -1;
    for(int i=1; i<=heapSz; i++)
    {
        if(heap[i]==value)
        {
            valInd = i;
            break;
        }
    }
    if(valInd==-1) return ;

    heap[valInd] = heap[heapSz];
    heapSz--;
    int parInd = valInd;
    while( (parInd<<1)<=heapSz )
    {
        int lChild = parInd<<1, rChild = lChild+1, smallerValInd = parInd;

        if(!_cmp(heap[smallerValInd], heap[lChild])) smallerValInd = lChild;
        if(rChild<=heapSz && !_cmp(heap[smallerValInd], heap[rChild])) smallerValInd = rChild;

        if(smallerValInd!=parInd)
        {
            swap(heap[parInd], heap[smallerValInd]);
            parInd = smallerValInd;
        }
        else break;
    }
}

void _showOperation()
{
    cout<<"------------------------------"<<endl;
    cout<<"1. Insert new value into heap"<<endl;
    cout<<"2. Delete top value from heap"<<endl;
    cout<<"3. Delete given value from heap"<<endl;
    cout<<"4. Print top value of heap"<<endl;
    cout<<"5. Print all values of heap"<<endl;
    cout<<"6. Terminate"<<endl;
    cout<<"------------------------------"<<endl;
}

void _init()
{
    heapSz = 0;
}

void _insert()
{
    int val;
    cout<<"Give a value to insert: ";
    cin>>val;
    _insertIntoMinHeap(heap, heapSz, val);
}
void _deleteTop()
{
    _deleteTopValueFromHeap(heap, heapSz);
}
void _deleteValue()
{
    int val;
    cout<<"Give a value to delete: ";
    cin>>val;
    _deleteValueFromHeap(heap, heapSz, val);
}
void _printTopValue()
{
    if(heapSz)
    {
        cout<<"Top value: "<<heap[1]<<endl;
    }
    else
    {
        cout<<"Heap is empty"<<endl;
    }
}
void _printAll()
{
    for(int i=1; i<=heapSz; i++) cout<<heap[i]<<" ";
    if(!heapSz) cout<<"Empty heap!";
    cout<<endl;
}
int main()
{
    _init();
    int operation;

    while(true)
    {
        _showOperation();
        cin>>operation;

        if(operation==1) _insert();
        else if(operation==2) _deleteTop();
        else if(operation==3) _deleteValue();
        else if(operation==4) _printTopValue();
        else if(operation==5) _printAll();
        else if(operation==6) break;
    }
}
