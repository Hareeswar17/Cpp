/* #include <bits/stdc++.h>
using namespace std;
int main(){
    // input
    int n, k;
    cin >> n >> k;
    vector<int> nums(k+1);
    for(int i=0;i<n;i++){
        int c;
        cin >>c;
        nums[c]++;
    }

    int maxi = -1;
    for(int i=0;i<n;i++){
        maxi = max(maxi, nums[i]);
    }
    int cnt = 0;
    for(auto it : nums){
        if(it == maxi){
            cnt++;
        }
    }

    // output
    cout << cnt << "\n";
    return 0;
} */
#include <bits/stdc++.h>
using namespace std;
/* int main(){
    // input
    int n, k;
    cin >> n >> k;
    vector<int> nums(k+1);
    for(int i=0;i<n;i++){
        int c;
        cin >> c;
        nums[c]++;
    }
    if(k == 1){
        cout << nums[1] << "\n";
        return 0;
    }
    int maxi = -1;
    for(int i=1;i<=k;i++){
        maxi = max(maxi, nums[i]);
    }
    int cnt = 0;
    for(auto it : nums){ // Failing here because we never removed extra 0 which was initialzed due to k+1 hence when maxi <= 1 that zero was also counted 
        if(it + 1 >= maxi){
            cnt++;
        }
    }

    // output
    cout << cnt << "\n";
    return 0;
} */

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> nums(k+1,0);
    for(int i=0;i<n;i++){
        int c;
        cin >> c;
        nums[c]++;
    }
    int mx = *max_element(nums.begin()+1, nums.end());
    int ans = 0;
    for(int i=1;i<=k;i++){
        if(nums[i] >= mx-1){
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}