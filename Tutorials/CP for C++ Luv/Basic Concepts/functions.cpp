#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10; //declare something greater than upper bound of the array size
int arr[N];

void Basics1(){
    int arr[10];
    int multiArr[20][20];
    //Why main function need not have any return type?
        //Modern compilers treat main as a special function and assume that (return 0) happens

    // References in C++:
    // Can do everything that pointers can do
    //  int n=3;
    // int &b=n;
    // cout<<++b<<endl;
    // cout<<n<<endl;
    // references(n);
    // cout<<n<<endl;
    // Arrays by default are passed by references

    //Ways to run an array:
    waysToPassAnArray1(arr);
    waysToPassAnArray2(arr);
    waysToPassAnArray3(arr,10);

    //Ways to create a multi-dimensional array:
    //When creating the function , we can only skip the first size(i.e the row size) , rest others need to be passed....in the language of the compiler:
    // declaration of 'arr' as multidimensional array must have bounds for all dimensions except the first
    //Ways to Call a multidimensional array
    waysToPassAMultiDimensionalArray(multiArr);

    //We generally avoid passing multi-dimensional or in general , arrays to the functions in CP

    //If you want to use an array in a function , dont declare inside main but globally
}

int main()
{
    
    return 0;
}

void references(int &n)
{
    n++;
    // Here ,in the argument list , passing &n means n is passed by reference. So any changes in the value of n are reflected
}

void waysToPassAnArray1(int arr[10]) {}
void waysToPassAnArray2(int arr[]) {}
void waysToPassAnArray3(int arr[], int sizeOfArray) {} // If you need to keep the track record of the size of the array

void waysToPassAMultiDimensionalArray(int arr[][20]) {}
