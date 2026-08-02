#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> cand;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        cand.push_back({a,b});
    }
    int u = -1, v = -1;
    int x = cand[0][0], y = cand[0][1];
    // case-1
    for(int i=1;i<m;i++){
        if(cand[i][0] != x && cand[i][1] != x){
            u = i;
            break;
        }
    }
    for(int i=1;i<m;i++){
        if(cand[i][0] != y && cand[i][1] != y){
            v = i;
            break;
        }
    }
    if(u == -1 && v == -1){
        cout << 2*n-3 << endl;
        return 0;
    }
    // case-2
    if(u == -1 || v == -1){
        cout << n-1 << endl;
        return 0;
    }
    // case-3;
    set<pair<int,int>> ways;
    int p1 = cand[u][0];
    int p2 = cand[u][1];
    int p3 = cand[v][0];
    int p4 = cand[v][1];
    ways.insert({min(x,p1), max(x,p1)});
    ways.insert({min(x,p2), max(x,p2)});
    ways.insert({min(y,p3), max(y,p3)});
    ways.insert({min(y,p4), max(y,p4)});
    int ans = 0;
    for(auto it : ways){
        int c1 = it.first;
        int c2 = it.second;
        bool flag = true;
        for(int i=0;i<m;i++){
            int c3 = cand[i][0], c4 = cand[i][1];
            if(c1 != c3 && c1 != c4 && c2 != c3 && c2 != c4){
                flag = false;
                break;
            }
        }
        if(flag){
            ans += 1;
        }
    }
    cout << ans << endl;
    return 0;
}