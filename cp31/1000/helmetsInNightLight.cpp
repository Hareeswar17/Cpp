#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        long long p;
        cin >> n >> p;

        vector<long long> a(n), b(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        vector<pair<long long, long long>> people;

        for (int i = 0; i < n; i++) {
            people.push_back({b[i], a[i]});
        }
        sort(people.begin(), people.end());
        long long ans = p;
        long long remaining = n - 1;

        for (auto [cost, capacity] : people) {
            if (remaining == 0)
                break;

            if (cost >= p)
                break;

            long long use = min(remaining, capacity);

            ans += use * cost;
            remaining -= use;
        }
        ans += remaining * p;

        cout << ans << '\n';
    }

    return 0;
}