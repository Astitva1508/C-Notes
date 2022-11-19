#include<iostream>
#include<memory>
using namespace std;

class PointerDemonstration{
    public:
    PointerDemonstration(){
        cout<<"Constructor Invoked"<<endl;
    }
    ~PointerDemonstration(){
        cout<<"Destructor Invoked"<<endl;
    }
};

void smartPointers(){
    // A void pointer is a container or a wrapper for a raw pointer and they deallocate memory automatically. 
    // Types of smart pointers: Unique , Shared and weak
    // Need to include memory to use smart pointers

    //Creation of a Unique Pointer
    unique_ptr<int>unqPtr = make_unique<int>(25);
    //unique_ptr<int>unqPtr creates a unique pointer with the name of unqPtr and to store the address of some integer and then the make_unique<int> method is used to create a unique pointer of type int.The value in the argument is the one that is stored at the address stored in uniquePtr
    //Unique Pointers cannot be shared.i.e Two unique pointers cannot store the same address
    // unique_ptr<int>unqPtr2 = unqPtr; //throws an error
    //We can however move the ownership of a uniqie pointer and in this case the previous owner becomes NULL Pointer and if we try to access the value stored at the previous owner , we get a NULL_POINTER_EXCEPTION
    unique_ptr<int>unqPtr2 = move(unqPtr);
    cout<<*unqPtr2<<endl;

    //unique Pointer is destroyed at the end of the scope (Remember the example of classes given by Ma'am. We use class as an example because we can see when it is destroyed coz the destructor function is invoked.(For other types , this is not true))
    unique_ptr<PointerDemonstration> unqPtr1 = make_unique<PointerDemonstration>();

    //Shared Pointers
    //It can be shared between multiple owners and we can assign one raw pointer to multiple owners
    shared_ptr<PointerDemonstration>shrPtr = make_shared<PointerDemonstration>();
    shared_ptr<PointerDemonstration>shrPtr2 = shrPtr; //Does not throw an error
    //Since we can share shared pointer , it has the count of all of its owners.(i.e all the references to the pointer)
    cout<<"Count of the shared pointer "<<shrPtr.use_count()<<endl;
    {
        shared_ptr<PointerDemonstration> shrPtr3 = shrPtr; // Does not throw an error
        cout << "Count of the shared pointer " << shrPtr.use_count() << endl;
    }
    cout << "Count of the shared pointer " << shrPtr.use_count() << endl;

    //The memory stored in the shared pointer is automatically deallocated when there are no pointers pointing to that memory location. Every owner of the memory allocation is destroyed at the end of the scope. and when no owners are left , the memory location also is destroyed.

    cout<<"Weak Pointers"<<endl;
    //Weak Pointers
    //If we assign a memory location (stored by a shared pointer or in general) to a weak pointer , it is not going to increase the owners of the memory location i.e. We use weak pointers to observe(locate) objects in memory but a weak pointer will not keep that object alive(Mtlb agar kahi aur wo memory location nahi stored hai , to wo memory location deallocate ho jayegi aur bss uska address rh jaega bacha weak pointer me.)

    weak_ptr<int>weakPtr;
    {
        shared_ptr<int>shrPtrForIllustration = make_shared<int>(25);
        weakPtr = shrPtrForIllustration;
    }
    
}

int main()
{
    smartPointers();
    return 0;
}

void PointerUses(){
    // Uses of Pointers
    // 1. To pass values by reference to a function
    // 2. Return multiple values from a function
    // 3. Pointers with Arrays
    // 4. Pointers for Dynamic Memory Allocation
    // 5. Pointers with OOPs to use pointer of base class to access an object of derived class
};

void pointerToAPointer()
{
    int anInteger = 4;
    int *pointerToAnInteger = &anInteger;
    int **pointerToAPointer = &pointerToAnInteger;
    cout << "The Value of an integer is " << anInteger << endl;
    cout << "The Value of an integer using dereference is " << *pointerToAnInteger << endl;
    cout << "The Address of an integer is " << &anInteger << endl;
    cout << "The Address of an integer using pointer is " << pointerToAnInteger << endl;
    cout << "The Address of the Pointer is " << &pointerToAnInteger << endl;
    cout << "The Address of the Pointer using another pointer is " << pointerToAPointer << endl;
    cout << "The Value stored at the pointer using dereference is " << *pointerToAPointer << endl;
    cout << "The Value of an integer using dereferencing the pointer to the pointer is " << **pointerToAPointer << endl;
    cout << "The address of the pointer to the pointer is" << &pointerToAPointer << endl;
}

void voidPointer()
{
    // Void Pointer can hold the address of any other data type.However we cannot directly dereference it
    void *ptrVoid;
    int n = 5;
    ptrVoid = &n;
    cout << ptrVoid << endl;
    // cout<<*ptrVoid<<endl; throws an error

    // Casting poniters
    int *ptrInt = (int *)ptrVoid;

    // This is the way to dereference a void pointer
    cout << *ptrInt << endl;

    // Hence in order to dereference a void pointer , we must know the data type whose address it stores
};

void arrayPointer()
{
    // The name of the array behaves like a pointer
    int arr[5] = {1, 3, 5, 7, 9};
    cout << arr << endl;
    cout << &arr[0] << endl; // Same output as the above line

    // Square Brackets behave as a dereference operator
    cout << arr[2] << endl;
    cout << *(arr + 2) << endl; // Same Output as Above Line

    // Passing Array to Functions
    //  function(int array[],int size)

    // Dont access memory locations that do not belong to you
}

void multipleReturnUsingPointer(int *firstReference, int *secondReference)
{
    // To return multiple values from a function , we need to pass those values to the function as reference (in the function parameters)

    // Lets say we want to return 1 and 2 as the output
    *firstReference = 1;
    *secondReference = 2;

    // Passing a parameter using a reference is to pass the address of a variable as a parameter
}

void dynamicArrays()
{
    // Accessing elements of the array is very fast.In a LinkedList for Example, where the elements are not stored in continous blocks of memory , each element stores a pointer to the previous and the next element. This means everytime we need to access some element of the array , we need to traverse through all the previous elements.
    // However , Deletion or Insertion of an element in the middle of an array is difficult while maintaining the continousness
    // Biggest disadvantage of using array is constant size.
    // Dynamic Memory can be created when needed and deleted when its no longer in use

    int size;
    cin >> size;
    int arr[size];
    // This throws of an error because we need to allocate memory at the compile time and not at the run time. I dont know why it's working

    // in Dynamic Memory Allocation , we do :
    int *myArray = new int[size];
    // This expression allocates memory needed to store 5(if size==5) integers and assigns the first address to myArray pointer
    // Each time you allocate memory when you need it, you deallocate it when you don't need it.
    delete[] myArray; // Because we have allocated a block of memory so we used square brackets to deallocate that. Now in the next line we make sure that the pointer myArray does not point to anything.
    myArray = NULL;
}

void multiDimensionalDynamicArrays()
{
    // MultiDimensional Array is nothing but a number of linear arrays stacked together.
    // So in order to create it , we need the address of the first element(viz same as the address of the linear array)of all the linear arrays which we will store in another linear array
    // And finally  we will store the address of this array (viz stores the address of the first element of all the linear arrays ) inside another pointer to a pointer
    int rows, columns;
    cout << "Enter the Rows , Columns : ";
    cin >> rows >> columns;
    int **addressOfArrayStoringAddressofArrays = new int *[rows];
    // What the above line of code does is it creates memory space corresponding to the number of rows given to store address of integers and then it stores the address of this allocated space to a pointer to a pointer.
    for (int i = 0; i < rows; i++)
    {
        *(addressOfArrayStoringAddressofArrays + i) = new int[columns];
        // We need to store the address of the first element of the arrays inside this array;
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cin >> addressOfArrayStoringAddressofArrays[i][j];
        }
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout << *(*(addressOfArrayStoringAddressofArrays + i) + j) << " ";
        }
        cout << endl;
    }

    // Now how do we deallocate the allocated memory? While allocating the memory , firstly we created a pointer to a pointer and stored the address of the address array in it.
    // However while deleting the array we will follow the opposite approach coz if we once delete the pointer to a pointer , then we have no way to access the dynamic multidimensional arrays.

    for (int i = 0; i < rows; i++)
    {
        delete[] * (addressOfArrayStoringAddressofArrays + i);
    }
    delete[] addressOfArrayStoringAddressofArrays;
    addressOfArrayStoringAddressofArrays = NULL;
}

int dummyFunctionToShowFunctionPointers(int a)
{
    return a;
}

void functionPointers()
{
    // Function Pointers are used to store the address of a function
    // The name of a function gives it's address e.g

    // This is a function pointer
    int (*funcPointer)(int) = dummyFunctionToShowFunctionPointers;

    // Calling a Function using Function Pointers. There are two ways:
    cout << (*funcPointer)(5) << endl;
    cout << funcPointer(5) << endl; // This line of code implies that passing parameters to a function parameter is the same as dereferencing it and then invoking it.

    // All the three lines return the same output
    cout << funcPointer << endl;
    cout << dummyFunctionToShowFunctionPointers << endl;
    cout << &dummyFunctionToShowFunctionPointers << endl;

    // Function Pointers can be passed as parameters to other functions and then the function can be used as a callback
}

int sum(int a, int b)
{
    return a + b;
}

void functionPointerToShowCallback(int a, int b, int (*funcPtr)(int, int))
{
    cout << funcPtr(a, b) << endl;

    // Run this function in the main using one of the following codes:
    //  Approach One  :
    //  functionPointerToShowCallback(4,5,sum);
    // Approach Two
    // int (*funcPtr)(int , int) =sum;;
    // functionPointerToShowCallback(4, 5, funcPtr);
}