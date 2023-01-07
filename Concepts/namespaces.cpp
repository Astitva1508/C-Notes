#include <iostream>
// using namespace std;

using std::endl;

namespace first{
    int age = 25;
}

namespace second{
    int age =14;
}

int main(){
    first::age = 30;
    std::cout<<first::age<<endl;
    return 0;
}

//Namespaces are used to resolve conflicts that we get when two or more variables have the same name
//A Namespace can contain multiple variables
//Using namespace std suggests the program to use the standard namespace.This enables us to use all of its members without writing the full std::endl;
//An alternative to that is to define all the variables of the std namespace that we need in our program right at the top.
//The second approach is better as it prevents including all the unnecessary members of the std namespace