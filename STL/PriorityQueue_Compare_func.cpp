#include<queue>

#include<iostream>
using namespace std;

void _printAllValuesOfPriorityQueue(priority_queue<int>pq) // decreasing order
{
    while(!pq.empty())
    {
        cout<<"Current top element in priority queue: "<<pq.top()<<endl;
        pq.pop();
    }
}

void _printAllValuesOfPriorityQueue(priority_queue< int, vector<int>, greater<int> >pq) // increasing order
{
    while(!pq.empty())
    {
        cout<<"Current top element in priority queue: "<<pq.top()<<endl;
        pq.pop();
    }
}

void _defaultPriorityQueueOperations()
{
    priority_queue<int>pq;  // it provides max heap
    pq.push(10);
    pq.push(20);
    pq.push(-10);

    _printAllValuesOfPriorityQueue(pq);
}

void _minHeapWIthPriorityQueue()
{
    priority_queue< int, vector<int>, greater<int> >pq;  // it provides min heap
    pq.push(10);
    pq.push(20);
    pq.push(-10);

    _printAllValuesOfPriorityQueue(pq);
}

/** --------------------------- custom compare function ---------------------------- */
struct _cmp
{
    bool operator() (const int &a, const int &b)
    {
        return a > b;   // it provides min heap
    }
};

void _printAllValuesOfPriorityQueue(priority_queue< int , vector<int>, _cmp >pq) // increasing order
{
    while(!pq.empty())
    {
        cout<<"Current top element in priority queue: "<<pq.top()<<endl;
        pq.pop();
    }
}

void _minHeapWIthCustomCompareFunction()
{
    priority_queue< int , vector<int>, _cmp >pq;
    pq.push(10);
    pq.push(20);
    pq.push(-10);

    _printAllValuesOfPriorityQueue(pq);
}
int main()
{
    //_defaultPriorityQueueOperations();

    //_minHeapWIthPriorityQueue();

    _minHeapWIthCustomCompareFunction();    // output -> -10, 10, 20

}

