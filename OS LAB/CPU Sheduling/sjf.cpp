#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arrival(n);
    vector<int> burst(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arrival[i] >> burst[i];
    }
    int totalCPUTime = 0;
    int totalWaitTime = 0;
    int currProcessWaitTime = 0;
    while (!arrival.empty())
    {
        int min = INT_MAX;
        int index = -1;
        for (int i = 0; i < arrival.size(); i++)
        {
            if (arrival[i] <= totalCPUTime && burst[i] < min)
            {
                min = burst[i];
                index = i;
            }
        }
        currProcessWaitTime = totalCPUTime - arrival[index];
        if (currProcessWaitTime > 0)
            totalWaitTime += currProcessWaitTime;
        totalCPUTime += burst[index];
        arrival.erase(arrival.begin() + index);
        burst.erase(burst.begin() + index);
    }
    cout << totalWaitTime << endl;
    return 0;
}