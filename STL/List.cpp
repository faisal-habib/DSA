#include<list>

#include<algorithm> // to use find function
#include<iostream>
using namespace std;

void _printList(list<int> &numList)
{
    for(auto num : numList)
    {
        cout<<num<<" ";
    }
    cout<<endl<<endl;
}

void _findValueInList(list<int> &numList)
{
    cout<<"400 exists in the list? ";
    auto it = find(numList.begin(), numList.end(), 400);
    if(it != numList.end()) cout<<"yes"<<endl<<endl;
    else cout<<"no"<<endl<<endl;
}

void _eraseValueFromList(list<int> &numList)
{
    int value = 2;
    auto it = numList.begin();
    while(it != numList.end() && *it != value) it++;

    if(it != numList.end())
    {
        numList.erase(it);
        cout<<"value "<<value<<" exists in the list. Deletion done."<<endl<<endl;
    }
    else cout<<"value "<<value<<" does not exist in the list"<<endl<<endl;
}

void _countFrequency(list<int> &numList)
{
    int value = 3;
    int freq = count(numList.begin(), numList.end(), value);
    cout<<"Frequency of value "<<value<<" in the list: "<<freq<<endl<<endl;
}

int main()
{
    list<int>numList{1, 2, 3};

    cout<<" Initial list"<<endl;
    _printList(numList);

    cout<<" Inserting 40 at the beginning of the list"<<endl;
    /*
    insert(iterator, element) : inserts element in the list before the position pointed by the iterator.
    */
    numList.insert(numList.begin(), 4);
    _printList(numList);

    cout<<" Push 30 at the beginning of the list"<<endl;
    numList.push_front(30);
    _printList(numList);

    cout<<" Push 50 at the end of the list"<<endl;
    numList.push_back(50);
    _printList(numList);

    cout<<" Pop the first value from the list"<<endl;
    numList.pop_front();
    _printList(numList);

    cout<<" Pop the last value from the list"<<endl;
    numList.pop_back();
    _printList(numList);

    _findValueInList(numList);

    _eraseValueFromList(numList);

    _printList(numList);

    _countFrequency(numList);
}
