#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    vector<string> ans(n);
    ll cal = 0;
    for(int i=0;i<n;i++){
        if(i-m >= 0){
            if(ans[i-m] == "Yes"){
                cal -= nums[i-m];
            }
        }
        if(cal + nums[i] <= k){
            cal += nums[i];
            ans[i] = "Yes";
        }
        else{
            ans[i] = "No";
        }

    }

    for(int i=0;i<n;i++){
        cout << ans[i] << endl;
    }

    return 0;
}