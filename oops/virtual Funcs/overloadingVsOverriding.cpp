#include <bits/stdc++.h>
using namespace std;
class A{
    public:
    void show(int amount){
        cout << amount << endl;
    }
    void show(double amount){
        cout << amount << endl;
    }
    // This is called overloading at compile time it knows which function to call 
    // Function overloading :- A function having same name as already existing function but differnt parameters in the same class at the compile time it automatically calls the correct functions
};
class Base{
    public:
    virtual void show(){
        cout << "Base class" << endl;
    }
};
class Derived : public Base{
    public:
    void show() override{
        cout << "Derived class" << endl;
    }
    // Function overriding :- A derived class provides its own implementation of a function already defined in the function
};
int main(){
    Derived obj;
    obj.show();
    A a;
    a.show(10);
    a.show(10.266);
    return 0;
}