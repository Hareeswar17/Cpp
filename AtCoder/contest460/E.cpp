#include <bits/stdc++.h>
using namespace std;
using u64 = unsigned long long;
const u64 MOD = 998244353;
const int dMax = 19;
vector<u64> p10(dMax+1);
int main(){
    int t;
    cin >> t;
    p10[0] = 1;
    for(int i=1;i<=dMax;i++){
        p10[i] = p10[i-1]*10;
    }
    while(t--){
        u64 n,m;
        cin >> n >> m;
        // We need to find number of pairs where (to_string(x) + to_string(y)) = (x + y)%M -> both x and y less than N
        // return no of pairs with modulo
        u64 ans = 0;
        for(int d=1;d<=dMax;d++){
            u64 maxi = min(p10[d],n+1);
            u64 mini = p10[d-1];
            if(mini >= maxi){
                break;
            }
            u64 cntb = (maxi - mini)%MOD;
            u64 g = gcd(p10[d]-1,m);
            u64 x = m/(g);
            u64 cnta = (n/x)%MOD;

            ans += cnta*cntb;
            ans = ans%MOD;
        }
        cout << ans << endl;
    }
    return 0;
}