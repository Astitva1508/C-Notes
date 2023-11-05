// Find the number of pairs a and b such that a&b = k
// Here a and b are integers

#include <bits/stdc++.h>
using namespace std;

int main(){
    int k;
    cin>>k;
    long long int ans = 1;
    for(int i=0;i<32;i++){
        if(k&(1<<i)) continue;
        ans*=3;
    }
    cout<<ans<<endl;
    return 0;
}