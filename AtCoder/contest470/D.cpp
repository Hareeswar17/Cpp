#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> P(N + 1), inv(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> P[i];
        inv[P[i]] = i;
    }
    bool rev = false;
    while (Q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int x, y;
            cin >> x >> y;
            if (!rev) {
                int vx = P[x];
                int vy = P[y];
                swap(P[x], P[y]);
                inv[vx] = y;
                inv[vy] = x;
            } 
            else {
                int vx = inv[x];
                int vy = inv[y];
                swap(inv[x], inv[y]);
                P[vx] = y;
                P[vy] = x;
            }
        }
        else {
            rev = !rev;
        }
    }

    if (!rev) {
        for (int i = 1; i <= N; i++) {
            cout << P[i] << (i == N ? '\n' : ' ');
        }
    } 
    else {
        for (int i = 1; i <= N; i++) {
            cout << inv[i] << (i == N ? '\n' : ' ');
        }
    }

    return 0;
}