#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
class expo{
    public:
    ll pow(int a, int b){
        if(b == 0){
            return 1;
        }
        ll half = pow(a,b/2);
        ll res = half*half;
        if(b%2){
            res = res*a;
        }
        return res;
    }
};
int main(){
    int a, b;
    cin >> a >> b;
    // We nee to find the a^b so we use binary exponentiation
    expo e;
    cout << e.pow(a,b) << endl;
    return 0;
}