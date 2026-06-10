#include <bits/stdc++.h>
using namespace std;
class segTree{
private:
    vector<long long> seg, lazy;

public:
    segTree(int n){
        seg.resize(4*n+1,0);
        lazy.resize(4*n+1,0);
    }

    void build(int idx,int low,int high,vector<int>& nums){
        if(low==high){
            seg[idx]=nums[low];
            return;
        }

        int mid=(low+high)/2;

        build(2*idx+1,low,mid,nums);
        build(2*idx+2,mid+1,high,nums);

        seg[idx]=seg[2*idx+1]+seg[2*idx+2];
    }

    void propagate(int idx,int low,int high){

        if(lazy[idx]==0) return;

        seg[idx]+=(high-low+1)*lazy[idx];

        if(low!=high){
            lazy[2*idx+1]+=lazy[idx];
            lazy[2*idx+2]+=lazy[idx];
        }

        lazy[idx]=0;
    }

    void update(int idx,int low,int high,
                int l,int r,long long val){

        propagate(idx,low,high);

        // no overlap
        if(high<l || low>r) return;

        // complete overlap
        if(low>=l && high<=r){

            lazy[idx]+=val;
            propagate(idx,low,high);
            return;
        }

        int mid=(low+high)/2;

        update(2*idx+1,low,mid,l,r,val);
        update(2*idx+2,mid+1,high,l,r,val);

        seg[idx]=seg[2*idx+1]+seg[2*idx+2];
    }

    long long query(int idx,int low,int high,
                    int l,int r){

        propagate(idx,low,high);

        // no overlap
        if(high<l || low>r) return 0;

        // complete overlap
        if(low>=l && high<=r) return seg[idx];

        int mid=(low+high)/2;

        long long left=
            query(2*idx+1,low,mid,l,r);

        long long right=
            query(2*idx+2,mid+1,high,l,r);

        return left+right;
    }
};