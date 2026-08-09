#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, q;
    cin >> n >> q;
    vector<int> nums(n,0);
    vector<vector<int>> queries;
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int idx;
            cin >> idx;
            queries.push_back({type, idx});
        }
        else{
            queries.push_back({type});
        }
    }
    int ans = 0;
    set<int> mpp;
    for(auto it : queries){
        int type = it[0];
        if(type == 1){
            int idx = it[1]-1;
            ans ^= nums[idx]^(nums[idx]+1);
            nums[idx]++;
            if(nums[idx] == 1){
                mpp.insert(idx);
            }
        }
        else{
            for(auto pos = mpp.begin(); pos != mpp.end();){
                int idx = *pos;
                ans ^= nums[idx]^(nums[idx]-1);
                nums[idx]--;
                if(nums[idx] == 0){
                    pos = mpp.erase(pos);
                }
                else{
                    pos++;
                }
                // pos++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}