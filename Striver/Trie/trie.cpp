#include <bits/stdc++.h>
using namespace std;


class Trie{
    public:
    TrieNode *address;

    Trie(){
        address = new TrieNode();
    }

    bool search(string word)
    {
        TrieNode *trav = address;
        for (auto it : word)
        {
            if (!trav->isCharPresent(it))
                return false;
            trav = trav->get(it);
        }
        return trav->isEnd();
    }

    void insert(string word)
    {
        TrieNode *trav = address;
        for (auto it : word)
        {
            if (!trav->isCharPresent(it)) trav->put(it);
            trav = trav->get(it);
        }
        trav->setEnd();
    }

    bool startsWith(string word)
    {
        TrieNode *trav = address;
        for (auto it : word)
        {
            if (!trav->isCharPresent(it))
                return false;
            trav = trav->get(it);
        }
        return true;
    }

};

class TrieNode
{
    public:
    TrieNode *next[26] = {nullptr};
    bool isSet=false;

    TrieNode(){}

    bool isCharPresent(char c){
        return next[c-'a']!=nullptr;
    }

    void setEnd(){
        isSet=true;
    }

    bool isEnd(){
        return isSet;
    }

    void put(char ch){
        next[ch-'a'] = new TrieNode();
    }

    TrieNode *get(char ch){
        return next[ch-'a'];
    }

};