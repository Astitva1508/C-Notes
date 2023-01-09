#include<iostream>
using namespace std;
#include<stack>

void printStackElements(stack<int> stack){
    while (stack.size()>0){    //or while(!stack.empty())
        cout<<stack.top()<<endl;
        stack.pop();
    }
};
int main(){
    stack<int> numbersStack;

    numbersStack.push(5);
    numbersStack.push(6);
    numbersStack.push(7);
    numbersStack.pop();
    // cout<<numbersStack.empty()<<endl;
    // cout<<numbersStack.size()<<endl;
    printStackElements(numbersStack);

    return 0;
}

// Stacks implement LIFO (last plate added is the first one to be removed)
// e.g Stack Of Plates

// Important functions to work with stack
// empty, size ,top ,push, pop 