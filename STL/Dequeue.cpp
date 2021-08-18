#include<queue>

#include<iostream>
using namespace std;

void _printDeque(deque<int> &dq)
{
    for(auto val : dq)
    {
        cout<< val <<" ";
    }
    cout<<endl<<endl;
}

int main()
{
    deque<int>dq;

    dq.push_back(1);
    dq.push_back(2);
    dq.push_back(3);
    dq.push_front(4);
    dq.push_front(5);
    dq.push_front(6);
    dq.push_front(7);

    _printDeque(dq);

    cout<<"Size of dq: "<<dq.size()<<endl;

    cout<<"Erasing second element from deque"<<endl;
    dq.erase(dq.begin()+1);
    _printDeque(dq);

    cout<<"Erasing second and third element from deque"<<endl;
    dq.erase(dq.begin()+1, dq.begin()+3);

    _printDeque(dq);

    return 0;
}


/*
Output ->

7 6 5 4 1 2 3

Size of dq: 7
Erasing second element from deque
7 5 4 1 2 3

Erasing second and third element from deque
7 1 2 3

*/
