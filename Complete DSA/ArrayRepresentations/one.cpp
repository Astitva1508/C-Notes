// Increasing the Size of a Dynamic Array

#include <bits/stdc++.h>
using namespace std;

int main(){
    int * p = new int(5);
    for (int i=0;i<5;i++) p[i] = i+1;

    // Now we need a larger sized array
    int * q= new int (10);
    for (int i=0;i<5;i++) q[i] = p[i];

    delete []p;
    p=q; //Now p is also pointing towards q
    q=NULL ; // Now q is not pointing anywhere
    return 0;
}