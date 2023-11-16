// Virutal function can be defined in the base class as well.
// Objects of abstract class types(
// i.e classes which contain pure virtual functions) cannot be created.
// )

// Most common use case with pointers and classes is to use pointers of base class to access an object of derived class

// How to call constructor of the base class in the derived class?
// Ans : Use the constructor of the base class in the initialization list of the derived class constructor

// Sequence of constructor calls in case of inheritance
// 1. Constructor of the base class is called
// 2. Constructor of the member objects is called
// 3. Constructor of the derived class is called

// Sequence of destructor calls in case of inheritance
// 1. Destructor of the derived class is called 
// 2. Destructor of the member objects is called
// 3. Destructor of the base class is called


// Pointer of the base class pointing to the derived class object ->possible only when the derived class is publicly inheriting the base class
// Pointer of the derived class pointing to the base class object -> not possible

// What is the difference between pointer of base class pointing to object of derived class and pointer of derived class pointing to object of derived class ?
// Methods only present in the derived class but not in the base class cannot be called by the base class pointer
// If we don't use the virtual function, then base class pointer used to point to derived class object cannot revoke any of the methods/properties of the derived class

// User defined constructor overrides the default constructor, i.e the default constructor no longer exists

// Benefits of each pillar
// Encapsulation : Data security
// Abstraction : Hiding the implementation details
// Polymorphism : Flexibility
// Inheritance : Code reusability

// Compile Time Polymorphism :(Method Overloading) Function Overloading, Operator Overloading
// Run Time Polymorphism : (Method Overriding) Function Overriding

// SOLID Priniciples : to create flexibile and maintainable software designs
// Single Responsibilty Prinicple
// Open/Closed Principle (OCP)
// Liskov Substitution Principle(LSP)
// Interface Segregation Principle(ISP)
// Dependency Inversion Principle(DIP)

// Difference between Abstract Class And Inheritance
// Abstract Class : allows incusion of concrete methods along with pure virtual methods. A class can inherit only one abstract class. It contains at least one pure virtual function and it cannot be instantiated.
// Interface : provides a contract for methods that the implementing class must define. A class can implement multiple interfaces. It contains pure virtual functions only.

// Keywords used in the function declaration
// virtual : the function can be overridden in the derived class
// static : the function can be called without creating an object of the class
// friend : the function can access the private members of the class
// inline : the function is expanded in the code where it is called
// explicit : the function cannot be used for implicit type conversion
// volatile : the function can be modified by something outside the scope of the program
// noexcept : the function will not throw an exception
// constexpr : the function can be evaluated at compile time and it it a constant expression
// override : the function is overriding a virtual function in the base class
// final : the function cannot be overridden in the derived class

// const : function does not modify the state of the object it is called on. For a const object, only const member functions can be called.
// explicit : prevents impilict conversions for a constructor 


// Types of Constructors
// Default Constructor : no parameters
// Parameterized Constructor : parameters
// Copy Constructor : copy of an object of the same class
// Move Constructor : rvalue reference to an object of the same class

// Solution to the dimaond problem : using virtual inheritance which ensures that only a single instance of the common base class is inherited by the derived class
// When a base class is declared as virtual in the inheritance hierarchy, it ensures that only one instance of that base class exists, regardless of how many times it's inherited within the hierarchy

// Types of Inheritance:
// Single Inheritance : one base class and one derived class
// Multiple Inheritance : one derived class and multiple base classes
// Multilevel Inheritance : one derived class and one base class and the base class is derived from another base class
// Hierarchical Inheritance : one base class and multiple derived classes
// Hybrid Inheritance : combination of multiple inheritance and multilevel inheritance

