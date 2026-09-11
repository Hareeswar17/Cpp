#include <bits/stdc++.h>
using namespace std;
int main(){
    // Input
    int n;
    long long p;
    cin >> n >> p;
    double sum = 0;
    for(int i=0;i<n;i++){
        long long x,v;
        cin >> x >> v;
        if(x == p){
            continue;
        }
        sum += (double(v)/abs(x-p));
    }

    //Ouput
    cout << fixed << setprecision(20) << sum << '\n';

    return 0;
}