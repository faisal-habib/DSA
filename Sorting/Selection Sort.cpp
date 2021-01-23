/**
Time =>
Worst , Average and Best: O(n*n)
(Worst case occurs when array is reverse sorted)
(Best case occurs when array is already sorted. In best case, there's no swap required)

Space => O(1) / In-place

Not Stable
(stable means, it maintains input order. If duplicate values are given as input, output will maintain given input order)
Not Adaptive
(A sorting algorithm falls into the adaptive sort family if it takes advantage of existing order in its input)

* it is good for less number of swap (max O(N) swap)
* intermediate results are useful (like bubble sort), in K passes, we'll get K smaller numbers

Resources:
https://www.geeksforgeeks.org/selection-sort/
*/


#include<bits/stdc++.h>
using namespace std;

#define MX 100

void selectionSort(int ar[], int sz)
{
    for(int i=0; i<sz-1; i++)
    {
        int minIndex = i;   // index of min value
        for(int j=i+1; j<sz; j++)
        {
            if(ar[j]<ar[minIndex]) minIndex = j;
        }
        swap(ar[i], ar[minIndex]);
    }
}

int main()
{
    int ar[MX], sz;
    cout<<"Give size of the array: ";
    cin>>sz;
    cout<<"Give elements of the array: ";
    for(int i=0;i<sz;i++) cin>>ar[i];

    selectionSort(ar, sz);
    cout<"After sorting: ";
    for(int i=0;i<sz;i++) cout<<ar[i]<<" ";
}

/*
5
7 1 8 3 8

5
5 4 3 2 1
*/
