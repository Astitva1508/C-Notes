// Program to demostrate methods of creating a 2-D Array


#include <bits/stdc++.h>
using namespace std;

void illustration()
{
    int *ptr;
    int x = 5;
    ptr = &x;
    cout << ptr[0] << endl;
}

int main(){
    int *ptr = new int[6];
    illustration();
    int array[5]; //Creates memory space to store five integers
    
    // Method 1
    int array1[5][6]; // Creates memory space for 30 integers
    // Note that the moemory allocated is continous only.Only for accessing purposes , it seems as if some 2-D array is created
    // array1[0][6] yaani ki zeroth position of an array 1 par tum 6 integers store kar sakte

    // Method 2
    int* array2[5];
    for (int i=0;i<5;i++){
        array2[i] = new int[6];
    }
        //Accesing : array2[x][y]  
        // Deallocating memory
    for (int i=0;i<5;i++){
        delete [](array2[i]);
    }

    // Method 3
    // Creating a 2-D Array completely inside heap
    int **ultimateAddress= new int*[5];
    for (int i=0;i<5;i++){
        ultimateAddress[i] = new int[6];
    }
    //Deallocating Memory
    for (int i=0;i<5;i++){
        delete []ultimateAddress[i]; 
        // or delete []*(ultimateAddress+i)
    }
    delete []ultimateAddress;
    // ultimateAddress=NULL;
    ultimateAddress=nullptr;
    return 0;
}

// How a Compiler internally represents Array ? using formula
// Address(array[i]) = L + i*sizeof(data type stored in array ) 
// Here L is the base address which is known at runtime once the memory for an array is allocated

// How a 2-D Array is handled by a compiler?
// Representation of a 2-D Array mapped on a single dimension :
// 1. Row Major Mapping 
// Address(array[i][j]) = L+(i*(noOfColumns)+j)*sizeof(data type stored in array)
// 2. Column Major Mapping
// Address(array[i][j]) = L+(j*(noOfRows)+i)*sizeof(data type stored in array)

// C++ compiler uses Row Major Mapping  

// TO Do : Concept of Data Binding in System Programming or Assembly Language Programming

// Formula for n-D Arrays
// e.g. a[i1][i2][i3][i4]  where total elements in each are a[n1][n2][n3][n4]
// Row Major (left to right) : L+(i1*d2*d3*d4+i2*d3*d4+i3*d4+i4)*w
// Column Major (right to left) : L+(i4*d3*d2*d1+i3*d2*d1+i2*d1+i1)*w

// No Of Multiplications in case of Row Major Mapping : O(n^2)
// No Of Multiplications can be reduces by taking common : O(n)
// Method of reducing multiplications by taking common called as Horner's Rule

// Row Major Mapping simply means left to right(while writing the formula)
// Column Major Mapping means right to left(while writing the formula)