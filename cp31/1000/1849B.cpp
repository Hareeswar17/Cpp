#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    int t;
    cin >> t;
    while(t--){
        // Input
        int n, k;
        cin >> n >> k;
        vector<pair<ll,int>> a;
        for(int i=0;i<n;i++){
            ll num;
            cin >> num;
            int rem = num%k;
            if(rem == 0){
                rem = k;
            }
            a.push_back({rem,i+1});
        }

        sort(a.begin(), a.end(), [](auto a, auto b){
            if(a.first != b.first){
                return a.first > b.first;
            } else{
                return a.second < b.second;
            }
        });

        // Output
        for(auto it : a){
            cout << it.second << " ";
        }
        cout << '\n';
    }
    return 0;
}