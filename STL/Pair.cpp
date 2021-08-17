#include<utility>

#include<vector>
#include<algorithm> // for using sort
#include<iostream>
using namespace std;

void _printVecotrOfPair(vector< pair<int, int> > &pairVector)
{
    for(int i=0 ; i < pairVector.size(); i++)
    {
        cout<<i<< " : " << pairVector[i].first<< " " << pairVector[i].second<<endl;
    }
}

void _sortVectorOfPair(vector< pair<int, int> > &pairVector)
{
    sort(pairVector.begin(), pairVector.end()); // sorting in increasing order
    cout<<" After sorting in increasing order"<<endl;
    _printVecotrOfPair(pairVector);


    sort( pairVector.begin(), pairVector.end(), greater< pair<int, int> >() );  // sorting in decreasing order
    cout<<" After sorting in decreasing order"<<endl;
    _printVecotrOfPair(pairVector);
}

void _insertValuesInVecotrOfPair(vector< pair<int, int> > &pairVector)
{
    pairVector.push_back(make_pair(10, 29));
    pairVector.push_back({18, 20});
    pairVector.push_back({10, 20});
    pairVector.push_back({19, 10});
}

bool _cmp(pair<int, int> &p1, pair<int, int> &p2)
{
    return (p1.second < p2.second || (p1.second == p2.second && p1.first < p2.first));
}

void _sortVectorOfPairBasedOnSecondElement(vector< pair<int, int> > &pairVector)
{
    cout<<" After sorting in increasing order based on 2nd element of the pair"<<endl;
    sort(pairVector.begin(), pairVector.end(), _cmp); // sorting in increasing order
    _printVecotrOfPair(pairVector);
}

int main()
{
    vector< pair<int, int> > pairVector;    // vector of pairs

    _insertValuesInVecotrOfPair(pairVector);

    cout<<" Given vector of pair"<<endl;
    _printVecotrOfPair(pairVector);

    _sortVectorOfPair(pairVector);

    _sortVectorOfPairBasedOnSecondElement(pairVector);

    return 0;
}

/*
Output->

 Given vector of pair
0 : 10 29
1 : 18 20
2 : 10 20
3 : 19 10
 After sorting in increasing order
0 : 10 20
1 : 10 29
2 : 18 20
3 : 19 10
 After sorting in decreasing order
0 : 19 10
1 : 18 20
2 : 10 29
3 : 10 20
 After sorting in increasing order based on 2nd element of the pair
0 : 19 10
1 : 10 20
2 : 18 20
3 : 10 29
*/
