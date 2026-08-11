#include <bits/stdc++.h>
using namespace std;
class Array{
    public:
    int* arr;
    Array() {
        arr = new int[100];
    }
    ~Array(){
        delete[] arr;
    }
};
int main(){
    Array a;
    // Because default destructor doesnot delete dynamically allocated memory without this we can cause memory leaks
    return 0;
}