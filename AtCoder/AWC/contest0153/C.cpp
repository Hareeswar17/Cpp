#include <bits/stdc++.h>
using namespace std;
int main(){
    // Input
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    vector<int> diff(n+1,0);
    for(int i=0;i<m;i++){
        int l,r;
        cin >> l >> r;
        diff[l]++;
        diff[r+1]--;
    }

    //
    long long water = 0;
    int ans = 0;
    for(int i=0;i<n;i++){
        water += diff[i];
        if(water + nums[i] >= k){
            ans++;
        }
    }

    // Output
    cout << ans << "\n";
    return 0;
}