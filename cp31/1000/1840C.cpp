#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    int t;
    cin >> t;
    while(t--){
        // input
        int n, k, q;
        cin >> n >> k >> q;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        ll ans = 0;
        int len = 0;
        for(int i=0;i<n;i++){
            if(a[i] <= q){
                len++;
            }else{
                if(len >= k){
                    ll cnt = len-k+1;
                    ans += cnt*(cnt+1)/2;
                }
                len = 0;
            }
        }
        if(len >= k){
            ll cnt = len-k+1;
            ans += cnt*(cnt+1)/2;
        }

        // output
        cout << ans << "\n";
    }
    return 0;
}