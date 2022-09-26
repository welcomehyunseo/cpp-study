# Track Memory

## What is "delete" operation
* New operator is used for dynamic memory allocation which puts variables on heap memory.
* Delete operator or Delete [ ] operator
* Deallocates memory from heap.
* Pointer to object is not destroyed, value or memory block pointed by pointer is destroyed.

## Make New and Delete operator
```c++
#include<iostream>
#include<stdlib.h>
 
using namespace std;
class student
{
    string name;
    int age;
public:
    student()
    {
        cout<< "Constructor is called\n" ;
    }
    student(string name, int age)
    {
        this->name = name;
        this->age = age;
    }
    void display()
    {
        cout<< "Name:" << name << endl;
        cout<< "Age:" << age << endl;
    }
    void * operator new(size_t size)
    {
        cout<< "Overloading new operator with size: " << size << endl;
        void * p = ::operator new(size);
        //void * p = malloc(size); will also work fine
     
        return p;
    }
 
    void operator delete(void * p)
    {
        cout<< "Overloading delete operator " << endl;
        free(p);
    }
};
 
int main()
{
    student * p = new student("Yash", 24);
 
    p->display();
    delete p;
}
```

* New and Delete operators can be overloaded globally or they can be overloaded for specific classes.
* These operators are overloaded using member function for a class

## What is "void*" 
* A void * can be converted to any other pointer type without an explicit cast.
* void vs void*, They're not really the same thing, but pointers can be converted to void *.

## References
* [Track MEMORY ALLOCATIONS the Easy Way in C++](https://www.youtube.com/watch?v=sLlGEUO_EGE&t=381s)
* [delete keyword in C++](https://www.geeksforgeeks.org/delete-in-c/)
* [Overloading New and Delete operator in c++](https://www.geeksforgeeks.org/overloading-new-delete-operator-c/)