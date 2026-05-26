#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--) {
        string s;
        cin >> s;
        int n = s.length();
        vector<int> freq(26, 0);
        for(char ch : s) {
            freq[ch - 'a']++;
        }
        int maxi = 0;
        int idx = 0;
        for(int i = 0; i < 26; i++) {
            if(freq[i] > maxi) {
                maxi = freq[i];
                idx = i;
            }
        }
        if(maxi > (n + 1) / 2) {
            cout << "No\n";
            continue;
        }
        string ans(n, '#');
        int pos = 0;
        while(freq[idx] > 0) {
            ans[pos] = char(idx + 'a');
            freq[idx]--;
            pos += 2;
        }
        for(int i = 0; i < 26; i++) {
            while(freq[i] > 0) {
                if(pos >= n) {
                    pos = 1;
                }
                ans[pos] = char(i + 'a');
                freq[i]--;
                pos += 2;
            }
        }
        cout << "Yes\n";
        cout << ans << '\n';
    }

    return 0;
}