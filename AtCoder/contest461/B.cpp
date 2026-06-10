#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i=0;i<n;i++){
        cin >> a[i]; // {i -> person a[i] -> axe}
    }
    for(int i=0;i<n;i++){
        cin >> b[i]; // {i -> axe b[i] -> person}
    }
    // In axe i is owned by b[i]
    unordered_map<int,int> mpp;
    // {person, axe}
    for(int i=0;i<n;i++){
        mpp[i+1] = a[i];
    }
    bool flag = true;
    for(int i=0;i<n;i++){
        if(mpp[b[i]] != i+1){
            flag = false;
            break;
        }
    }
    if(flag){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
    return 0;
}