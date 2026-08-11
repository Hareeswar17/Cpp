#include <bits/stdc++.h>
using namespace std;
class Base{
    private:
    virtual void show(){
        cout << "Base class" << endl;
    }
    public:
    void call(){
        show();
    }
};
class Derived : public Base{
    private:
    void show() override{
        cout << "Derived" << endl;
    }
};
int main(){
    Derived obj;
    obj.call();
    return 0;
}