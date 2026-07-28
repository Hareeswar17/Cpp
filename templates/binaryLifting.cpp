#include <bits/stdc++.h>
using namespace std;
const int LOG = 20;
class Solution{
    public:
    vector<vector<int>> up;
    void treeAncestor(vector<int>& nums){
        int n = nums.size();
        up.assign(n, vector<int>(LOG,-1));
        for(int i=0;i<n;i++){
            up[i][0] = nums[i];
        }
        for(int k=1;k<LOG;k++){
            for(int i=0;i<n;i++){
                if(up[i][k-1] != -1){
                    up[i][k] = up[up[i][k-1]][k-1];
                }
            }
        }
    }
    int getAncestor(int node, int k){
        for(int j=0;j<LOG;j++){
            if(node == -1){
                break;
            }
            if(k & (1<<j)){
                node = up[node][j];
            }
        }
        return node;
    }

};
int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    Solution s;
    s.treeAncestor(nums);
    int q;
    cin >> q;
    while(q--){
        int node, k;
        cin >> node;
        cin >> k;
        cout << s.getAncestor(node,k) << endl;
    }
    return 0;
}