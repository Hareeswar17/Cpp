#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        // input
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        for(int i=0;i<n;i++){
            cin >> b[i];
        }

        //
        unordered_map<int,int> mpp1;
        unordered_map<int,int> mpp2;
        for(int i=0;i<n;i++){
            int j = i;
            while(j < n && a[i] == a[j]){
                j++;
            }
            int len = j-i;
            mpp1[a[i]] = max(mpp1[a[i]], len);
            i = j-1;
        }

        for(int i=0;i<n;i++){
            int j = i;
            while(j < n && b[i] == b[j]){
                j++;
            }
            int len = j-i;
            mpp2[b[i]] = max(mpp2[b[i]], len);
            i=j-1;
        }

        int ans = 0;
        for(auto it : mpp1){
            int len = it.second;
            ans = max(ans, len + mpp2[it.first]);
        }
        for(auto it : mpp2){
            int len = it.second;
            ans = max(ans, len);
        }
        
        // output
        cout << ans << "\n";
    }
    return 0;
}