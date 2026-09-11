#include<bits/stdc++.h>
using namespace std;
long long func(vector<vector<pair<int,int>>>& adjLis, int n, int s){
    //
    // queue<pair<int,int>> q;
    vector<int> mnD(n+1,INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({0,s});
    mnD[s]= 0;
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        int d = it.first;
        int u = it.second;
        if(mnD[u] < d){
            continue;
        }
        for(auto ngh : adjLis[u]){
            int v = ngh.first;
            int wt = ngh.second;
            if(mnD[u] + wt <= mnD[v]){
                mnD[v] = mnD[u] + wt;
                pq.push({mnD[v],v});
            }
        }
    }

    long long dist_sum = 0;
    for(int i=0;i<=n;i++){
        if(mnD[i] == INT_MAX || i == s){
            continue;
        } else{
            dist_sum += mnD[i];
        }
    }

    return dist_sum;
}
int main(){
    // Input
    int n,m,s;
    cin >> n >> m >> s;
    vector<vector<pair<int,int>>> adjLis(n);
    for(int i=0;i<m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        adjLis[u].push_back({v,w});
        adjLis[v].push_back({u,w});
    }

    //
    long long ans = func(adjLis,n,s);

    // Output
    cout << ans << "\n";
    return 0;
}