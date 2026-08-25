#include <bits/stdc++.h>
using namespace std;
int main(){
    int q;
    cin >> q;
    while(q--){
        string s;
        cin >> s;
        int n = s.length();
        int ones = 0;
        int zeros = 0;
        for(int i=0;i<n;i++){
            if(s[i] == '0'){
                zeros++;
            }
            else{
                ones++;
            }
        }

        int ans = 0;
        int neededOnes = 0;
        int neededZeros = 0;
        for(int i=0;i<n;i++){
            if(s[i] == '0'){
                neededOnes++;
            }
            else{
                neededZeros++;
            }
            if(neededOnes > ones || neededZeros > zeros){
                ans = n - (i);
                break;
            }
        }

        cout << ans << endl;

    }
    return 0;
}