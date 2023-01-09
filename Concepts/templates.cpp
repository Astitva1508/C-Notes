#include <iostream>
using namespace std;

// Templates enable us to pass data type as a parameter so that we don’t need to write the same code for different data types.

template <typename T> T maxOfTwo(T t1,T t2){
    if (t1>t2) return t1;
    return t2;
}

int main(){
    cout<<maxOfTwo<int>(12,32)<<endl;
    cout<<maxOfTwo<std::string>("a","b")<<endl;
    return 0;
}