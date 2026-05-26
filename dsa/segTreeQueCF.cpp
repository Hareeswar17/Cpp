#include <bits/stdc++.h>
using namespace std;
struct info {
    int open, close, full;
    info(int _open, int _close, int _full){
        open = _open;
        close = _close;
        full = _full;
    }
};
info merge(info left, info right){
    int match = min(left.open, right.close);
    info res(0,0,0);
    res.full = left.full + right.full + match;
    res.open = left.open + right.open - match;
    res.close = left.close + right.close - match;
    return res;

}
void build(int idx, int low, int high, string& s, vector<info>& seg){
    if(low == high){
        if(s[low] == '()'){
            seg[idx] = info(1,0,0);
        }
        else{
            seg[idx] = info(0,1,0);
        }
        return;
    }
    int mid = (high-low)/2 + low;
    build(2*idx+1,low,mid,s,seg);
    build(2*idx+2,mid+1,high,s,seg);
    seg[idx] = merge(seg[2*idx+1], seg[2*idx+2]);
}
info query(int idx, int low, int high, int l, int r, vector<info>& seg){
    if(low > r || high < l){
        return info(0,0,0);
    }
    if(l <= low && high <= r){
        return seg[idx];
    }
    int mid = (high-low)/2 + low;
    info left = query(2*idx+1,low,mid,l,r,seg);
    info right = query(2*idx+2,mid+1,high,l,r,seg);
    return merge(left,right);
}
void solve(){
    string s;
    cin >> s;
    int n = s.length();
    vector<info> seg(4*n);
    build(0,0,n-1,s,seg);
    int q;
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        // l--; r-- => if queries are 1 indexed
        info ans = query(0,0,n-1,l,r,seg);
        cout << 2*ans.full << endl;
    }
}
int main(){
    solve();
    return 0;
}