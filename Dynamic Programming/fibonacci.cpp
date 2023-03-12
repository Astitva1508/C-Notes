#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
static int arr[N]={-1};

int fibonacci(int n){
    if (n<=1) return n;
    if (arr[n]==-1){
        if (arr[n-1]==-1) arr[n-1] = fibonacci(n-1);
        if (arr[n-2]==-1) arr[n-2] = fibonacci(n-2);
        arr[n] = arr[n-1]+arr[n-2];
    } 
    return arr[n];
}

int main(){

    return 0;
}