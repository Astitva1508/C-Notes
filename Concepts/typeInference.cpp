#include <iostream>
using namespace std;

//auto keyword

void autoKeyWord(){
    // auto x; //throws an error
    // The variable declared with auto keyword should be initialized at the time of its declaration only 
    auto y = 4;

    // UseCase : avoid long initializations when creating iterators for containers.
    // Catch: auto becomes int type if even an integer reference is assigned to it. To make it reference type, we use auto &.
}

int main(){
    return 0;
}