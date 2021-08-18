#include <unordered_map>

#include <iostream>
using namespace std;


void _takeInput(unordered_map<string, int> &ump)
{
    ump["apple"] = 1;
    ump["ball"] = 2;
    ump["cat"] = 3;
    ump["dog"] = 4;
    ump["Dog"] = 5;
}

void _printAll(unordered_map<string, int> &ump)
{
    /*
    for(unordered_map<string, int> :: iterator it = ump.begin(); it != ump.end(); it++)
    {
        cout<<"key: "<< it->first <<" value: "<< it->second <<endl;
    }
    */

    // iterate using auto
    for(auto it : ump)
    {
        cout<<"key: "<< it.first <<" value: "<< it.second <<endl;
    }
}

void _eraseAnElement(unordered_map<string, int> &ump)
{
    ump.erase("dog");
}

int main()
{
    unordered_map<string, int> ump;

    _takeInput(ump);

    _printAll(ump);

    _eraseAnElement(ump);

    return 0;
}
