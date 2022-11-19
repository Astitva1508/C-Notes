#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

void Basics1(){
    // Calculations in C++ takes place in higher data types:
    // Double > FLoat > Long Long Int > Long Int > Int > Char

    // Range of Integers
    // Int : -10^9 - 10^9
    // Long Int : -10^12 - 10^12
    // Int : -10^18 - 10^18

    cout << INT_MAX << endl; // The maximum value that an int can store
    cout << INT_MIN << endl; // The minimun value that an int can store

    int max = INT_MAX;
    cout << max + 1 << endl; // On addition of one to INT_MAX , the whole cycle gets reversed
    // 1LL is equivalent of 1 stored as Long Long Int and is used to manipulate the calculations in CP

    // When the outut comes in scientific notation , to remove it,use the keyword fixed.
    double pow = 10000000000;
    cout << pow << endl;
    cout << fixed << pow << endl;

    // Setprecision(n) is used to display the output to n decimals.
    cout << fixed << setprecision(0) << pow << endl;

    // Even thouugh we can store a really big number in float and double , we cannot store it accurately.e.g
    pow = 1e24;
    cout << pow << endl;
    // Isliye jis type me input lena is best suited ho for the range of the question , usi me input lenge aur aisa nahi ki double me input lena shuru kar diya.
}

void Basics2(){
    //Result of a boolean expression is either 1 or 0

    //C++ characterizes a pair of curly braces as a scope

    //Syntax of a for loop
    // for (initialization;condition;operation){}
    // one or more of the initialization , condition and operation can be skipped as well
    // What I want to say is dont make a rigid definition of for loop in your mind
    // operation can be anything and need not necessarily be i++, it can be cout<<i++<<endl;
    // for loop ka use karne se variable waste nahi hota outer scope me

    // To run the test cases loop in C++ , the best way is while(t--). Isse variable waste nahi hoga

    // break and continue hamesha sabse closest running loop ke baahar jaate hain.

}

void Basics3()
{
    // cin takes input till it does not encounter a space or a newline. This limits its ability to take a multi-line or a multi-space input

    // We can concatenate string as well as perform comparison operations on them
    string a = "Astitva Dubey";
    cout << a.size() << endl;

    // Multi-space inputs taken using getline
    getline(cin, a);
    cout << a << endl;

    // Multi-line inputs taken using multiple getline
    // cin takes input not from where the cursor is but where there is anything except whitespaces.However getline takes input from the place where the cursor is till the next \n

    cin.ignore(); // shifts the input cursor to the next line where there is something other than whitespaces

    a.push_back('d');
    // Appends a character at the end of the string. This method is better than a+='d' due to time complexity reasons.
    //a += d ki time complexity a ke size par depend karti hai kyonki wo phle string ki copy banaata hai then usko string me store karta hai. Hence Time Complexity O(a.size())

    // Large numbers (greater than 10^18) are taken input using strings and then operations performed using manipulation

    // Conversion of a character to an integer
    char character = '2';
    int charAsInt = character - '0';
    cout << charAsInt << endl;
}