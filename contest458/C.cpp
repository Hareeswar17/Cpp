#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    int n = s.length();
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(s[i] == 'C'){
            if(i >= 1 && i < n-1){
                int left = i;
                int right = n-1-i;
                cnt += min(left,right);
            }
        }
    }
    cout << cnt;
    return 0;
}

// SMBCPROGRAMMINGCONTEST
