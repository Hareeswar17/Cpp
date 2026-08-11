#include <bits/stdc++.h>
using namespace std;
class Animal{ // A class having atleast one pure virtual function is called abstract class
    public:
    // Virtual function does not mean we should always override sometime we don't want to provide any implementation for base class
    virtual void sound() = 0; // This is called pure virtual function
};
class Dog : public Animal{
    public:
    void sound() override{
        cout << "Bark" << endl; 
    }
};
int main(){
    Dog d;
    d.sound();
    return 0;
}