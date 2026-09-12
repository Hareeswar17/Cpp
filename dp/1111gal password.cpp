#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 998244353;
int main(){
    // Input
    int n;
    cin >> n;

    //
    // string start = "";
    // string end = "";
    // for(int i=0;i<n;i++){
    //     start += '1';
    //     end += '9';
    // }
    // int s = stoi(start);
    // int e = stoi(end);
    // ll cnt = 0;
    // while(s <= e){
    //     bool flag = true; 
    //     int num = s;
    //     int prev_d = num%10;
    //     num /= 10;
    //     while(num > 0){
    //         int digit = num%10;
    //         if(abs(prev_d-digit) > 1 || digit == 0 || prev_d == 0){
    //             flag = false;
    //             break;
    //         }
    //         prev_d = num%10;
    //         num /= 10;
    //     }
    //     if(flag){
    //         cnt = (cnt+1)%MOD;
    //     }
    //     s += 1;
    // }
    // // Output
    // cout << cnt%MOD << '\n';

    vector<vector<ll>> dp(n+1,vector<ll>(10,0));

    for(int d=1;d<=9;d++){
        dp[1][d] = 1;
    }

    for(int len=2;len<=n;len++){
        for(int digit=1;digit<=9;digit++){
            // dp[len][digit] = dp[len-1][digit-1] + dp[len-1][digit] + dp[len-1][digit+1];
            // Because the immediate digits which satisfy the condition |Xi - Xi+1| <= 1 are digit-1,0,1
            dp[len][digit] += dp[len-1][digit];

            if(digit-1 >= 0){
                dp[len][digit] += dp[len-1][digit-1];
            }

            if(digit+1 <= 9){
                dp[len][digit] += dp[len-1][digit+1];
            }

            dp[len][digit] %= MOD;
        }
    }
    ll cnt = 0;
    for(int d=1;d<=9;d++){
        cnt = (cnt + dp[n][d])%MOD;
    }

    // Output
    cout << cnt << '\n';
    return 0;
}