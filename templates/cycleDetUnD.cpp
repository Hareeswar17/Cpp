#include <bits/stdc++.h> 
using namespace std;
bool dfs(int node, int parent, vector<vector<int>>& adjLis, vector<bool>& vis){
    vis[node] = true;
    for(auto it : adjLis[node]){
        if(!vis[it]){
            if(dfs(it,node,adjLis,vis)){
                return true;
            }
        }
        else if(it != parent){
            return true;
        }
    }
    return false;
}
bool cycleDetection(vector<vector<int>>& edges, int V){
    vector<vector<int>> adjLis(V);
    for(auto it : edges){
        adjLis[it[0]].push_back(it[1]);
    }
    vector<bool> vis(V,false);
    for(int i=0;i<V;i++){
        if(!vis[i]){
            if(dfs(i,-1,adjLis,vis)){
                return true;
            }
        }
    }
    return false;
}
int main(){
    int V, edgeCnt;
    cin >> V >> edgeCnt;
    vector<vector<int>> edges;
    for(int i=0;i<edgeCnt;i++){
        int a,b;
        cin >> a >> b;
        edges.push_back({a,b});
    }
    bool ans = cycleDetection(edges,V);
    cout << ans << endl;
    return 0;
}