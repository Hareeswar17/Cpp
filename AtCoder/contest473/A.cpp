#include <bits/stdc++.h>
using namespace std;
int main(){
    //Input
    int n;
    cin >> n;
    vector<int> nums(n);
    int sum = 0;
    for(int i=0;i<n;i++){
        cin >> nums[i];
        if(i > n/2){
            sum += nums[i];
        }
    }
    //Output
    cout << sum << "\n";

    return 0;
}