#define ll long long
#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
    const ll RADIX_1 = 31;
    const ll MOD_1 = 1000000007;
    const ll RADIX_2 = 53;
    const ll MOD_2 = 1000000033;
    pair<ll,ll> hashPair(string s, ll m){
        ll hash1 = 0;
        ll hash2 = 0;
        ll factor1 = 1;
        ll factor2 = 1;
        for(ll i=m-1;i>=0;i--){
            hash1 = (hash1 + ((s[i]-'a')*factor1))%MOD_1;
            factor1 = (factor1*RADIX_1)%MOD_1;
            hash2 = (hash2 + ((s[i]-'a')*factor2))%MOD_2;
            factor2 = (factor2*RADIX_2)%MOD_2;
        }
        return {hash1%MOD_1 , hash2%MOD_2};
    }
    int func(string& s1, string& s2){
        int n = s1.length();
        int m = s2.length();
        if(n < m){
            return -1;
        }
        int maxWt1 = 1;
        int maxWt2 = 1;
        for(int i=1;i<=m;i++){
            maxWt1 = (maxWt1*RADIX_1)%MOD_1;
            maxWt2 = (maxWt2*RADIX_2)%MOD_2;
        }
        pair<ll,ll> hashS2 = hashPair(s2,m);
        pair<ll,ll> hashS1 = {0,0};
        for(int i=0;i<=n-m;i++){
            if(i == 0){
                hashS1 = hashPair(s1,m);
            }
            else{
                hashS1.first = (hashS1.first*RADIX_1)%MOD_1;
                hashS1.first = (hashS1.first - ((s1[i-1]-'a')*maxWt1)%MOD_1 + MOD_1)%MOD_1;
                hashS1.first = (hashS1.first + (s1[i+m-1]-'a'))%MOD_1;

                hashS1.second = (hashS1.second*RADIX_2)%MOD_2;
                hashS1.second = (hashS1.second - ((s1[i-1]-'a')*maxWt2)%MOD_2 + MOD_2)%MOD_2;
                hashS1.second = (hashS1.second + (s1[i+m-1]-'a'))%MOD_2;
            }
            if(hashS1.first == hashS2.first && hashS1.second == hashS2.second){
                return i;
            }
        }
        return -1;
    }
};
int main(){
    string str1, str2;
    cin >> str1 >> str2;
    Solution s;
    int ans = s.func(str1,str2);
    cout << ans << endl;
    return 0;
}