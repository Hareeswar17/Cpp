#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define bgn(x) (x).begin()
#define nd(x) (x).end()
#define ll long long int
#define MOD 1000000007
#define pb push_back
#define e erase

class Solution{
    public:
    int removeDuplicates(vector<int>& nums){
        int n = nums.size();
        // [1,1,2,2,2,3,4,4,4,5,5]
        // [[1,2,3,4,5],1,2,2,4,4,5]
        int idx = 0;
        for(int j=1;j<n;j++){
            if(nums[idx] != nums[j]){
                idx++;
                nums[idx] = nums[j];
            }
        }
        return idx+1;
    }
};
int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    Solution s;
    int k = s.removeDuplicates(nums);
    for(int i=0;i<k;i++){
        cout << nums[i] << " ";
    }
    return 0;
}