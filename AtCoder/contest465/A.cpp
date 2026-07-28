#include <bits/stdc++.h>
using namespace std;
int main(){
    int A, B;
    cin >> A >> B;
    int num = 2.0/3.0;
    if(A > B*num){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
    return 0;
}