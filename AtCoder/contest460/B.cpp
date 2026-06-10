#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    int t;
    cin >> t;
    while(t--){
        ll x1,y1,r1, x2,y2,r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        ll distRSq = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
        ll totRSq = (r1 + r2)*(r1+r2);
        ll min = abs(r1-r2);
        ll maxi = r1+r2;
        if(min*min <= distRSq && distRSq >= maxi*maxi){
            cout << "No" << endl;
        }
        else{
            cout << "Yes" << endl;
        }
        // cout << "Yes" << endl;
    }
    return 0;
}