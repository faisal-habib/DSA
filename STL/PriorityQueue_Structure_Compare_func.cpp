#include<queue>

#include<iostream>
using namespace std;

typedef struct
{
    int age;
    int salary;
}PersonInfo;

struct _cmp
{
    bool operator()(const PersonInfo &p1, const PersonInfo &p2)
    {
        /* people with max salary will be on top. is salary is same, then greater aged people will be on top*/
        return !( p1.salary > p2.salary || (p1.salary == p2.salary && p1.age < p2.age) );
    }
};

void _defaultPriorityQueueOperations(PersonInfo personInfoAr[], int &arSz)
{
    priority_queue< PersonInfo, vector<PersonInfo>, _cmp >pq;

    for(int i=0; i < arSz; i++)
    {
        pq.push(personInfoAr[i]);
    }

    while(!pq.empty())
    {
        cout<<"Age: "<<pq.top().age<<" Salary: "<<pq.top().salary<<endl;
        pq.pop();
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

    _defaultPriorityQueueOperations(personInfoAr, arSz);
}

/*
Output:
Age: 29 Salary: 2500000
Age: 25 Salary: 250001
Age: 26 Salary: 250000
Age: 27 Salary: 250000
Age: 28 Salary: 25000
*/
