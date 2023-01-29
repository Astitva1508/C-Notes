#include <iostream>
using namespace std;

// Templates enable us to pass data type as a parameter so that we don’t need to write the same code for different data types.
// You can convert any Data Structure Class into a template

// We can use the same class or a function to operate on multiple data types.

// Generic Class or Template Class

template <typename T>class Arithmetic{
private:
    T num1;
    T num2;
public:
    Arithmetic(T a , T b){
        this->num1=a;
        this->num2=b;
    }
    T Sum();
    T Subtract();
    ~Arithmetic(){
    }
};
// We can use the generic data type T only inside the class. For data members of the class defined outside it (using scope resolution operator) , we need to make them generic data members as shown below

template <typename T>T Arithmetic<T>::Sum()
{
    return num1+num2;
}
// Since the Arithmetic class is a template class so whenever we use the class name , we should specify the template parameter

template <class T> T Arithmetic<T>::Subtract(){
    return num1-num2;
}

// Generic Function
template <class T> T maxOfTwo(T t1,T t2){
    if (t1>t2) return t1;
    return t2;
}
// The 'typename' keyword can always be replaced by the keyword ‘class’.

int main(){
    cout<<maxOfTwo<int>(12,32)<<endl;
    cout<<maxOfTwo<std::string>("a","b")<<endl;
    return 0;
}

// Its a better idea to first write the class for a known data type and then converting it to templates .( Instead of starting from the templates from the get go)