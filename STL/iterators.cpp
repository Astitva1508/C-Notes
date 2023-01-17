#include <iostream>
#include <iterator>
#include<vector>
using namespace std;

void autoKeywordAndRangeBasedLoops(){
    // In Containers , we can directly iterate over the elements i.e. we dont need to use index to access the element. We directly iterate over its value

    vector<int> numbers={1,2,3,4,5};
    for(int number:numbers){
        cout<<number<<endl;
    }

    // In Range base loop , however , number variable gets the copy of the actual value.Hence, we cannot alter the values of a container. To alter the values , use C++ references
    for (int & number:numbers){
        cout<<number<<endl;
    }

    // Auto keyword dynamically assumes the data type
}

int main(){
    autoKeywordAndRangeBasedLoops();
    return 0;
}

void iteratorsTheory()
{

    // Unlike Vectors , most of the containers in STL dont have indexing.Hence we can't access the value at the ith index using map[i].Hence arises the need for iterators

    // Iterators point to the elements of the container
    // .begin points to the first element of the container
    // .end points to the position next to the last element in the container.It does not point to a accesible location in the container

    // Declaration of an iterator
    vector<int> v;
    vector<int>::iterator it = v.begin(); // This iterator can point to the vector storing integers

    // We can iterate any container using iterators
    for (it = v.begin(); it != v.end(); it++)
    {
        cout << *it << endl;
    }
    // it++ and it+1 are two different things
    // it++ points to the next iterator and not to the next memory location(unlike pointers)
    // it++ moves to the next iterator while it+1 moves to the next location
    // Iterators in case of maps and sets are of discontinous nature

}