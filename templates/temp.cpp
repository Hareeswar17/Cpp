#include <bits/stdc++.h>
using namespace std;
class student{
    public:
    string name;
    int age;
    student(string s, int n){ 
        // this is constructor overloading we have different ways of initialising constructors we can also initialize the constructor with same name but with different paramters or no parameters at all.
        name = s;
        age = n;
    } 
};
int main(){
    student s1("Hareeswar",21);
    cout << s1.name << endl;
    cout << s1.age << endl;
    return 0;
}