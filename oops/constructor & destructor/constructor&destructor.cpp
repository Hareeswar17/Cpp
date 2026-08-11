#include <bits/stdc++.h>
using namespace std;
class Base{
    public:
    Base(){
        cout << "Base class constructor is initialized." << endl;
    }
    ~Base(){
        cout << "Base class destructor is initialized." << endl;
    }
};
class Derived : public Base{
    public:
    Derived(){
        cout << "Derived class constructor is initialized." << endl;
    }
    ~Derived(){
        cout << "Derived class destructor is initialized." << endl;
    }
};
int main(){
    // Base b;
    Derived d;
    return 0;
}
// When Construction happens 
// Base -> Derived {because first base must exist in order for derived class to execute something..}
// when Destructor happens
// Derived -> Base {Initially Derived is deleted after that it moves to base class..}