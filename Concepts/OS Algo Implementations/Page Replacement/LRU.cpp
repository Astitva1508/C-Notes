#include <bits/stdc++.h>
using namespace std;

class LRUCache
{
    unordered_map<int, int> keys;
    int capacity;
    vector<int> prevDemands;

public:
    LRUCache(int capacity)
    {
        this->capacity = capacity;
    }

    int get(int key)
    {
        prevDemands.push_back(key);
        if (keys.find(key) != keys.end())
        {
            return keys[key];
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (keys.find(key) != keys.end())
            keys[key] = value;
        else if (keys.size() < capacity)
        {
            keys[key] = value;
        }
        else
        {
            int keyToDelete;
            unordered_set<int> recentlyUsedKeys;
            for (int i = prevDemands.size() - 1; i >= 0; i--)
            {
                int it = prevDemands[i];
                cout << it << endl;
                if (keys.find(it) != keys.end())
                {
                    recentlyUsedKeys.insert(it);
                }
                if (recentlyUsedKeys.size() == keys.size())
                {
                    keyToDelete = it;
                    break;
                }
            }
            keys.erase(keyToDelete);
            keys[key] = value;
        }
        prevDemands.push_back(key);
    }
};