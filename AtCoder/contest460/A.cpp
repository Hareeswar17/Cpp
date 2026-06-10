#include <bits/stdc++.h>
using namespace std;
int main(){
    int N,M;
    cin >> N >> M;
    int x = M;
    int cnt = 0;
    while(x > 0){
        x = N%x;
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}