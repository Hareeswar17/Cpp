#include <bits/stdc++.h>
using namespace std;
class Student{
    int age;
    public:
    void setAge(int age){
        this->age = age;
        // "this->age" refers to the objects data member
    }
    void display(){
        cout << "Age = " << age << endl;
    }
};
int main(){
    Student s;
    s.setAge(20);
    s.display();
    return 0;
}