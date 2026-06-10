#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    vector<int> A(n);
    vector<int> B(m);
    for(int i=0;i<n;i++){
        cin >> A[i];
    }
    for(int i=0;i<m;i++){
        cin >> B[i];
    }
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    stack<int> s1;
    stack<int> s2;
    for(int i=n-1;i>=0;i--){
        s1.push(A[i]);
    }
    for(int i=m-1;i>=0;i--){
        s2.push(B[i]);
    }
    int cnt = 0;
    while(!s1.empty() && !s2.empty()){
        int num1 = s1.top();
        int num2 = s2.top();
        if(num2 <= 2*num1){
            s1.pop();
            s2.pop();
            cnt++;
        }
        else{
            s1.pop();
        }
    }
    cout << cnt << endl;
    return 0;
}