#include <iostream>
#include <vector>
using namespace std;


// Difference between a dynamic array and a vector and when to use what
// Since a vector is a class => it completely hides memory management from the programmer/ It also provides useful functionalities , is tested and error-free

// A Dynamic Array is an old-fashioned way to do the same thing
// Almost never use Dynamic Arrays in place of vectors

// Use Static Arrays for faster accessing and when the size of the array won't change

int main(){
    vector<int> numbers; // Need not specify the size of the vector at initialization
    return 0;
}

// Disadvatages of Static Arrays is that you cannot change its size

// Disadvantage of Dynamic Arrays is that the background process of changing its size requires additional execution time.The process is 
// [ 
    // Allocate space for a bigger/smaller array
    // Copy all the elements from the old array to the new one
    // Delete the old array
// ]

// STL Vectors have all the benefits of dynamic arrays with much less work and errors
// Vector elements are stored in contiguos memory (unlike e.g Linked List)
// It has the ability to resize itself automatically when element is inserted or deleted

// Iterators are special functions that point to some important locations in your vector.
// Since two most important locations in a vector are its beginning and end , we have two iterators begin and end

void vectorBasics(vector<int> numbers)
{
    // Inserting Elements into the vector
    numbers.push_back(0);
    for (int i = 1; i <= 10; i++)
    {
        if (i % 2 == 0)
            numbers.push_back(i);
    }

    // Traversing Over a Vector
    // Way 1
    for (int number : numbers)
    {
        cout << number << endl;
    }

    // Way 2 (Using an Iterator)
    for (auto it = numbers.begin(); it != numbers.end(); it++)
    {
        // cout<<it<<endl;      // throws an error
        // cout<<*it<<endl;     // the value of the element
        // cout<<&it<<endl;     // the address of the iterator
        // cout<<&(*it)<<endl;  // the address of the element = iterator
    }
    // What does auto do ?
    // It checks which type the numbers.begin() will return and then automatically assign that type to the it iterator
    // You cannot print the iterator in C++
}

void vectorFunctionalities(vector<int> numbers)
{
    for (int i = 1; i <= 10; i++)
    {
        if (i % 2 == 0)
            numbers.push_back(i);
    }

    // Performing Arithmetic Operations on Vectors
    auto it = numbers.begin();
    cout << *(it + 2) << endl;
    // Both are constant iterators and the value stored inside the iterator cannot be changes

    // Other Important Iterators
    auto it1 = numbers.cbegin();
    auto it2 = numbers.cend();
    // Need for constant iterators : When we only need to do read only tasks

    cout << numbers.size() << endl;
    cout << numbers.max_size() << endl; // Maximum number of elements that we can add to the vector
    cout << numbers.capacity() << endl; // It tells you how many elements we can add to the vector before resizing it
    cout << numbers.empty() << endl;
    cout << numbers[0] << endl;
    cout << numbers.at(0) << endl;
    cout << numbers.front() << endl; // The first element of the vector
    cout << numbers.back() << endl;  // The last element of the vector
    numbers.resize(4);               // changes the size of the array
    numbers.clear();                 // empties the array

    // Inserting element at a specific position inside the vector
    numbers.insert(numbers.begin() + 5, 12);
    // Removing element from a specific position inside the vector
    numbers.erase(numbers.begin() + 5);
    numbers.pop_back(); // erases an element from the back of the array
}