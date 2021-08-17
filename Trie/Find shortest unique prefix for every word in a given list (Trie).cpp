/**
Idea:
Construct a Trie of all words. Also maintain frequency of every node (Here frequency is number of times node is visited during insertion).
Time complexity of this step is O(N) where N is total number of characters in all words.

Resources:
https://www.geeksforgeeks.org/find-all-shortest-unique-prefixes-to-represent-each-word-in-a-given-list/
*/


#include<bits/stdc++.h>
using namespace std;

typedef struct Trie
{
    bool endFlag;
    int visCount;
    struct Trie *child[26];
    Trie()
    {
        endFlag = false;
        visCount = 0;
        for(int i=0; i<26; i++) child[i] = NULL;
    }
} Trie_Node;

void _insertIntoTrie(Trie_Node *root, string str)
{
    for(int i=0; str[i]; i++)
    {
        int charId = str[i] - 'a';
        if(root->child[charId] == NULL) root->child[charId] =new Trie();
        root = root->child[charId];
        root->visCount++;
    }
    root->endFlag = true;
}

void _getShortestUniquePrefix(Trie_Node *root, char output[], int outputSz)
{
    if(root == NULL) return ;

    if(root->visCount == 1)
    {
        output[outputSz] = '\0';
        cout<<output<<endl;
        return ;
    }

    for(int i=0; i<26; i++)
    {
        if(root->child[i])
        {
            output[outputSz] = i + 'a';
            _getShortestUniquePrefix(root->child[i], output, outputSz+1);
        }
    }
}

int main()
{
    int N, testCase;
    string strArr[] = {"zebra", "dog", "duck", "dove"};
    int sz = sizeof(strArr)/sizeof(strArr[0]);

    Trie_Node *root = new Trie();

    for(int i=0; i<sz; i++)
    {
        _insertIntoTrie(root, strArr[i]);
    }

    char prefix[100];
    _getShortestUniquePrefix(root, prefix, 0);

    return 0;
}
