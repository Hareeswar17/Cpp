#include <bits/stdc++.h>
using namespace std;
#ifdef QUEUE_T_PIE
#include "../template.cpp"
#else
#define debug(...) 1419
#define debugArr(...) 1419
#endif
#define int ll
#define ull unsigned ll
#define ll long long
#define ld long double
#define INF 1e18
#define F first
#define S second
#define pb push_back
#define endl '\n'
#define all(e) e.begin(), e.end()
#define mxN 100001
#define mxM 1001
const ld EPS = 1e-9;
const int MOD = 998244353;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
struct Median {
public:
  multiset<int> start, end;
  void insert(int n) {
    end.insert(n);
    balance();
  }
  void remove(int n) {
    auto it = start.find(n);
    if (it == start.end()) {
      end.erase(end.find(n));
    } else {
      start.erase(it);
    }
    balance();
  }
  void balance() {
    while (!end.empty() && !start.empty() && *end.begin() < *start.rbegin()) {
      int temp = *end.begin();
      end.erase(end.begin());
      start.insert(temp);
    }
    while (start.size() < end.size()) {
      int temp = *end.begin();
      start.insert(temp);
      end.erase(end.begin());
    }
    while (start.size() - end.size() > 1) {
      int temp = *prev(start.end());
      end.insert(temp);
      start.erase(prev(start.end()));
    }
  }
  int getMedian() { return *this->start.rbegin(); }
};

void solve() {
  int x, q, a, b;
  Median m;
  cin >> x >> q;
  m.insert(x);
  while (q--) {
    cin >> a >> b;
    m.insert(a);
    m.insert(b);
    cout << m.getMedian() << endl;
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

#ifdef QUEUE_T_PIE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
  freopen("../error.txt", "w", stderr);
#endif
  int tt = 1;
  // cin >> tt;
  while (tt--)
    solve();
}