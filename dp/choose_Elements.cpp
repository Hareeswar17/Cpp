#include <bits/stdc++.h>
using namespace std;
void func(){
    // Input
    int n,k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        cin >> b[i];
    }

    //
    bool dpA = true;
    bool dpB = true;
    for(int i=1;i<n;i++){
        bool newA = false;
        bool newB = false;
        if(dpA && abs(a[i-1]-a[i]) <= k){
            newA = true;
        }
        if(dpB && abs(b[i-1]-a[i]) <= k){
            newA = true;
        }
        if(dpA && abs(a[i-1]-b[i]) <= k){
            newB = true;
        }
        if(dpB && abs(b[i-1]- b[i]) <= k){
            newB = true;
        }
        dpA = newA;
        dpB = newB;
        if(!dpA && !dpB){
            cout << "No" << "\n";
            return;
        }
    }

    //Output
    cout << "Yes" << "\n";
}
int main(){
    func();
    return 0;
}