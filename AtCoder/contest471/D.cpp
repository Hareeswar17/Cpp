#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;
int main(){
    ll q, v;
    cin >> q >> v;
    priority_queue<ll> pq;
    for(int i=0;i<q;i++){
        int type;
        cin >> type;
        if(type == 1){
            ll time, charge;
            cin >> time >> charge;
            pq.push(charge-time);
        }
        else{
            ll time;
            cin >> time;
            if(pq.empty()){
                cout << -1 << endl;
            }
            ll maxCharge = pq.top();
            pq.pop();
            maxCharge = min(time + maxCharge, v);
            cout << maxCharge << endl;
        }
    }

    return 0;
}