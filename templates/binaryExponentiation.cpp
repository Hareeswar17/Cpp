#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1000000007;
ll binaryExpo(ll n, ll pow){
    ll res = 1;
    while(pow > 0){
        if(pow%2 == 1){
            res = (res*n)%MOD;
        }
        n = (n*n)%MOD;
        pow /= 2; // pow >>= 1 means right shit bits by one position in on=ther terms dividing with 2^k 
    }
    return res;
}
int main(){
    // Input
    ll n, pow;
    cin >> n >> pow;

    // 
    ll ans = binaryExpo(n,pow);
    // Even though we have pow(a,b) which calculates a^b why do we still use loops or fast exponentiation because pow() is for floating point calculation for cal's like pow(2.0,3.5) our loops or fast expo won't be able to caluculate that value precisely even though we use 3,10 The arguments are integers, but the available overloads can lead to a floating-point result.
    // For exact integer calculations we don't want to relay on pow() it is not adivisable to use pow for int, long long 
    // Best used when calculating double values or working with floating points 
    // Output
    cout << ans << '\n';

    return 0;
}