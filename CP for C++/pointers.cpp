#include <bits/stdc++.h>
using namespace std;

void Pointers(){
    //Pointers addition me bytes add hote corresponding to the size of the data type stored by the pointer
    //if int stores 4 bytes,
    int a = 3;
    int *b=&a;
    cout<<b<<endl;
    b+=1; //adds 4 bytes
    cout<<b<<endl;
}

int main()
{
    Pointers();
    return 0;
}