#include <bits/stdc++.h>
using namespace std;
class Animal{
    public:
    virtual ~Animal(){
        cout << "Base class named Animal is destructing" << endl;
    }
    virtual void sound(){
        cout << "Animal sound" << endl;
    }
};
class Dog : public Animal{
    public:
    ~Dog(){
        cout << "Derived class named Dog is destructing" << endl;
    }
};
class Cat : public Animal{
    public:
    void sound() override{
        cout << "Meow Meow" << endl;
    }
};
int main(){
    // Dog obj;
    // Virtual destructor — critical when dealing with polymorphism. If you delete a derived class object through a base class pointer and the base destructor isn't virtual, only the base part gets destroyed, causing a memory/resource leak in the derived part.
    // obj.~Dog(); -> This is dangerous beacuse it destructs both Derived and Base because that's how it was programmed 
    Animal *ptr = new Dog();
    delete ptr; // Without virtual Ptr this is still pointing to animal so animal is destructed, because at this point it asks whether should i destroy this as an Animal or Dog, A virtual destructor tells to use runtime polymorphism
    Animal *ptr1 = new Cat();
    ptr->sound();

    return 0;
}