#include <bits/stdc++.h>
using namespace std;

// Designing a Set DS (This concept is used in DP. Set designed using BitMasking)
// Set DS implements the following properties
// insert(num) in log(N)
// erase(num) in log(N)
// print() //to print all the elements in the sorted order

//The space complexity is O(1) and time complexity is O(1)

// number of elements is less than 64

// Take a long long int (having 64 bits) and set the bit to one which bit is to be added and set the bit to zero which cannot be your answer

class Set{
    long long int x;
    public:
        Set(){
            x=0;
        }
        void add(int num){
            x = x|(1<<num);
        }
        void remove(int num){
            x = x ^ ~(1<<num);
        }
        void print(){
            for(long long int i=0;i<=63;i++){
                if(x & (1<<i)) cout<<i<<" ";
            }
        }
};

int main(){
    return 0;
}