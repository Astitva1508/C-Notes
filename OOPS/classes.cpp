#include<iostream>
using std::string;
using std::cout;
using std::endl;

//class IEmployee or
class AbstractEmployee{
    //This class serves as a contract
    //It has a rule which says that whichever class decides to sign this contract needs to provide implementation for a method called askForPromotion
    //We can make this obligatory by making it a pure virtual function
    virtual void askForPromotion()=0;
    // A virtual function is a member function which is declared within a base class and is re-defined (overridden) by a derived class.pure virtual function is not defined at all in the base class but set to zero
};

class Employee:AbstractEmployee{
    private:
    int Age;
    string Name;
    int yearsServed;
    bool isPromoted;
    public:
    Employee(int age,string name){
        Age=age;
        Name=name;
    };
    void setName(string name){
        Name=name;
    }
    string getName(){
        return Name;
    }
    void setAge(int age){
        if(age<18)return;
        Age=age;
    }
    void askForPromotion(){
        if(Age>45 && yearsServed>5) isPromoted=true;
    }
    virtual void Work(){
        cout<<Name<<" is doing the work"<<endl;
    }
};

class Developer:public Employee{
    public:
        string favProgrammingLanguage;
        Developer(int age, string name,string lang):Employee(age , name){
            favProgrammingLanguage=lang;
        }
        void Work(){
            cout<<getName()<<" is writing the code in "<<favProgrammingLanguage<<endl;
        }
};

void PillarsOfOOPS(){
    //1. Encapsulation
    //2. Abstraction
    //3. Inheritance
    //4. Polymorphism

    //Encapsulations is bundling data and methods that operate on it.Idea behind this is to preveny anyone outside the class to directly access the data and change it.
    //Others access and modify the data not directly but through getters and 
    //We can provide special rules (for getters and setters) to interact with the data.(e.g. setAge())

    //Abstraction is hiding complex things behind a procedure that make those things look simple(user knows the output but does not know how we arrived at it ).Class acts as an interface between logic and output
    //For C++ Classes , Abstraction implemented using AbstractClasses.
    //Consider the case of promotion of an empoyee

    //Inheritance
    //Whenever a child class inherits from the parent class having its own constructor, you need to provide a constructor for the child class as well(it also does not have a default constructor)
    // Developer d(25,"Suresh","Python");

    //Polymorphism means ability of an object or a method to have many forms
    //Its most common use case is when a parent class reference is used to refer to an object of a child class
    Employee E(20,"Dhruv");
    Developer D(20, "Astitva", "Javascript");
    // E.Work();
    // D.Work();

    Employee *employeePtr = &D;
    employeePtr->Work(); //This doesnt work
    //However if we make the function Work virtual in the base class , it works as it should be
    //Adding the virtual keyword checks if there is implementation for the virtual function in the derived class or not.If the answer is yes,that instance is triggered

}


int main(){
    PillarsOfOOPS();
    return 0;
}

void classAndAccessSpecifiers(){
    // Everything inside a class is private by default
    // For a class : Its private and protected properties are accesible only inside the class and not outside.
    // Private properties can only be accessed inside the class and are inaccesible to the child class but the protected properties can be accessed by the child class

    // For a Child Class
        // which is publicly inheriting parent:
            // public of parent is public for child
            // protected of parent is protected for child
            // private of parent is inaccesible for child
        // which is protectingtly inheriting parent:
            // public,protected of parent is protected for child
            // private of parent is inaccessible for child
        // which is privately inheriting parent:
            // public,protected of parent is private for child
            // private of parent is inaccesible for child
}

void Constructor()
{
    // A special type of function which is invoked each time when an object of a class is created
    // Default constructor is a constructor which is automatically generated by the compiler in case we don't create our own constructor

    // Rules for creating a constructor:
    // It does not have a return type
    // Same name as the class which it belongs to
    // Must be public.(in certain situations , it can be private.Not for now)

    // When we create a constructor , we lose the default constructor that was automatically gneerated.To fix this error, either make your own default constructor or by triggering your constructor at time of creation of object as shown
    // Employee Ram = Employee(24, "Ram"); // Or
    // Employee Shyam(25, "Shyam");

};