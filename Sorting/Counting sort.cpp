/**
Time : O(n+k) where n is the number of elements in input array and k is the range of input.
Space: O(n+k)

Stable
(If duplicate values are given as input, output will maintain given input order)
Not Adaptive
(A sorting algorithm falls into the adaptive sort family if it takes advantage of existing order in its input)

Resources:
https://www.interviewcake.com/concept/java/counting-sort
https://www.geeksforgeeks.org/counting-sort/
*/

#include<bits/stdc++.h>
using namespace std;

#define MX 50

// approach 2
void countingSort(int ar[], int sz)    // it works for both positive & negative elements
{
    int mxVal = ar[0], mnVal = ar[0], ind = 0, range;
    for(int i=0; i<sz; i++)
    {
        mxVal = mxVal>ar[i] ? mxVal:ar[i];
        mnVal = mnVal<ar[i] ? mnVal:ar[i];
    }

    range = mxVal - mnVal + 1;
    int countAr[range];

    for(int i=mnVal; i<=mxVal; i++) countAr[i-mnVal] = 0;

    for(int i=0; i<sz; i++)
    {
        countAr[ar[i]-mnVal]++;
    }

    for(int i=mnVal; i<=mxVal; i++)
    {
        while(countAr[i-mnVal])
        {
            ar[ind++] = i;
            countAr[i-mnVal]--;
        }
    }
}

/*
// approach 1
void countingSort(int ar[], int sz)    // it works only for positive numbers
{
    int mxVal = 0, ind = 0;
    for(int i=0; i<sz; i++) mxVal = mxVal>ar[i] ? mxVal:ar[i];

    int countAr[mxVal+1];
    for(int i=0; i<=mxVal; i++) countAr[i] = 0;

    for(int i=0; i<sz; i++) countAr[ar[i]]++;

    for(int i=0; i<=mxVal; i++)
    {
        while(countAr[i])
        {
            ar[ind++] = i;
            countAr[i]--;
        }
    }
}
*/
int main()
{
    int ar[MX],sz;
    cout<<"Give size of the array: ";
    cin>>sz;
    cout<<"Give elements of array: ";
    for(int i=0;i<sz;i++) cin>>ar[i];

    countingSort(ar,sz);
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
