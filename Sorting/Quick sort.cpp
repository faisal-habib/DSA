/**
Selection Exchange sort, Partition Exchange sort, divide and conquer approach

Time =>
Worst: O(n*n)
(Worst case occurs when array is already sorted in increasing or decreasing order)

Best and Average: O(n log n)
(Best case is when partition are as evenly balanced as possible)

Space =>  In-place sorting
Worst: O(n)
Best & Avg: O(log n)
(both of above memory are stack memory)

Not Stable
(stable means, it maintains input order. If duplicate values are given as input, output will maintain given input order)
Adaptive
(A sorting algorithm falls into the adaptive sort family if it takes advantage of existing order in its input)

* The worst case runtime of quick sort is O(n*n) can be avoided by using randomized

Resources:
https://www.geeksforgeeks.org/quick-sort/
https://www.interviewbit.com/tutorial/quicksort-algorithm/
*/

#include<bits/stdc++.h>
using namespace std;

#define MX 100

/* This function takes last element as pivot, places the pivot element at its correct position in sorted array
and places all smaller (smaller than pivot) to left of pivot and all greater elements to right of pivot */
int _partition(int ar[], int low, int high)
{
    int pivot = ar[high];
    int leftPointer = low, rightPointer = high;

    for(int i=low; i<high ;i++)
    {
        if(ar[i] < pivot)
        {
            swap(ar[i], ar[leftPointer]);
            leftPointer++;
        }
    }

    swap(ar[leftPointer], ar[high]);

    return leftPointer;
}

// Random selection of pivot
int randomPivotPartition(int ar[], int low, int high)
{
    int n = rand();
    int ind = low+ n%(high-low+1);
    // Swapping pivot value from high, so pivot value will be taken as a pivot while partitioning
    swap(ar[high], ar[ind]);

    return _partition(ar, low, high);
}

// low --> Starting index,  high --> Ending index
void quickSort(int ar[], int low, int high)
{
    if(low < high)
    {
        int partitioningIndex = _partition(ar, low, high);
        //int partitioningIndex = randomPivotPartition(ar, low, high);

        quickSort(ar, low, partitioningIndex-1);
        quickSort(ar, partitioningIndex+1, high);
    }
}

int main()
{
    int ar[MX], sz;
    cout<<"Give size of the array: ";
    cin>>sz;
    cout<<"Give elements of the array: ";
    for(int i=0;i<sz;i++) cin>>ar[i];

    quickSort(ar, 0, sz-1);
    cout<"After sorting: ";
    for(int i=0;i<sz;i++) cout<<ar[i]<<" ";
}

/*
5
7 1 8 3 8

5
5 4 3 2 1
*/
