#include <bits/stdc++.h>
using namespace std;
// int main(){
//     unsigned int n;
//     cin >> n;
//     if(n > 12){
//         cout << "n will oveflow 32-bit integer" << endl;
//         exit(0); // or use return 0;
//     }
//     unsigned int ans = 1;
//     for(unsigned int i=2;i<=n;i++){
//         ans *= i;
//     }
//     cout << ans << endl;
//     return 0;
// }
int main(){
    // This code is for using when we need big factorials like upto 20! 
    // Because in 32-bit integer 13! will oveflow but if we use unsigned long long we can extend this upto 20!
    int n;
    cin >> n;
    unsigned long long ans = 1;
    for(int i=2;i<=n;i++){
        ans *= i;
    }
    cout << ans << endl;
    return 0;
}
// The reason we use unsigned is because it uses bit which is used to reperesent negative numbers so now we have almost double the range than when using int