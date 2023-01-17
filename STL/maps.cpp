#include <bits/stdc++.h>
using namespace std;

void basicTheoryMultiMaps(){
    multimap<int,string> m;
    // Internally implemented using Red Black Trees
    // Keys in multimap are need not be unique
}



int main(){
    return 0;
}

void basicTheoryMaps()
{
    // Map is used to store key:value pairs
    // Ordered Maps are implemented as RedBlackTrees(self balancing tree)
    // Every element of a map is a pair

    map<int, string> m;
    m[1] = "a"; // Insertion Operation Time Complexity O(log(n)) where n is the current size of the map
    m[0] = "g";
    m[3]; // Key 3 is inserted into the map with value = 0.If we don't provide values for the keys , default values are inserted.

    // Time Complexity of accessing the elements of the map is log(n) also
    for (auto it : m)
    {
        cout << it.first << " " << it.second << endl;
    } // Time Complexity of the loop is nlog(n)

    // Find the value corresponging to a given key
    auto it = m.find(3); // find returns an iterator corresponding to the key value pair if the value is present in the map , else it returns m.end()
    // Time Complexity of .find() is also O(log(n))

    // For most of the Self Balancing Trees , operations have a time complexity of log(n)

    // m.erase() -> erases the key value pair corresponding to the input key or iterator
    // Time Complexity : log(n)
    m.erase(1);  // Deletion by the value of key
    m.erase(it); // Deletion by the iterator value
    // if the iterator passed to the erase DNE, gives segmentation fault

    // Note that although the insertion operation in map is O(log(n)) , it also depends upon the data type of the key
    // Whenever we insert a new value into the map , its compared to the existing values. (Internally, log(n) comparisons take place). Now if the key is a string , time for string comparison also adds up[kyonki string character by character compare hongi]. So overall complexity becomes O(log(n)*lengthOfString)

    // To take input of a string of size n , time taken is O(n)
}

void basicTheoryUnOrderedMaps()
{
    // Difference between ordered and unordered maps
    // 1. Inbuilt Implementation
    // 2. Time Complexity
    // 3. Valid Data Types for the keys

    // All functions for unordered maps are same as maps

    // Maps are internally implemented using Trees while Unordered Maps are internally implemented using Hash Tables. For every key , hash value is calculated
    // Average Time Complexity of most of its operations(Insertion and Accessing,.find() , .erase()) is O(1)
    // For Maps , we can add complex data types as keys but not for unordered maps.This is because we calculate hash value for the keys and there is no inbuilt hash function defined for complex data types.
    // Usually we can have basic data types as keys only for unordered maps. For the ordered maps , we can have any data type as  keys as long as it supports comparisons

    // Always use UnOrdered Maps if order of storing does not matter
}