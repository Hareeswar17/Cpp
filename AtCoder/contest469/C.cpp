#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> prefixO(n), prefixX(n);
    prefixO[0] = (s[0] == 'o');
    prefixX[0] = (s[0] == 'x');

    for (int i = 1; i < n; i++) {
        prefixO[i] = prefixO[i - 1] + (s[i] == 'o');
        prefixX[i] = prefixX[i - 1] + (s[i] == 'x');
    }
    vector<int> xPos;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'x')
            xPos.push_back(i);
    }
    int totalX = xPos.size();
    for (int i = 0; i < n; i++) {
        int k = i + 1;
        int hits = prefixO[i];
        if (hits == 0) {
            cout << k << endl;;
            continue;
        }
        int xSeen = prefixX[i];
        int suffixX = totalX - xSeen;
        if (suffixX < hits) {
            cout << n << endl;
        } else {
            int pos = xPos[xSeen + hits - 1];
            cout << pos + 1 << endl;
        }
    }

    return 0;
}