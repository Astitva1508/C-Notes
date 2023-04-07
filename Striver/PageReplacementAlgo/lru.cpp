#include <bits/stdc++.h>
using namespace std;

int lru(vector<int> pageDemands , int capacity,int size){
    queue<int> RAM;
    map<int,int> LRUCache;
    int pageFaults=0;
    for (int i=0;i<size;i++){
        if(LRUCache.size()<capacity){
            if (LRUCache.find(pageDemands[i])==LRUCache.end()){
                pageFaults++;
                RAM.push(pageDemands[i]);
                LRUCache[pageDemands[i]]=i; 
            }
        }else{

        }
    }
    return pageFaults;
}

int main()
{
    vector<int> pages = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    cout << lru(pages, 13, 4);
    return 0;
}