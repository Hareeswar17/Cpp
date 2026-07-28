#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n, r;
    cin >> n >> r;
    ll ans = 1;
    r = min(r, n-r);
    for(int i=1;i<=r;i++){
        ans = ans*(n-r+i)/i;
    }
    cout << ans << endl;
    return 0;
}
// Time complexity: O(r)
// Space Complexity: O(1)