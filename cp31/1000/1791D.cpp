#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        // input
        int n;
        cin >> n;
        string s = "";
        for(int i=0;i<n;i++){
            char ch ;
            cin >> ch;
            s += ch;
        }
        // cout << s << endl;

        //
        unordered_map<char,int> mpp;
        // for(auto it : s){
        //     mpp[it]++;
        // }
        // long long t_Distinct = mpp.size();
        // mpp.clear();

        vector<long long> prefix(n);
        for(int i=0;i<n;i++){
            mpp[s[i]]++;
            prefix[i] = mpp.size();
        }

        mpp.clear();
        vector<long long> suffix(n);
        for(int i=n-1;i>=0;i--){
            mpp[s[i]]++;
            suffix[i] = mpp.size();
        }

        long long ans = 0;
        for(int i=1;i<n;i++){
            ans = max(ans , prefix[i-1] + suffix[i]);
        }

        // output
        cout << ans << "\n";
    }
    return 0;
}