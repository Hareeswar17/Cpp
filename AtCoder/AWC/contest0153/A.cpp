#include<bits/stdc++.h>
using namespace std;
int main(){
    // Input
    int n, k;
    cin >> n >> k;
    vector<int> A(n+1);
    vector<int> C(k+1), B(k+1);
    A[0] = 0;
    B[0] = 0;
    C[0] = 0;
    for(int i=1;i<=n;i++){
        cin >> A[i];
    }
    for(int i=1;i<=k;i++){
        cin >> B[i];
    }
    for(int i=1;i<=k;i++){
        cin >> C[i];
    }

    //
    long long var = 0;
    // unordered_map<int,int> mpp;
    // for(int i=1;i<=k;i++){
    //     mpp[B[i]] = C[i];
    // }
    for(int i=1;i<=k;i++){
      A[B[i]] = C[i];
    }
    for(int i=1;i<n;i++){
        // int diff;
        // if(mpp.find(i) != mpp.end()){
        //     diff = abs(mpp[i] - A[i+1]);
        // } else{
        //     diff = abs(A[i+1] - A[i]);
        // }
        var += abs(A[i+1] - A[i]);
    }
    // Ouptut
    cout << var <<"\n";
    return 0;
}