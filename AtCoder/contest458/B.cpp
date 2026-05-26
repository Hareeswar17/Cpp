#include <bits/stdc++.h> 
using namespace std;
int main(){
  int n;
  int m;
  cin >> n >> m;
  vector<vector<int>> ans(n,vector<int>(m));
  vector<int> dRow = {1,0,-1,0};
  vector<int> dCol = {0,1,0,-1};
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      int cnt = 0;
      for(int k=0;k<4;k++){
        int nRow = i + dRow[k];
        int nCol = j + dCol[k];
        if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m){
          cnt++;
        }
      }
      ans[i][j] = cnt;
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}