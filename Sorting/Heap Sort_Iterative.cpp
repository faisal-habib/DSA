#include<bits/stdc++.h>
using namespace std;

#define MX 100

int heap[MX], heapSz;

bool _cmp(int parVal, int childVal)
{
    if(parVal<childVal) return true;
    return false;
}

void _topDownHeapify(int heap[], int heapSz, int parInd)
{
    while((parInd<<1)<=heapSz)
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

void _buildMinHeapify(int heap[], int heapSz)
{
    for(int i=heapSz>>1; i>=1; i--)
    {
        _topDownHeapify(heap, heapSz, i);
    }
}

void _heapSort(int heap[], int heapSz)
{
    _buildMinHeapify(heap, heapSz);
    while(heapSz>1)
    {
        swap(heap[1], heap[heapSz]);
        heapSz--;
        _topDownHeapify(heap, heapSz, 1);
    }
}

void printIncreasingOrder(int heap[], int sz)
{
    cout<<"Increasing order: ";
    for(int i=sz;i>=1;i--) cout<<heap[i]<<" ";
    cout<<endl;
}
void printDecreasingOrder(int heap[], int sz)
{
    cout<<"Decreasing order: ";
    for(int i=1;i<=sz;i++) cout<<heap[i]<<" ";
    cout<<endl;
}

int main()
{
    cout<<"Give size of the array: ";
    cin>>heapSz;
    cout<<"Give elements of array: ";
    for(int i=1;i<=heapSz;i++) cin>>heap[i];

    _heapSort(heap, heapSz);

    printIncreasingOrder(heap, heapSz);
    printDecreasingOrder(heap, heapSz);
}

/*
8
0 90 85 80 70 60 55 50
5
1 2 -5 4 3
10
3 6 0 5 1 3 7 3 4 1
*/
