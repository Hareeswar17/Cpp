#include <bits/stdc++.h>
using namespace std;
class segTree{
    private:
    vector<int> seg;
    public:
    segTree(int n){ // constructor
        seg.resize(4*n+1);
    }
    // build
    void build(int idx, int low, int high, vector<int>& nums){
        if(low == high){
            seg[idx] = nums[low];
            return;
        }
        int mid = (high-low)/2 + low;
        // idx -> {2*idx+1, 2*idx+2} => thumb rule for left and right indexes
        build(2*idx+1,low,mid,nums);
        build(2*idx+2,mid+1,high,nums);
        seg[idx] = min(seg[2*idx+1],seg[2*idx+2]);
        // this for minium range query if we want this for max query
        // seg[idx] = max(seg[2*idx+1],seg[2*idx+2]); -> this line shuold be used
    }
    // query
    int query(int idx, int low, int high, int l, int r){
        // partial overlap -> 
        // no overlap -> [low,high][l,r] , [l,r][low,high]
        // complete overlap -> [low,[l,r],high]
        if(high < l || r < low){ // no overlap
            return INT_MAX;
        }
        if(low >= l && high <= r){ // complete overlap
            return seg[idx];
        }
        int mid = (high-low)/2 + low;
        int left = query(2*idx+1,low,mid,l,r);
        int right = query(2*idx+2,mid+1,high,l,r);
        return seg[idx] = min(left,right);
        // return seg[idx] = max(left,right) -> for max range query
    }
    // update
    void update(int idx, int low, int high, int i, int val){
        if(low == high){
            seg[idx] = val;
        }
        int mid = (high-low)/2 + low;
        if(i <= mid){
            update(2*idx+1,low,mid,i,val);
        }
        else{
            update(2*idx+2,mid+1,high,i,val);
        }
        seg[idx] = min(seg[2*idx+1],seg[2*idx+2]);
        // Above code is for minimum point update 
        // seg[idx] = max(seg[2*idx+1],seg[2*idx+2])
    }
};
int main(){
    /* 
       This tempalte is for min-max && point updates on static size array whose contents may change with each query   
    */
    int n;
    cin >> n;
    vector<int> nums;
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    vector<int> ans;
    segTree s1(n); // initialized object
    s1.build(0,0,n-1,nums);
    int q;
    cin >> q;
    while(q--){
        int type, l, r, l1, r1;
        cin >> type >> l >> r;
        if(type == 1){
            int mini = s1.query(0,0,n-1,l,r);
            ans.push_back(mini);
        }
        else{
            s1.update(0,0,n-1,l1,r1);
        }
    }
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << endl;
    }
    return 0;
}