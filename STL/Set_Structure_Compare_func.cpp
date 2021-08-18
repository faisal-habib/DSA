#include<set>

#include<iostream>
#include<iterator>
using namespace std;

typedef struct
{
    int age;
    int salary;
}PersonInfo;

struct _cmp
{
    bool operator() (const PersonInfo &p1, const PersonInfo &p2)
    {
        return ( p1.salary > p2.salary || (p1.salary == p2.salary && p1.age < p2.age) );
    }
};

void _printAllElementsOfSet(set<PersonInfo, _cmp> &personSet)
{
    cout<<" Printing all info in set"<<endl;
    // traverse set using auto ->  auto specifier is present since c++11 version

    for(auto values : personSet)
    {
        cout<< "Age: "<< values.age <<" Salary: "<< values.salary<<endl;
    }

    // can also do like following

    /*for(auto it = personSet.begin(); it != personSet.end(); it++)
    {
        cout<< "Age: "<< (*it).age <<" Salary: "<< (*it).salary<<endl;
    }*/

    cout<<endl<<endl;
}

void _printAllInfo(PersonInfo ar[], int &sz)
{
    for(int i=0; i < sz; i++) cout<< "Age: "<< ar[i].age <<" Salary: "<< ar[i].salary<<endl;
    cout<<endl<<endl;
}

void _eraseAllWithParticularValueFromSet(set<PersonInfo, _cmp> &personSet)
{
    int age = 27;
    auto it = personSet.begin();
    while(it != personSet.end())
    {
        if(it->age == age)
        {
            it = personSet.erase(it);
        }
        else it++;
    }
}

int main()
{
    PersonInfo personInfoAr[5];
    int arSz = 5;
    personInfoAr[0].age = 25, personInfoAr[0].salary = 250001;
    personInfoAr[1].age = 26, personInfoAr[1].salary = 250000;
    personInfoAr[2].age = 27, personInfoAr[2].salary = 250000;
    personInfoAr[3].age = 28, personInfoAr[3].salary = 25000;
    personInfoAr[4].age = 29, personInfoAr[4].salary = 2500000;
    cout<<" All initial info"<<endl;
    _printAllInfo(personInfoAr, arSz);

    set<PersonInfo, _cmp> personSet;
    for(int i=0; i < arSz; i++) personSet.insert(personInfoAr[i]);

    _printAllElementsOfSet(personSet);

    cout<<"Erasing person with age 27 from set"<<endl;
    PersonInfo p;
    p.age = 27, p.salary = 250000;
    personSet.erase(p);

    _printAllElementsOfSet(personSet);

    p.age = 27, p.salary = 100000;
    personSet.insert(p);
    p.salary = 200000;
    personSet.insert(p);
    p.salary = 300000;
    personSet.insert(p);

    cout<<" After inserting some new elements in set"<<endl;
    _printAllElementsOfSet(personSet);

    cout<<" Erasing all person with age 27 from set"<<endl;
    _eraseAllWithParticularValueFromSet(personSet);
    _printAllElementsOfSet(personSet);
}

/*
Output ->
 All initial info
Age: 25 Salary: 250001
Age: 26 Salary: 250000
Age: 27 Salary: 250000
Age: 28 Salary: 25000
Age: 29 Salary: 2500000


 Printing all info in set
Age: 29 Salary: 2500000
Age: 25 Salary: 250001
Age: 26 Salary: 250000
Age: 27 Salary: 250000
Age: 28 Salary: 25000


Erasing person with age 27 from set
 Printing all info in set
Age: 29 Salary: 2500000
Age: 25 Salary: 250001
Age: 26 Salary: 250000
Age: 28 Salary: 25000


 After inserting some new elements in set
 Printing all info in set
Age: 29 Salary: 2500000
Age: 27 Salary: 300000
Age: 25 Salary: 250001
Age: 26 Salary: 250000
Age: 27 Salary: 200000
Age: 27 Salary: 100000
Age: 28 Salary: 25000


 Erasing all person with age 27 from set
 Printing all info in set
Age: 29 Salary: 2500000
Age: 25 Salary: 250001
Age: 26 Salary: 250000
Age: 28 Salary: 25000

*/
