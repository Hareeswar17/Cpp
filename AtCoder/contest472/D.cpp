#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m, k;
    cin >> n >> m >> k;

    vector<string> str;
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        str.push_back(s);
    }

    vector<int> r(n,0);
    vector<int> c(m,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(str[i][j] == '#'){
                r[i] = 1;
                c[j] = 1;
            }
        }
    }

    vector<vector<int>> d(n, vector<int>(m,-1));
    queue<pair<int,int>> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(r[i] == 0 && c[j] == 0){ // Row and Col which don't have any bomb we initialize from there 
                q.push({i,j});
                d[i][j] = 0;
            }
        }
    }

    int ans = 0;
    vector<int> dRow = {-1,0,1,0};
    vector<int> dCol = {0,1,0,-1};
    while(!q.empty()){
        auto front = q.front();
        q.pop();
        int u = front.first;
        int v = front.second;
        if(d[u][v] <= k){
            ans++;
        }   
        for(int i=0;i<4;i++){
            int nRow = dRow[i] + u;
            int nCol = dCol[i] + v;
            if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && str[nRow][nCol] == '.' && d[nRow][nCol] == -1){
                d[nRow][nCol] = d[u][v] + 1;
                q.push({nRow, nCol});
            }
        }
    }

    cout << ans << endl;

    return 0;
}