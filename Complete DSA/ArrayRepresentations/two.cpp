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

