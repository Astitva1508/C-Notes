#include <iostream>
using namespace std;

void swap(int a ,int b){
    //Copies of a and b are passed
    //pass by values
    int c = a ;
    a = b ;
    b = c ;
}

void SwapUsingPointer(int *a,int *b){
    //Addresses of a and b are passed
    //Pass By Reference
    //In Pass By Reference , we directly manipulate with the values stored at the passed addresses
    int c = *a ;
    *a = *b ;   
    *b = c ;   
}

void swapPointersUsingPointers(int *a,int *b){
    int c = *a;
    *a = *b ;
    *b = c;
}

void passByReferenceNotWorking(int *a){
    cout<<a<<endl;
    int b = 4;
    a = &b;
    cout<<a<<endl;
}

int main(){
    int num1,num2;
    cin>>num1>>num2;
    // swap(num1,num2);
    // cout<<num1<<" "<<num2<<endl;
    // SwapUsingPointer(&num1,&num2);
    // cout<<num1<<" "<<num2<<endl;
    // int *num1Add = &num1;
    // int *num2Add = &num2;
    // swapPointersUsingPointers(num1Add,num2Add);
    // cout<<num1<<" "<<num2<<endl;
    passByReferenceNotWorking(&num1);
    cout<<&num1<<endl;
    return 0;
}