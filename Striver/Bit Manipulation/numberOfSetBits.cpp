#include <bits/stdc++.h>
using namespace std;

int main(){
    int num;
    cin>>num;
    int ct1 = 0;
    //Way 1 
    while(num!=0){
        ct1+=(num&1);
        num=num>>1;
    }
    // Ans = ct1

    //Way 2
    int ct2 = 0;
    while(num!=0){
        num = (num&(num-1)); // This removes the rightmost set bit
        ct2++;
    }
    // Ans = ct2
    return 0;
}