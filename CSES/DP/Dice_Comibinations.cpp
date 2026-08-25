#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define ll long long

class Solution{
    public:
    int func(int target,vector<int>& nums, vector<int>& dp){
        if(target < 0){
            return 0;
        }
        if(target == 0){
            return 1;
        }
        if(dp[target] != -1){
            return dp[target];
        }
        ll ways = 0;
        for(int i=1;i<=6;i++){
            ways += func(target-i,nums,dp);
            ways %= MOD;
        }
        return dp[target] = ways;
    }
    int noOfWays(int n){
        vector<int> nums = {1,2,3,4,5,6};
        vector<int> dp(n+1,-1);
        return func(n,nums,dp)%MOD;
    }
};
int main(){
    int n;
    cin >> n;
    Solution obj;
    cout << obj.noOfWays(n) << endl;
    return 0;
}