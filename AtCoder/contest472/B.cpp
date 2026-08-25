#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    
    vector<int> prefix(n,0);
    prefix[0] = nums[0];
    for(int i=1;i<n;i++){
        prefix[i] = prefix[i-1] + nums[i];
    }

    int mini = INT_MAX;
    for(int i=0;i<n;i++){
        int len = abs(2*prefix[i] - prefix[n-1]);
        mini = min(mini, len);
    }

    cout << mini << endl;

    return 0;
}