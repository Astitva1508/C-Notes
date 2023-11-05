#include<iostream>
#include <vector>
using namespace std;

void HowNotToPassAVector(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
        cout << v[0] << "  ";
}

void howToPassAVector(vector<int> &v){
    for (int i=0;i<v.size();i++) cout<<v[0]<<"  ";
}

int main(){
    vector<int> numbers;
    // Declaration of a Vector of a given size:
    vector<int> vec(5); // The value of all the elements is zero
    // Note that the above vector is also dynamic

    // Declaration of a Vector of a given size with a given initial values for all indices
    vector<int> vec1(10,4);

    // We can copy vectors directly.Changes made in the copy are not reflected in the original vector and vice-versa
    vector <int> vectorToCopy = vec1; // Time Complexity of this operation : O(N)
    // Now because while passing parameters to a function , copy of the parameters are generated , similarily when we pass a vector as a parameter , its copy is generated and this is an expensive operation.
    // Unlike Arrays, vectors are passed by values.
    // So The Way we pass vector to a function is using reference :
    howToPassAVector(vec1);

    vector<int> &vn = vec;  //Now vn is created as reference and is the same as vec.Its not a copy

    int a[10];
    // int b[10]= a;  Throws an error
    // int &c = a;    Throws an error  
    int *b = a;
    // In arrays , we can copy them using the pointer but they both effectively point to the same thing 

    return 0;
}

// Vectors are similar to arrays but dynamic

// Time Complexity :
    // push-back : O(1)
    // size :O(1)
    // pop_back : O(1)

// Vectors have similar limits as arrays for continous memory allocation i.e. Local Array is of the order of 10^5 and global arrays of the order of 10^7

// You cannot access the indices of a vector that you haven't created;