#include<bits/stdc++.h>
using namespace std;
template <typename T>
T maximum(T a, T b){
    return (a > b) ? a : b;
}
int main(){
    cout << maximum(3,4) << endl;
    cout << maximum(3.7,4.8) << endl;
    cout << maximum('A','C') << endl;
    return 0;
}