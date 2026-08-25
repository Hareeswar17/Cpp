/* #include <bits/stdc++.h>
using namespace std;
int main(){
    int q;
    cin >> q;
    while(q--){
        int n, k;
        cin >> n >> k;
        
        vector<int> a(n);
        int ans = INT_MAX;
        for(int i=0;i<n;i++){
            cin >> a[i];
            int rem = a[i]%k;
            ans = min(ans, (k-rem)%k);
        }
        cout << ans << "\n";
    }
    return 0;
} */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;

    while (q--) {
        int n, k;
        cin >> n >> k;

        int ans = INT_MAX;
        int evenCount = 0;

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            // Make one number divisible by k
            int operations = (k - x % k) % k;
            ans = min(ans, operations);
            // Count even numbers for k = 4
            if (x % 2 == 0) {
                evenCount++;
            }
        }

        if (k == 4) {
            int makeTwoEven;

            if (evenCount >= 2) {
                makeTwoEven = 0;
            }
            else if (evenCount == 1) {
                makeTwoEven = 1;
            }
            else {
                makeTwoEven = 2;
            }

            ans = min(ans, makeTwoEven);
        }

        cout << ans << '\n';
    }

    return 0;
}