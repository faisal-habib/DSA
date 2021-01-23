/**
Time =>
Worst and Average: O(n*n)
(Worst case occurs when array is reverse sorted)

Best: O(n)
(Best case occurs when array is already sorted)

Space => O(1) / In-place

Stable (maintains input order. If duplicate values are given as input, output will maintain given input order)
Adaptive (A sorting algorithm falls into the adaptive sort family if it takes advantage of existing order in its input)

* to sort linked list, insertion sort is better choice (insertion takes constant time,don't need any elements shifting, only searching the value takes time)
* intermediate results won't give any useful result
* Insertion sort is used when number of elements is small.
  It can also be useful when input array is almost sorted, only few elements are misplaced in complete big array

Resources:
https://www.geeksforgeeks.org/insertion-sort/
*/

#include<bits/stdc++.h>
using namespace std;

#define MX 100

void insertionSort(int ar[],int sz) // increasing order
{
    for(int i=1; i<sz; i++)
    {
        int j = i-1, currVal = ar[i];
        while( j>=0 && ar[j]>currVal )
        {
            ar[j+1] = ar[j];
            j--;
        }
        ar[j+1] = currVal;
    }
}

int binarySearch(int ar[], int currVal, int low , int high)
{
    if( high <= low )
    {
        return ( ar[low]<currVal ? (low+1) : low );
    }

    int mid = (high+low)/2;
    if(currVal==ar[mid]) return (mid+1);

    if(ar[mid]<currVal) return binarySearch(ar, currVal, mid+1, high);

    return binarySearch(ar, currVal, low, mid-1);
}
//worst-case time complexity is O(N*N), because of the series of swaps required for each insertion.
void insertionSortWithBinarySearch(int ar[], int sz)
{
    for(int i=1; i<sz; i++)
    {
        int j = i-1, currVal = ar[i];
        //find index where current val should be inserted using binary search, it'll reduce comparison time to (log N)
        int ind = binarySearch(ar, currVal, 0 , j);

        while(j>=ind)
        {
            ar[j+1] = ar[j];
            j--;
        }
        ar[j+1] = currVal;
    }
}

int main()
{
    int ar[MX], sz;
    cout<<"Give size of the array: ";
    cin>>sz;
    cout<<"Give elements of the array: ";
    for(int i=0;i<sz;i++) cin>>ar[i];

    insertionSort(ar, sz);
    //insertionSortWithBinarySearch(ar, sz);
    cout<"After sorting: ";
    for(int i=0;i<sz;i++) cout<<ar[i]<<" ";
}

/*
5
7 1 8 3 8

5
5 4 3 2 1
*/
