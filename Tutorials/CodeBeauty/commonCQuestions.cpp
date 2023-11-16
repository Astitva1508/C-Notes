// Inline Functions : 
// unncessary function overhead
// compiler reduces the function call with the body of the function 

// Stack Applications : 
// Function Calls
// Undo/Redo
// Backtracking Applications
// Expression Evaluation in compilers

// Queuss Applications :
// BFS
// CPU Sheduling


// Difference between push_back() and emplace_back() : 
// push_back() : copies the value of the element to the end of the vector
// emplace_back() : constructs the element at the end of the vector
// emplace_back saves overhead for copying. it is more efficient than push_back() and useful when the element passed cannot be copied

// SOLID Principles

// static : makes a single instance of the variable for all the instances/function calls

// Features of Friend Functions
// A friend function in spite of not being a member function of a class has the privilege to access the private and protected data of a class.
// non-member function or ordinary function of a class, which is declared as a friend using the keyword “friend” inside the class.
// The keyword “friend” is placed only in the function declaration of the friend function and not in the function definition or call.
// is called like an ordinary function.It cannot be called using the object name and dot operator. However, it may accept the object as an argument whose value it wants to access.
// can be declared in any section of the class i.e.public or private or protected.

// Smart Pointers : container around raw pointer that automatically deallocated memory
// Unique Pointers : cannot be shared
// Shared Pointers : can be shared and has count of references
// Weak Pointers : assigning to a weak ptr does not increase the number of owners. Used to observe objects in memory but does not keep it alive.

// OpenMP : parallel programming language 
// MPI : Message Passing Interface