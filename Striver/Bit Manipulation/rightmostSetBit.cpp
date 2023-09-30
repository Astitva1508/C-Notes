#include <bits/stdc++.h>
using namespace std;

int main(){
    // To remove the rightmost set bit from the number 
    int num;
    cin>>num;
    
    //Way 1
    int rmsb = num & (-num); //This yields the number having only the rightmost set bit and rest all places are zero
    num-=rmsb; //Therefore we need to subtract this number from the original
    cout<<num<<endl;

    //Way2
    num = (num&(num-1)); // This yeilds a number having the rightmost bit turned off
    cout<<num<<endl;
    return 0;
}

