#include <bits/stdc++.h>
#define ll long long 
#define MOD 1000000007
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<string> arr;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        for(auto it : arr[i]){
            it = tolower(it);
        }
    }
    unordered_map<string,int> mpp;
    int maxFreq = -1;
    for(auto it : arr){
        mpp[it]++;
        maxFreq = max(maxFreq, mpp[it]);
    }
    cout << maxFreq << endl;
    return 0;
}