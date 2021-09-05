#include<list>
#include<utility>
#include<iostream>
using namespace std;

void _printList(list<pair<int, int>> &pairList)
{
    cout<<"---- Printing values of list ----"<<endl;
    int ind = 1;
    for(auto pii : pairList)
    {
        cout<< ind++ <<": "<< pii.first <<" "<< pii.second<<endl;
    }
}

void _takeInput(list<pair<int, int>> &pairList)
{
    pairList.push_back({1, 2});
    pairList.push_back({1, 3});
    pairList.push_back({2, 2});
    pairList.push_back({3, 4});
    pairList.push_back({4, 2});
    pairList.push_back({4, 5});
    pairList.push_back({3, 5});
}

int numberToBeDeleted;
/*
Remove all occurrence of a value if it's found in the list as a second value of every pair.
*/
bool _remove(const pair<int, int> &pii)
{
    return (pii.second == numberToBeDeleted);
}

void _deleteAllOccurance(list<pair<int, int>> &pairList)
{
    numberToBeDeleted = 2;
    pairList.remove_if(_remove);
}

/*
Change all occurrence of matched value
*/

void _changeValue(list<pair<int, int>> &pairList, int modifyValue, int modifyWith)
{

    for(auto pii = pairList.begin(); pii != pairList.end(); pii++)
    {
        if( pii->second == modifyValue)
        {
            pii->second = modifyWith;
        }
    }
}

/*
Change first matched value
*/

void _changeValueOfFirstOccurance(list<pair<int, int>> &pairList, int modifyValue, int modifyWith)
{

    for(auto pii = pairList.begin(); pii != pairList.end(); pii++)
    {
        if( pii->second == modifyValue)
        {
            pii->second = modifyWith;
            break;
        }
    }
}

int main()
{
    list<pair<int, int>>pairList;

    _takeInput(pairList);

    _printList(pairList);

    _deleteAllOccurance(pairList);

    _printList(pairList);

    //_changeValue(pairList, 5, 100);

    _changeValueOfFirstOccurance(pairList, 5, 100);

    _printList(pairList);
}
