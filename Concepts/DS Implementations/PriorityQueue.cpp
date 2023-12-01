#include<bits/stdc++.h>
using namespace std;

int PQ[50];
int sz=-1;

int parent(int index){
    return((index-1)/2);
}

int leftChild(int index){
    return 2*index+1;
}

int rightChild(int index){
    return 2*index+2;
}

void shiftUp(int index){
    while(index>=0 && PQ[index]>PQ[parent(index)]){
        swap(PQ[index],PQ[parent(index)]);
        index=parent(index);
    }
}

void shiftDown(int index){
    int desiredIndex = index;
    int left = leftChild(index);
    int right = rightChild(index);

    if(left<=sz && PQ[desiredIndex]<PQ[left]) desiredIndex=left;
    if(right<=sz && PQ[desiredIndex]<PQ[right]) desiredIndex=right;

    if(index!=desiredIndex){
        swap(PQ[index],PQ[desiredIndex]);
        shiftDown(desiredIndex);
    }
}

int getMax(){
    return PQ[0];
}

void insert(int element){
    PQ[++sz] = element;
    shiftUp(sz);
}

int extractMax(){
    int result = PQ[0];
    PQ[0]=PQ[sz];
    sz-=1;
    shiftDown(0);
    return result;
}

void remove(int index){
    PQ[index] = getMax()+1;
    shiftUp(index);
    extractMax();
}

void changePriority(int index,int newPriority){
    int oldPriority = PQ[index];
    PQ[index] = newPriority;
    if(newPriority>oldPriority){
        shiftUp(index);
    }else{
        shiftDown(index);
    }
}

int main(){
    return 0;
}
