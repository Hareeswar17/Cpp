#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
    vector<int> dRow = {-1,-1,1,1};
    vector<int> dCol = {-1,1,-1,1};
    int func(vector<vector<int>>& mat){
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<vector<int>>> prefix(205,vector<vector<int>>(205,vector<int>(205,0)));
        for(int val=0;val<=200;val++){
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    int add = 0;
                    if(mat[i][j] > val){
                        add = 1;
                    }
                    int up = 0;
                    int left = 0;
                    int dia = 0;
                    if(i > 0){
                        up = prefix[val][i-1][j];
                    }
                    if(j > 0){
                        left = prefix[val][i][j-1];
                    }
                    if(i > 0 && j > 0){
                        dia = prefix[val][i-1][j-1];
                    }
                    prefix[val][i][j] = up + left - dia + add;
                }
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == 0){
                    continue;
                }
                int val = mat[i][j];
                int r1 = max(0, i-val);
                int c1 = max(0, j-val);
                int r2 = min(n-1,i+val);
                int c2 = min(m-1,j+val);
                int total = prefix[val][r2][c2];
                int up = 0;
                int left = 0;
                int dia = 0;
                if(r1 > 0){
                    up = prefix[val][r1-1][c2];
                }
                if(c1 > 0){
                    left = prefix[val][r2][c1-1];
                }
                if(i > 0 && j > 0){
                    dia = prefix[val][r1-1][c1-1];
                }
                int cnt = total - up - left + dia;
                for(int k=0;k<4;k++){
                    int nRow = i + dRow[k]*val;
                    int nCol = j + dCol[k]*val;
                    if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && mat[nRow][nCol] > val){
                        cnt--;
                    }
                }
                if(cnt == 0){
                    ans++;
                }
            }
        }
        return ans;
    }
};
int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> mat(n,vector<int>(m));
    for(int i=0;i<n*m;i++){
        cin >> mat[i/m][i%m];
    }
    Solution obj;
    int ans = obj.func(mat);
    cout << ans << " ";
    return 0;
}