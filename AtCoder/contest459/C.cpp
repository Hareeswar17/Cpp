#include <bits/stdc++.h>
using namespace std;
#define N 300005
int main(){
    vector<int> A(N+1,0);
    vector<int> B(N+1,0);
    int n,q,t,x;
    int k = 0;
    cin >> n >> q;
    for(int i=0;i<q;i++){
        cin >> t >> x;
        if(t == 1){
            A[x]++;
            int val = A[x];
            B[val]++;
            if(B[val] == n){
                k = val;
            }
        }
        else{
            if(x+k > q){
                cout << 0 << endl;
            }
            else{
                cout << B[x+k] << endl;
            }
        }
    }
    return 0;
}