#include <bits/stdc++.h>
using namespace std;
// class Student{
//     const int age;
//     public:
//     Student(int a) : age(a){} // This is one way of initializing constructor
//     // This should be declared like this if not const we can declare normally\
//     Student(int a){age = a;}
// };
class Student{
    int age;
    public:
    Student(int num){
        age = num;
        cout << "This student age " << age << endl;
    }
    Student(const Student& other){ // copy constructor
        age = other.age;
    }
    ~Student(){
        cout << "Destructing this student data" << endl;
    }
};
int main(){
    Student s1(20);
    // Student s2 = s1;

    return 0;
}