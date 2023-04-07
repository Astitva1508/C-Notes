#include <bits/stdc++.h>
using namespace std;

int fact(int n)
{
    if (n == 0)
        return 1;
    return n * fact(n - 1);
}

string getPermutation(int n, int k)
{
    string sub;
    k-=1;
    for (int i = 1; i <= n; i++)
    {
        sub.push_back(i + 48);
    }
    string output;
    // if(n==1) return "1";
    while(n>0){
        int factorial = fact(n - 1);
        int firstIndice = k/factorial;
        k = k % factorial;
        output.push_back(sub[firstIndice]);
        sub.erase(sub.begin() + firstIndice);
        n-=1;
    }
    return output;
}

int main(){
    cout<<getPermutation(4,9)<<endl;
    return 0;
}

