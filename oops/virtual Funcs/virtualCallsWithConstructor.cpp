#include <bits/stdc++.h>
using namespace std;
class Base{
    public:
    Base(){
        show();
    }
    virtual void show(){
        cout << "Base class printing.." << endl;
    }
};
class Derived : public Base{
    public:
    void show() override {
        cout << "Derived class printing.." << endl;
    }
};
int main(){
    Derived obj; // This will print base because when it was derived class wasn't even constructed yet 
    obj.show();
    return 0;
}