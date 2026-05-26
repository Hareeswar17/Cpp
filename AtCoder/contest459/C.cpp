#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> a(N, 0);
    vector<int> freq(Q + 5, 0);
    freq[0] = N;
    int mini = 0;          
    int minCnt = N;     
    while(Q--) {
        int type;
        cin >> type;
        if(type == 1) {
            int x;
            cin >> x;
            x--;
            int oldVal = a[x];
            freq[oldVal]--;
            a[x]++;
            freq[a[x]]++;
            if(oldVal == mini) {
                minCnt--;
            }
            while(minCnt == 0) {
                mini++;
                minCnt = freq[mini];
            }
        }
        else {
            int y;
            cin >> y;
            int need = mini + y;
            int ans = 0;
            for(int val = need; val <= Q + 2; val++) {
                ans += freq[val];
            }
            cout << ans << '\n';
        }
    }
    return 0;
}