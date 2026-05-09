#include <bits/stdc++.h>
using namespace std;
vector<int> dfs(vector<vector<int>>& edges, int V){
    vector<vector<int>> adjLis(V);
    for(auto it : edges){
        int u = it[0];
        int v = it[1];
        adjLis[u].push_back(v);
    }
    vector<int> ans;
    stack<int> st;
    vector<bool> vis(V,false);
    st.push(0);
    vis[0] = true;
    while(!st.empty()){
        int node = st.top();
        st.pop();
        ans.push_back(node);
        for(auto it : adjLis[node]){
            if(!vis[it]){
                vis[it] = true;
                st.push(it);
            }
        }
    }
    // reverse(ans.begin(),ans.end());
    return ans;
}
int main(){
    int V;
    int edgeCnt;
    cin >> V >> edgeCnt;
    vector<vector<int>> edges;
    for(int i=0;i<edgeCnt;i++){
        int a,b;
        cin >> a >> b;
        edges.push_back({a,b});
    }
    vector<int> ans = dfs(edges,V);
    for(int i=0;i<V;i++){
        cout << ans[i] << " ";
    }
    return 0;
}