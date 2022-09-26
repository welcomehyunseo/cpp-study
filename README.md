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

## Heap vs Stack
### Layout
* Stack - stores local variables
* Heap - dynamic memory for programmer to allocate
### Stack
* Allocation happens in the function call stack.
* It’s a temporary memory allocation.
* Whenever the function call is over, the memory for the variables is de-allocated.
* Memory allocation and de-allocation is faster as compared to Heap-memory allocation.
* Stack-memory has less storage space as compared to Heap-memory.

```c++
int main()
{
   // All these variables get memory
   // allocated on stack
   int a;
   int b[10];
   int n = 20;
   int c[n];
}
```

### Is the stack automatically deallocation garbage collection?
The allocation and deallocation for stack memory is automatically done. 
The stack is not garbage collected.
The stack allocated for a given method call is freed when the method returns.

### Heap
* The memory is allocated during the execution of instructions written by programmers.
* To allocate heap memory in C++, use the keyword "new".
* To free heap memory, use the key word "delete".

## What is unique_ptr
* In C++ std::unique_ptr (pronounced “unique pointer”) is one of the “smart pointer” classes available in the Standard Library.
* std::unique_ptr is a smart pointer that owns and manages another object through a pointer and disposes of that object when the unique_ptr goes out of scope.

## What is the use of operator keyword?
* This gives the operator more than one meaning, or "overloads" it. (like redefined new operator)

## Where is a "std::string" allocated on stack or heap?
* The string object itself is stored on the stack but it points to memory that is on the heap.

## References
* [Track MEMORY ALLOCATIONS the Easy Way in C++](https://www.youtube.com/watch?v=sLlGEUO_EGE&t=381s)
* [delete keyword in C++](https://www.geeksforgeeks.org/delete-in-c/)
* [Overloading New and Delete operator in c++](https://www.geeksforgeeks.org/overloading-new-delete-operator-c/)
* [Stack vs Heap Memory Allocation](https://www.geeksforgeeks.org/stack-vs-heap-memory-allocation/)
* [Stack and Heap Memory](https://courses.engr.illinois.edu/cs225/sp2020/resources/stack-heap/)
* [std::unique_ptr](https://en.cppreference.com/w/cpp/memory/unique_ptr)