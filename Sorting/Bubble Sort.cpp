/**
An optimized version of Bubble Sort
Time =>
Worst and Average: O(n*n)
(Worst case occurs when array is reverse sorted)

Best: O(n)
(Best case occurs when array is already sorted)

Space => O(1) / In-place

Stable (maintains input order. If duplicate values are given as input, output will maintain given input order)
Adaptive (A sorting algorithm falls into the adaptive sort family if it takes advantage of existing order in its input)

Resources:
https://www.geeksforgeeks.org/bubble-sort/
*/

#include<bits/stdc++.h>
using namespace std;

#define MX 100

void bubbleSort(int ar[], int sz)   // increasing order
{
    bool swapped;
    for(int i=0; i<sz-1; i++)   /// for N elements we've to perform N-1 passes
    {
        swapped = false;
        for(int j=0; j<sz-1-i; j++) /// in every pass, 1 comparison get reduced. that's why (sz-1)-i
        {
            if(ar[j] > ar[j+1])
            {
                swap(ar[j], ar[j+1]);
                swapped = true;
            }
        }

        if(!swapped) break; /// if there's no swapping in a pass, that means list is already sorted.
                            /// if given array is already sorted, this condition will make time complexity O(N)
    }
}

int main()
{
    int ar[MX], sz;
    cout<<"Give size of the array: ";
    cin>>sz;
    cout<<"Give elements of the array: ";
    for(int i=0;i<sz;i++) cin>>ar[i];

    bubbleSort(ar, sz);
    cout<"After sorting: ";
    for(int i=0;i<sz;i++) cout<<ar[i]<<" ";
}
