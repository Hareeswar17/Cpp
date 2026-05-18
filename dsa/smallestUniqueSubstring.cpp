#define ll long long int
#define MOD 100000007
#define radix 31
#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
    bool func(vector<int>& nums, int len){
        int n = nums.size();
        ll maxWt = 1;
        for(int i=0;i<len;i++){
            maxWt = (maxWt*radix)%MOD;
        }
        ll currHash;
        

    }
};
int main(){
    vector<int> nums;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        nums.push_back(a);
    }
    Solution s;
    int ans = 0;
    int left = 1;
    int right = n;
    while(left <= right){
        int mid = (right-left)/2 + left;
        if(s.func(nums,mid)){
            ans = mid;
            right = mid-1;
        }
        else{
            left = mid;
        }
    }
    cout << ans << endl;
    return 0;
}