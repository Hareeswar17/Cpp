#include<bits/stdc++.h>
using namespace std;
int main(){
    // Input
    int n,m;
    cin >> n >> m;
    vector<int> h(n), p(m);
    for(int i=0;i<n;i++){
        cin >> h[i];
    }
    for(int i=0;i<m;i++){
        cin >> p[i];
    }

    //
    vector<int> minDist;
    for(int i=0;i<n;i++){
        int currH = h[i];

        auto it = lower_bound(p.begin(), p.end(), currH);
        int mnDist = INT_MAX;
        if(it != p.end()){
            mnDist = min(mnDist, abs(currH-*it));
        }
        if(it != p.begin()){
            it--;
            mnDist = min(mnDist, abs(currH-*it));
        }

        minDist.push_back(mnDist);
    }

    // Output
    for(auto it : minDist){
        cout << it << "\n";
    }
    return 0;
}