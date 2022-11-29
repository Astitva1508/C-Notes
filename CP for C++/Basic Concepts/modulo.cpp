#include<bits/stdc++.h>
using namespace std;

void ModularArithmetic(){
    // (a+b)%m = [(a%m)+(b%m)]%m    //similarly for multiplication
    // (a-b)%m = [(a%m)-(b%m)+m]%m   //Here we add M to make the net result positive
    // (a/b)%m = [(a%m)*(b^-1 %m)]%m , where b^-1 is "b inverse" or "multiplicative inverse of b" which is calculated using binary/modular exponentian
}

void WhyM(){
    // M = 10^9+7 ?
    //1. because it is close to the maximun value that int data type can store. This implies that the final answer after modulo M can be stored in an integer.
    //2. Coz it is a prime number. And we can't calculate multiplicative inverse for every number. However , if we are to perform (a/b)%M and M is prime , then we can calculate MMI for all numbers from 1 to M. This implies if M=10^9+7 , we can calculate MMI from 1 to M which practically covers all the integers.
}

int main(){

}

//ToDo: Modular Exponentian