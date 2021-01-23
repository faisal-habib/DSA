/**
The top-down merge sort approach is the methodology which uses recursion mechanism. It starts at the Top and proceeds downwards.

(current code doesn't work with negative values as input)
Idea to do it in-place:
First we have to find a value greater than all the elements of the array. Now we can store the original value
as modulus and the second value as division. Suppose we want to store arr[i] and arr[j] both at index i(means in arr[i]).
First we have to find a ‘maxval’ greater than both arr[i] and arr[j].
Now we can store as arr[i] = arr[i] + arr[j]*maxval.
So, arr[i] = arr[i]%mxval and arr[j] = arr[i]/mxval;

Time:
The list of size N is divided into a max of (log N) parts
and the merging of all sublists into a single list takes O(N) time.
Worst case: O(N log N)

Space:
O(1)

Stable
(If duplicate values are given as input, output will maintain given input order)
Not Adaptive
(A sorting algorithm falls into the adaptive sort family if it takes advantage of existing order in its input)

Resources:
https://www.interviewbit.com/tutorial/merge-sort-algorithm/
https://www.geeksforgeeks.org/merge-sort-with-o1-extra-space-merge-and-on-lg-n-time/?ref=rp
https://www.happycoders.eu/algorithms/merge-sort/#Natural_Mergesort_-_Example
*/

#include<bits/stdc++.h>
using namespace std;

#define MX 50
int mxVal;

void _merge(int ar[], int low, int mid, int high)
{
    int leftInd=low, rightInd=mid+1, tempInd = low;

    while(leftInd<=mid && rightInd<=high)
    {
        if(ar[leftInd]%mxVal <= ar[rightInd]%mxVal) // ar[leftInd]%mxVal means original value of ar[leftInd]
        {
            ar[tempInd] = ar[tempInd] + (ar[leftInd]%mxVal)*mxVal;
            tempInd++;
            leftInd++;
        }
        else
        {
            ar[tempInd] = ar[tempInd] + (ar[rightInd]%mxVal)*mxVal;
            tempInd++;
            rightInd++;
        }
    }

    while(leftInd <= mid)
    {
        ar[tempInd] = ar[tempInd] + (ar[leftInd]%mxVal)*mxVal;
        tempInd++;
        leftInd++;
    }

    while(rightInd<=high)
    {
        ar[tempInd] = ar[tempInd] + (ar[rightInd]%mxVal)*mxVal;
        tempInd++;
        rightInd++;
    }

    for(int i=low; i<=high; i++) ar[i] = ar[i]/mxVal;   // ar[i]/mxVal means the secondary value we kept
}

void _mergeSort(int ar[], int low, int high)
{
    if(low < high)    // it means there are more than 1 elements
    {
        int mid = low+(high-low)/2;

        _mergeSort(ar, low, mid);
        _mergeSort(ar, mid+1, high);

        _merge(ar, low, mid, high);
    }
}

int main()
{
    int ar[MX],sz;
    mxVal = INT_MIN;
    cout<<"Give size of the array: ";
    cin>>sz;
    cout<<"Give elements of array: ";
    for(int i=0;i<sz;i++)
    {
        cin>>ar[i];
        mxVal = ar[i]>mxVal ? ar[i]:mxVal;
    }
    mxVal++;

    _mergeSort(ar, 0, sz-1);
    cout<<"after sorting: ";
    for(int i=0;i<sz;i++) cout<<ar[i]<<" ";
    cout<<endl;
}

/*
5
1 2 5 4 3
*/
