#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> groupAllDiv(vector<int>& nums){
    int n = nums.size();
    vector<vector<int>> ans;
    // {3,4,6,9,2} -> {{2,4,6},{3,9}}
    vector<int> mpp(1e5+1,0);
    int maxi = *max_element(nums.begin(),nums.end());
    for(int i=0;i<n;i++){
        mpp[nums[i]]++;
    }
    for(int i=1;i<=maxi;i++){ // O(maxi)
        vector<int> temp;
        if(mpp[i] == 0){
            continue;
        }
        temp.push_back(i);
        for(int j=i*2;j<=maxi;j+=i){ // O(maxi/i) -> for simgle loop 
            // This commented line is if we want to perform any operations like replacing elements with smallest of them to get min sum or something which is asked in qiestion 
            // Currently i want to group same divisors based on smallest divisor
            // if(mpp[i] == 0){
            //     continue;
            // }
            // mpp[i] += mpp[j];
            // mpp[j] = 0;
            if(mpp[j] != 0){
                temp.push_back(j);
                mpp[j] = 0;
            }
        }
        ans.push_back(temp);
    }
    return ans;
}
int main(){
    int n; // n <= 1e5
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    vector<vector<int>> ans = groupAllDiv(arr);
    for(auto it : ans){
        for(int i=0;i<it.size();i++){
            cout << it[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// Time Complexity is O(n + maxi*log(maxi));