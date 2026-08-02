#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    if(n == 1){
        if(s[0] == 'x'){
            cout << 1 << endl;
            return 0;
        }
        else{
            cout << 0 << endl;
            return 0;
        }
    }
    if(s[0] == 'x' && s[1] == 'x'){
        ans += 1;
    }
    if(s[n-1] == 'x' && s[n-2] == 'x'){
        ans += 1;
    }
    for(int i=1;i<n-1;i++){
        if(s[i] == 'x' && s[i+1] == 'x' && s[i-1] == 'x'){
            ans += 1;
        }
    }
    cout << ans << endl;
    return 0;
}