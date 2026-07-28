#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 100000007
class FenwickTree{
    public:
    int n;
    vector<ll> bit;
    FenwickTree(int size){
        n = size;
        bit.assign(n+1,0);
    }
    void update(int idx, int val){
        idx++;
        while(idx <= n){
            bit[idx] += val;
            idx += idx & (-idx);
        }
    }
    ll query(int idx){
        idx++;
        ll sum = 0;
        while(idx > 0){
            sum += bit[idx];
            idx -= idx & (-idx);
        }
        return sum;
    }

};
int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    FenwickTree ft(n);
    for(int i=0;i<n;i++){
        ft.update(i,nums[i]);
    }
    // we built bit array 
    // Now if we want to find the range like [l,r]
    // now we do ft.query(r) - ft.query(l);

}