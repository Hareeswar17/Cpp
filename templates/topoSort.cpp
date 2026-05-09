#include <bits/stdc++.h>
using namespace std;
void dfs(int node, vector<vector<int>>& adjLis, stack<int>& st, vector<bool>& vis){
    vis[node] = true;
    for(auto it : adjLis[node]){
        if(!vis[it]){
            dfs(it,adjLis,st,vis);
        }
    }
    st.push(node);
}
vector<int> topoSort(vector<vector<int>>& edges, int V){
    vector<vector<int>> adjLis(V);
    for(auto it : edges){
        int u = it[0];
        int v = it[1];
        adjLis[u].push_back(v);
    }
    stack<int> st;
    vector<bool> vis(V,false);
    for(int i=0;i<V;i++){
        if(!vis[i]){
            dfs(i,adjLis,st,vis);
        }
    }
    vector<int> ans;
    while(!st.empty()){
        int top = st.top();
        st.pop();
        ans.push_back(top);
    }
    return ans;
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
    vector<int> ans = topoSort(edges,V);
    for(int i=0;i<V;i++){
        cout << ans[i] << " ";
    }
    return 0;
}