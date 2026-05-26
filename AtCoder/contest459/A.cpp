#include <bits/stdc++.h>
using namespace std;
int main(){
    int X;
    cin >> X;
    string s = "HelloWorld";
    string ans = "";
    for(int i=0;i<10;i++){
        if(i == X-1){
            continue;
        }
        else{
            ans += s[i];
        }
    }
    cout << ans << " ";
    return 0;
}