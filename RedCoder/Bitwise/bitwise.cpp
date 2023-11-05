#include <bits/stdc++.h>
using namespace std;

void theory();

int main(){
    int x  = 5;
    cout<<x<<endl;
    cout<<!x<<endl;
    cout<<(x^1)<<endl;
    return 0;
}

void theory(){
    // Sum of all the other bits = 2^(MSB BIT)-1
    // Significiance of the rightmost bit is always the most
    // Useful in Greedy

    int x = 0b101;
    // prefix 0b implies that the number 001 is in binary

    // Signed Numbers : We use the last bit for determining the sign of the number and the remaining digits determine the number
    // so a 32 bit signed integer can store from -2^31 to 2^31-1

    // bit XOR 1 = opposite bit 
    // bit XOR 0 = bit

    // When doing bitwise operations, every bit of the number is independent of the other => we can solve for each bit independently

    cout<<x<<endl;
}

void inbuiltFuncs(){
    int ans = __builtin_popcount(12); 
    // applies only for integers
    // Counts the number of 1 bits in the number

    ans = __builtin_popcountll(32);
    // same task but applies for long long 

    ans = __builtin_ctz(34);
    // Counts the number of trailing zeroes (number of zeroes before the first set bit is encountered)
    // crashes for 0

    ans = __builtin_clz(34);
    // Counts the number of leading zeroes 
    // crashes for 0

    // for ll, suffix ll
    ans = __builtin_ctzll(23);
}

void randomTricks(){
    // x%2 = x&1;
    // x%(2^n) = x&(2^n-1)

    // a + b = a^b + 2(a&b)
    // a + b = a|b + a&b

    // Bitsets : We can represent a set of bits (0s and 1s) in an integer and it is pretty useful

    // Bitmask DP : where the dp state is a bunch of zeroes and ones.
    // When we iterate over some mask, then we also iterate over all the submasks
    // Submasks =  all the bits which are set in the submask are also set in the main mask, but vice versa not true
    // So Total Complexity : 
        // if there are 2^n-1 masks
        // For each mask, there are 2^popcount() submasks (as there popcount() set bits and they can be zero or one)
        // So , Summation from i = 0 to 2^n-1 of (2^popcount(i)) == 3^n
    // Reason : With the concept of iterating over submasks, every submask has three possible states, it can be 
                    // O in both submask and larger mask
                    // 1 in both the submask and larger mask
                    // 0 in larger ma sk and 0 in submask
}