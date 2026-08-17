#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b;
    cin >> a >> b;
    double div = (double)a/b;
    if (a + b == 9 || 
        a - b == 9 || 
        a * b == 9 || 
        div == 9) {
        cout << "Nine" << endl;
    } else {
        cout << "Nein" << endl;
    }

    return 0;
}