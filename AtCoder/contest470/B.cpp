#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> C(n);
    for(int i=0;i<n;i++){
        cin >> C[i];
    }
    unordered_map<int,int> mpp;
    int maxi = INT_MIN;
    for(auto it : C){
        mpp[it]++;
        maxi = max(maxi, mpp[it]);
    }
    cout << n - maxi << endl;
    return 0;
}