#define ll long long int
#define MOD 10000000007
#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
    ll hashValue(string s, int RADIX, ll l){
        ll ans = 0;
        ll factor = 1;
        for(ll i=l-1;i>=0;i--){
            ans = (ans + ((s[i]-'a')*factor)%MOD)%MOD;
            factor = (factor*RADIX)%MOD;
        }
        return ans%MOD;
    }
    int func(string& s1, string& s2){
        ll n = s1.length();
        ll m = s2.length();
        if(n < m){
            return -1;
        }
        int RADIX = 31;
        ll maxWt = 1;
        for(ll i=0;i<m;i++){
            maxWt = (maxWt*RADIX)%MOD;
        }
        ll hashS2 = hashValue(s2,RADIX,m);
        ll hashS1 = 0;
        for(ll i=0;i<=n-m;i++){
            if(i == 0){
                hashS1 = hashValue(s1,RADIX,m);
            }
            else{
                hashS1 = (hashS1*RADIX)%MOD;
                hashS1 = (hashS1 - ((s1[i - 1] - 'a') * maxWt)%MOD + MOD) % MOD;
                hashS1 =(hashS1 + (s1[i + m - 1] - 'a'))%MOD;
            }
            if(hashS1 == hashS2){
                for(ll j=0;j<m;j++){
                    if(s1[i+j] != s2[j]){
                        break;
                    }
                    if(j == m-1){
                        return i;
                    }
                }
            }
        }
        return -1;
    }

};
int main(){
    string str1, str2;
    cin >>  str1 >> str2;
    Solution s;
    int ans = s.func(str1,str2);
    cout << ans << "\n";
    return 0;
}