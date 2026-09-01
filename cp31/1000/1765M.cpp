/* #include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        // input
        int n;
        cin >> n;

        //
        int first = 1;
        int last = n-1;
        int ans = 1e9+7;
        int fx, sx;
        while(first <= last){
            int l = lcm(first,last);
            if(l <= ans && (first + last <= fx + sx)){
                ans = l;
                fx = first;
                sx = last;
            }
            first++;
            last--;
        }

        // output
        cout << fx << " " << sx << "\n";
    }
    return 0;
} */
/* #include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int d = 2;

        // Find smallest divisor of n
        while (n % d != 0) {
            d++;
        }

        int a = n / d;
        int b = n - a;

        cout << a << " " << b << '\n';
    }

    return 0;
} */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int d = n;

        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                d = i;
                break;
            }
        }

        int a = n / d;
        int b = n - a;

        cout << a << " " << b << '\n';
    }

    return 0;
}