#include<bits/stdc++.h>
using namespace std;

#define MOD 10007

unsigned long HASH(int key)
{
    unsigned long h = 5381;
    int c;

    while (key!=0)
    {
        c = key % 10;
        h = ( ( (h << 8) + h) + c ) % MOD;
        key = key / 10;
    }

    return h % MOD;
}

int main()
{
    int n;
    while(1)
    {
        cin>>n;
        cout<<"h: "<<HASH(n)<<endl;
    }
}
