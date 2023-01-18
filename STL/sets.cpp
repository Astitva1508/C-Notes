#include <bits/stdc++.h>
using namespace std;

void basicTheoryMultiSet(){
    multiset <string> s;
    // Can store duplicate values
    // Operations become log(n)
    // Used mostly in place of Priority Queues

    // s.find() returns the iterator of the first instance of input element
    // For s.erase() , when we pass the iterator , the element at the position of the iterator is deleted. If an element is passed, all the instances of the element are deleted
}

int main(){
    return 0;
}

void printSet(set<string> &s)
{
    for (string element : s)
        cout << element << "  ";

    // for (auto it = s.begin();it!=s.end();it++) cout<<*it<<" ";
}

void basicTheorySets()
{
    // Set represents a collection of some elements
    // It stores elements in sorted order
    // Time Complexity of Insertion , Accessing etc is O(log(n))
    // It also stores uniqie elements only
    set<string> s;
    // Insertion
    s.insert("Astitva");
    s.insert("Rehan");
    s.insert("Nitish");

    // Accessing
    auto it = s.find("Astitva"); // Returns the iterator

    // Printing
    printSet(s);

    // When we provide iterator to erase , its average time complexity is O(1)
}

void basicTheoryUnorderedSets()
{
    unordered_set<string> s;
    // Time Complexity of Insertion , Accessing etc is O(1)
    // Used where order of storing elements does not matter and when we need to find whether a given value exists in the set or not
    // Internally implemented using hash tables
    // Keys cannot be complex data types. If you need to store complex data types , need to define your own hash function which is beyond the scope right now
}