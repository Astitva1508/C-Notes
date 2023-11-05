#include <iostream>
#include <queue>
using namespace std;

void printQueue(queue<int> queue){
    while(!queue.empty()){
        cout << queue.front() << endl;
        queue.pop();
    }
}

int main(){
    queue<int> numbersQueue;
    numbersQueue.push(1);
    numbersQueue.push(2);
    numbersQueue.push(3);
    // cout<<numbersQueue.size()<<endl;
    // cout<<numbersQueue.front()<<endl;
    // cout<<numbersQueue.back()<<endl;

    printQueue(numbersQueue);
    return 0;
}

// Queue implement FIFO 
// Usecase in Programming: When we need things to happen in the exact order they were called
// Functions involving queue:  push,front,size,back