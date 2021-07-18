#include<iostream>
#include<algorithm>
using namespace std;

typedef struct
{
    int age, salary;
}Info;

bool _cmp(Info info1, Info info2)
{
    return ( info1.age < info2.age || (info1.age == info2.age && info1.salary > info2.salary) );
}
void _printAllInfo(Info arr[], int arrSz)
{
    cout<<"--------------------------------------------------"<<endl;
    for(int i=0; i<arrSz; i++)
    {
        cout<<"Person "<<i+1<<" Age: "<<arr[i].age<<" Salary: "<<arr[i].salary<<endl;
    }
    cout<<"--------------------------------------------------"<<endl;
}
int main()
{
    Info infoAr[10];
    int infoArSize = 10;
    for(int i=0; i<infoArSize; i++)
    {
        infoAr[i].age = rand() % 60;
        infoAr[i].salary = rand();
    }
    cout<<"Information before sorting"<<endl;
    _printAllInfo(infoAr, infoArSize);

    sort(infoAr, infoAr+infoArSize, _cmp);

    cout<<"Information after sorting"<<endl;
    _printAllInfo(infoAr, infoArSize);
}
