#include <bits/stdc++.h>
using namespace std;
void func(){
    int n;
    cin >> n;
    int sum = 0;
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        sum += a;
    }
    if(sum%4 == 0){
        cout << "Yes" << "\n";
    } else{
        cout << "No" << "\n";
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        func();
    }
    return 0;
}