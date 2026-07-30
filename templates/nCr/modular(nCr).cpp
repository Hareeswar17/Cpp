#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;
class nCr{
    public:
    ll factorial(int num){
        ll ans = 1;
        for(int i=2;i<=num;i++){
            ans = (ans*i)%MOD;
        }
        return (ans)%MOD;
    }
    ll pow(int a, int b){
        if(b == 0){
            return 1;
        }
        ll half = pow(a,b/2);
        ll ans = (half*half)%MOD;
        if(b%2){
            ans = ans*a;
        }
        return (ans)%MOD;
    }
    ll modnCr(int n, int r){
        if(r < 0 || r > n){
            return 0;
        }
        // We need to find n! -> a & (r!*(n-r)!) -> b
        // (a/b)%M => a*(b^-1)%M => a*(modular inverse b of mod M)%M
        // We are going to use fermat's little theorem to find b inverse mod M
        ll a = factorial(n);
        ll b = (factorial(r)*factorial(n-r))%MOD;
        ll num = pow(b,MOD-2)%MOD;
        return (a*num)%MOD;
    }

};
int main(){
    int n, r;
    cin >> n >> r;
    nCr x;
    cout << x.modnCr(n,r) << endl;
    return 0;
}