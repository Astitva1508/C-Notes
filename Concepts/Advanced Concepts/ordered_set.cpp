// Reference Article : https://codeforces.com/blog/entry/11080

#include <bits/stdc++.h>

// Extra Imports 
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>     // Including tree_order_statistics_node_update

using namespace std;
// Additional Namespace
using namespace __gnu_pbds;

typedef tree<
    int,
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update> ordered_set;

void theory()
{
    // Ordered Set is a policy based data structure

    // Supported Operations
    // 1. Insertion an element X into the set 
    // 2. Delete an element X from the set 
    // 3. Return number of elements smaller than X in the current set 
    // 4. Print the element at the ith index
    
    // Completes all the operations in log(N) time

    // Provides all the functionalities provides by normal sets and additional methods 3 and 4
}

void implement(){
    ordered_set x;
    // Insertion (ignores duplicates)
    x.insert(1);
    x.insert(10);
    x.insert(2);
    x.insert(7);
    x.insert(7);

    // Printing (prints in ascending order as comparator is less<int>)
    for(auto it:x) cout<<it<<" ";
    cout<<endl;

    // Finding the kth element 
    cout<<*x.find_by_order(1)<<endl;

    // Finding number of elements smaller than x
    cout<<x.order_of_key(6)<<endl;

    // First element that is greater than or equal to x : lower_bound
    // First element that is greater than x : upper_bound

    cout<<*x.lower_bound(10)<<endl;
    cout<<*x.upper_bound(4)<<endl;

    // Erase an element
    x.erase(5); // No effect if the element is not present in the set
    x.erase(2);

}

int main(){
    theory();
    implement();
    return 0;
}