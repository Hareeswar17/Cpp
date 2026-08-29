#include <bits/stdc++.h>
using namespace std;
int main(){
    // Input
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }

    unordered_map<int,int> mpp;
    for(auto it : nums){
        mpp[it]++;
    }
    int sum = 0;
    for(auto it : mpp){
        int rem = (it.second)%2;
        if(rem == 0){
            continue;
        } else{
            sum += (rem*it.first);
        }
    }

    // output
    cout << sum << "\n";
    return 0;
}