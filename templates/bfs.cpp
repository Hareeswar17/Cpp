#include <bits/stdc++.h>
using namespace std;
vector<int> bfs(vector<vector<int>> &edges, int V)
{
    vector<vector<int>> adjLis(V);
    for (auto it : edges)
    {
        int u = it[0];
        int v = it[1];
        adjLis[u].push_back(v);
    }
    vector<int> ans;
    queue<int> q;
    vector<bool> vis(V, false);
    q.push(0);
    vis[0] = true;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for (auto it : adjLis[node])
        {
            if (!vis[it])
            {
                q.push(it);
                vis[it] = true;
            }
        }
    }
    return ans;
}
int main()
{
    vector<vector<int>> edges;
    int V;
    int edgeCount;
    cin >> V >> edgeCount;
    for (int i = 0; i < edgeCount; i++)
    {
        int a;
        int b;
        cin >> a >> b;
        edges.push_back({a, b});
    }
    vector<int> ans = bfs(edges, V);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
        // cout << endl;
    }
    return 0;
}