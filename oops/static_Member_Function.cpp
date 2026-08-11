#include <bits/stdc++.h>
using namespace std;
class Student{
    public:
    static int count; // static member this one belongs to the class itself not to individual objects
    Student(){
        count++;
    }
    void enroll(){
        cout << "This student got enrolled" << endl;
    }
    static int getCount(){
        return count;
    }
};
int Student::count = 0;
int main(){
    Student s1;
    // cout << s1.count << endl; // Ofcourse we can access the count but its not the point here we wanted whole count plus it doesn't belong to s1 or another class it belongs to class itself
    Student s2;
    Student s3;
    // cout << Student::count << endl;
    cout << Student::getCount() << endl;
    return 0;
}