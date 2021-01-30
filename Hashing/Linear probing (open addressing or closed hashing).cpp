/*
Resources:
https://www.hackerearth.com/practice/data-structures/hash-tables/basics-of-hash-tables/tutorial/
https://www.geeksforgeeks.org/hashing-set-3-open-addressing/
*/
#include<bits/stdc++.h>
using namespace std;

#define MOD 100003  // 1e5+3
#define base 31
#define MX 100001
#define MX_LEN 10
#define Hash_Table_Size 200005  // double of MOD

int hashTableAr[Hash_Table_Size];
int hashTableId;
char hashTableString[MX][MX_LEN];

int _HASH(char *s)
{
    int len = 0, h = 0;
    while(s[len])
    {
        h = ( ((h*base)%MOD) + ((s[len]-'a'+1) %MOD) )%MOD; // considering string containing small letters only
        len++;
    }
    return h;
}

void _stringCopy(char *from, char *to)
{
    int i = 0;
    while(from[i])
    {
        to[i] = from[i];
        i++;
    }
    to[i] = '\0';
}
bool _stringMatch(char *s1, char *s2)
{
    int i = 0;
    while(s1[i] && s2[i])
    {
        if(s1[i]!=s2[i]) return false;
        i++;
    }
    if(s1[i]==s2[i]) return true;
    return false;
}

int _getIdFromHashTable(char *s, int h)
{
    while(hashTableAr[h]!=-1)
    {
        int id = hashTableAr[h];
        if( _stringMatch(s, hashTableString[id]) ) return id;   // string already exists in hash table, so returning position
        h++;
        if(h>=Hash_Table_Size) h = 1;
    }

    hashTableAr[h] = ++hashTableId;
    _stringCopy(s, hashTableString[hashTableId]);
    return hashTableId;
}

void _init()
{
    for(int i=1; i<Hash_Table_Size; i++)
    {
        hashTableAr[i] = -1;
    }
    hashTableId = 0;
}

void _insertIntoHashTable(char *s)
{
    int h = _HASH(s);
    int tableId = _getIdFromHashTable(s, h);
}

int _searchInHashTable(char *s)
{
    int h = _HASH(s);
    while(hashTableAr[h]!=-1)
    {
        int id = hashTableAr[h];
        if( _stringMatch(s, hashTableString[id]) ) return id;
        h++;
        if(h>=Hash_Table_Size) h = 1;
    }
    return -1;  // returns -1 if string is not present in the hash table
}

int main()
{
    _init();

    int N;
    cout<<"Number of string: ";
    cin>>N;
    char str[MX_LEN];
    while(N--)
    {
        cout<<"Give string to insert into hash table: ";
        cin>>str;
        _insertIntoHashTable(str);
    }
    int q;
    cout<<"Number of query: ";
    cin>>q;
    while(q--)
    {
        cout<<"Give string to search: ";
        cin>>str;
        int id = _searchInHashTable(str);
        if(id==-1) cout<<"String was not found"<<endl;
        else cout<<"String is present in the hash table"<<endl;
    }
    return 0;
}
