#include <bits/stdc++.h>
using namespace std;

int fcfs(vector<int> pageDemands,int size,int capacity){
    unordered_set<int> CPUDummy;
    queue<int> CPU;
    int pageFaults=0;
    for (int i=0;i<size;i++){
        if(CPUDummy.size()<capacity){
            if (CPUDummy.find(pageDemands[i])==CPUDummy.end()){
                CPUDummy.insert(pageDemands[i]);
                CPU.push(pageDemands[i]);
                pageFaults++;
            }
        }
        else{
            if (CPUDummy.find(pageDemands[i]) == CPUDummy.end()){
                int val = CPU.front();
                CPU.pop();
                CPUDummy.erase(val);
                CPU.push(pageDemands[i]);
                CPUDummy.insert(pageDemands[i]);
                pageFaults++;
            }
        }
    }
    return pageFaults;
}


int main()
{
    vector<int> pages = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    cout<<fcfs(pages,13,4);
    return 0;
}