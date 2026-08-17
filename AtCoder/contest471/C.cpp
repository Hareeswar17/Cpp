/* #include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    multiset<long long> cookies;
    for (int i = 0; i < N; i++) {
        long long x;
        cin >> x;
        cookies.insert(x);
    }
    long long current = 0;
    long long ans = 0;
    while (!cookies.empty()) {
        auto right = cookies.lower_bound(current);
        auto left = right;
        if (left != cookies.begin()) {
            --left;
        } else {
            left = cookies.end();
        }
        auto chosen = cookies.end();
        if (left == cookies.end()) {
            chosen = right;
        }
        else if (right == cookies.end()) {
            chosen = left;
        }
        else {
            long long distLeft = current - *left;
            long long distRight = *right - current;

            if (distLeft <= distRight) {
                chosen = left;
            } else {
                chosen = right;
            }
        }

        ans += abs(*chosen - current);
        current = *chosen;
        cookies.erase(chosen);
    }

    cout << ans << '\n';

    return 0;
}
*/

/* #include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;
int main(){
    int n;
    cin >> n;
    multiset<ll> st;
    for(int i=0;i<n;i++){
        ll num;
        cin >> num;
        st.insert(num);
    }
    ll ans = 0;
    int pos = 0;
    for(int i=0;i<n;i++){
        auto it = st.lower_bound(pos);
        ll nxt;
        if(it == st.begin()){ // If there are no cookies to the left 
            nxt = *it;
        }
        else if(it == st.end()){ // If there are no cookies to the right if we just reduce the pointer we will be pointing to right cookie
            --it;
            nxt = *it;
        }
        else{
            ll rightCookie = *it;
            ll leftCookie = *prev(it);
            if(abs(rightCookie-pos) < abs(leftCookie-pos)){
                nxt = rightCookie;
            }
            else{
                nxt = leftCookie;
            }
        }
        ans = (ans + abs(pos-nxt))%MOD;
        st.erase(st.find(nxt));
        pos = nxt;
    }

    cout << ans%MOD << endl;

    return 0;
} */

#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;
int main(){
    int n;
    cin >> n;
    multiset<ll> st;
    for(int i=0;i<n;i++){
        int num;
        cin >> num;
        st.insert(num);
    }
    ll ans = 0;
    ll curr_pos = 0;
    for(int i=0;i<n;i++){
        auto rightCookie = st.lower_bound(curr_pos);
        auto leftCookie = rightCookie;
        if(leftCookie != st.begin()){
            --leftCookie;
        }
        else{
            leftCookie = st.end();
        }
        auto choosen = st.end();
        if(leftCookie == st.end()){
            choosen = rightCookie;
        }
        else if(rightCookie == st.end()) {
            choosen = leftCookie;
        }
        else{
            ll leftDist = curr_pos - *leftCookie;
            ll rightDist = *rightCookie - curr_pos;
            if(leftDist <= rightDist){
                choosen = leftCookie;
            }
            else{
                choosen = rightCookie;
            }
        }
        ans = (ans + abs(curr_pos - *choosen))%MOD;
        curr_pos = *choosen;
        st.erase(choosen);
    }

    cout << ans%MOD << endl;

    return 0;
}