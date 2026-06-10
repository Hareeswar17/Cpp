#include <bits/stdc++.h>
using namespace std;
class matrix{
    public:
    vector<int> dRow = {-1,0,1,0};
    vector<int> dCol = {0,1,0,-1};
    // vector<int> dRow = {-1,-1,-1,0,0,1,1,1}; for linking diagonals also
    // vector<int> dCol = {-1,0,1,-1,1,-1,0,1};
    int node(int r, int c, int m){
        return r*m + c;
        // r = node/m;
        // c = node%m; reverse mapping
    }
    void traverse(vector<vector<int>>& mat, vector<vector<int>>& adjLis){
        int n = mat.size();
        int m = mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == 0){
                    continue; // This line is used to bypass the blocked cells if dont want remove this if()
                }
                int u = node(i,j,m);
                for(int k=0;k<4;k++){
                    int nRow = dRow[k] + i;
                    int nCol = dCol[k] + j;
                    if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m){
                        int v = node(nRow,nCol,m);
                        adjLis[u].push_back(v);
                        adjLis[v].push_back(u);
                    }
                }
            }
        }
    }
};
int main(){
    return 0;
}