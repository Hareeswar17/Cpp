#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// ll func(int n, int x, int y, bool flag, vector<vector<ll>>& dp){
//     if(n == 1){
//         if(flag == true){
//             return 0;
//         } else{
//             return 1;
//         }
//     }
//     if(dp[n][flag] != -1){
//         return dp[n][flag];
//     }
//     if(flag == true){ 
//         // red(n,true) = red(n-1,true) + x*blue(n,false)
//         dp[n][flag] = func(n-1,x,y,true,dp) + x*func(n,x,y,false,dp);
//     } else{ 
//         // blue(n,false) = red(n-1,true) + y*blue(n-1,false)
//         dp[n][flag] = func(n-1,x,y,true,dp) + y*func(n-1,x,y,false,dp);
//     }
//     return dp[n][flag];
// }
// void changingJewels(){
//     // Input
//     int n, x, y;
//     cin >> n >> x >> y;

//     //
//     if(n <= 1){
//         cout << 0 << "\n";
//         return;
//     }
//     vector<vector<ll>> dp(n+1, vector<ll>(2,-1));
//     ll ans = func(n,x,y,true,dp); // flag == true means color is red

//     // Output
//     cout << ans << "\n";
// }
int main(){
    // changingJewels();
    
    // Input
    int n, x, y;
    cin >> n >> x >> y;

    //
    vector<ll> dpR(n+1), dpB(n+1);
    dpR[1] = 0;
    dpB[1] = 1;
    for(int i=2;i<=n;i++){
        dpB[i] = dpR[i-1] + y*dpB[i-1];
        dpR[i] = dpR[i-1] + x*dpB[i];
    }

    // Output
    cout << dpR[n] << "\n";
    return 0;
}