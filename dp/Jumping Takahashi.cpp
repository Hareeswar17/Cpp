#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool func(int target, int idx, vector<int>& nums, vector<vector<int>>& dp){
    if(idx == nums.size()){
        if(target == 0){
            return true;
        } else{
            return false;
        }
    }
    if(target < 0){
        return false;
    }
    if(dp[idx][target] != -1){
        return dp[idx][target];
    }

    bool curr = func(target-nums[idx],idx+2,nums,dp);
    bool adj = func(target-nums[idx+1],idx+2,nums,dp);

    return dp[idx][target] = curr || adj;
}
bool jumping(int target, vector<int>& nums){
    int len = nums.size();

    vector<vector<int>> dp(len, vector<int>(target+1,-1));
    return func(target,0,nums,dp);
}
int main(){
    // Input
    int n, x;
    cin >> n >> x;
    vector<int> nums;
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        nums.push_back(a);
        nums.push_back(b);
    }
    int len = nums.size();

    //
    // bool ans = jumping(x,nums);
    // Output
    // if(ans){
    //     cout << "Yes" << '\n';
    // } else{
    //     cout << "No" << '\n';
    // }

    return 0;
}