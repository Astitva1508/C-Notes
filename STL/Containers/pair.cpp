#include <iostream>
using namespace std;

// Pair stores two values

int main(){
    // Declaration
    pair<int,string> p;
    // Initialization During Declaration
    pair<int,string> p1(2,"Ashish");

    pair<int,string> p2 = p1;  //Values are passed as a copy
    p2.first=5; //Value does not change for p1
    pair <int,string> &p3=p1; //Values are passed as reference
    p3.first=10; //Value for p1 changes

    // Initialization
    p=make_pair(1,"Astitva");
    p={3,"Krishti"};
    p.first = 4; //Value Changes

    // Accessing a Pair
    cout<<p1.first<<" "<<p.second<<endl;

    // Use Of Pairs:To maintain relationship between two entities


    return 0;
}