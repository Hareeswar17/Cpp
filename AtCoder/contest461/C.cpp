#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Node{
    ll val;
    int col, id;
    bool operator<(const Node& other) const{
        return val < other.val;
    }
};

int main() {
    int N,K,M;
    cin >> N >> K >> M;

    vector<vector<ll>> g(N+1);

    for(int i=0;i<N;i++){
        int c;
        ll v;
        cin >> c >> v;
        g[c].push_back(v);
    }

    for(int i=1;i<=N;i++)
        sort(g[i].begin(),g[i].end(),greater<ll>());

    auto calc = [&](ll add){
        priority_queue<Node> pq;

        for(int i=1;i<=N;i++){
            if(!g[i].empty())
                pq.push({g[i][0]+add,i,0});
        }

        ll score = 0;
        int colors = 0;

        for(int t=0;t<K;t++){
            Node cur = pq.top();
            pq.pop();

            score += cur.val;
            if(cur.id==0) colors++;

            int nxt = cur.id+1;
            if(nxt<(int)g[cur.col].size()){
                pq.push({g[cur.col][nxt],cur.col,nxt});
            }
        }

        return pair<ll,int>(score,colors);
    };

    ll L = -400000000000000LL;
    ll R = 400000000000000LL;

    while(L<R){
        ll mid = L + (R-L)/2;
        auto [sc,cnt] = calc(mid);

        if(cnt>=M) R=mid;
        else L=mid+1;
    }

    ll x = L;
    auto [sc,cnt] = calc(x);

    cout << sc - x*(ll)M << "\n";
    return 0;
}