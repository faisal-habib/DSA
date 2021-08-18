#include<set>

#include<iostream>
#include<iterator>
using namespace std;

void _insertValuesInSet(set<int> &demoSet)
{
    demoSet.insert(10);
    demoSet.insert(5);
    demoSet.insert(12);
    demoSet.insert(3);
    demoSet.insert(11);
    demoSet.insert(-90);
    demoSet.insert(234);
    demoSet.insert(48);
}

void _insertValuesInSet(set< int, greater<int> > &demoReverseSet)
{
    demoReverseSet.insert(10);
    demoReverseSet.insert(5);
    demoReverseSet.insert(12);
    demoReverseSet.insert(3);
    demoReverseSet.insert(11);
    demoReverseSet.insert(-90);
    demoReverseSet.insert(234);
    demoReverseSet.insert(48);
}
void _printAllElementsOfSet(set< int, greater<int> > &demoReverseSet)
{
    // traverse set using auto ->  auto specifier is present since c++11 version

    for(auto values : demoReverseSet)
    {
        cout<< values <<" ";
    }

    // can also do like following

    /*for(auto it = demoReverseSet.begin(); it != demoReverseSet.end(); it++)
    {
        cout<< *it <<" ";
    }*/

    cout<<endl<<endl;
}


void _printAllElementsOfSet(set<int> &demoSet)
{
    set<int> :: iterator it;
    for(it = demoSet.begin(); it != demoSet.end(); it++)
    {
        cout<< *it <<" ";
    }
    cout<<endl<<endl;
}

void _printAllElementsOfSetInReverseOrder(set<int> &demoSet)
{
    set<int> :: reverse_iterator it;
    for(it = demoSet.rbegin(); it != demoSet.rend(); it++)
    {
        cout<< *it <<" ";
    }
    cout<<endl<<endl;
}

void _searchValueInSet(set<int> &demoSet)
{
    set<int> :: iterator it = demoSet.find(-100);
    if(it != demoSet.end()) cout<<"value is present in the set"<<endl;
    else cout<<"value is not present in the set"<<endl;
}

void _eraseValueFromSet(set<int> &demoSet)
{
    // _erase particular value from Set
    //demoSet.erase(10);

    // erase all elements upto given value
    demoSet.erase(demoSet.begin(), demoSet.find(10));   // (starting position, given value's position)

    cout<<" Values of set after erasing element" <<endl;
    _printAllElementsOfSet(demoSet);
}
int main()
{
    set<int> demoSet;

    _insertValuesInSet(demoSet);

    cout<<" Given values of set"<<endl;
    _printAllElementsOfSet(demoSet);

    /*
    cout<<" Printing values of set in reverse order"<<endl;
    _printAllElementsOfSetInReverseOrder(demoSet);
    */

    //_searchValueInSet(demoSet);

    //_eraseValueFromSet(demoSet);

    /*
    lower_bound( value ):- Returns an iterator to the element x if it is found else,
    return the iterator to the next element of it.
    */
    set<int> :: iterator it = demoSet.lower_bound(9);
    cout<< "Lower bound of 9: "<<*it <<endl;
    it = demoSet.lower_bound(11);
    cout<< "Lower bound of 11: "<<*it <<endl;

    /*
    upper_bound( value ):- Returns an iterator to the first element after the element x .
    */
    it = demoSet.upper_bound(9);
    cout<< "Upper bound of 9: "<<*it <<endl;
    it = demoSet.upper_bound(11);
    cout<< "Upper bound of 11: "<<*it <<endl<<endl;



    /// Reverse set - keeps values in decreasing order
    set< int, greater<int> > demoReverseSet(demoSet.begin(), demoSet.end());    // copying elements from one set to another

    //_insertValuesInSet(demoReverseSet);

    cout<<" Given values of reverse set"<<endl;
    _printAllElementsOfSet(demoReverseSet);
}

/*
Output ->
 Given values of set
-90 3 5 10 11 12 48 234

Lower bound of 9: 10
Lower bound of 11: 11
Upper bound of 9: 10
Upper bound of 11: 12

 Given values of reverse set
234 48 12 11 10 5 3 -90
*/
