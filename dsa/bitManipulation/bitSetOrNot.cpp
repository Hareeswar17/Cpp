#include <bits/stdc++.h>
using namespace std;
int main(){
    int n = 57; // 57 -> 111001
    // check whether ith bit is set or not 
    // 111001 now we have to check whether 3rd bit set or not 
    // to do this we use right shift operator because it shifts the bits by i positions
    // 000111 -> after shifting by 3 bits compare with 1(000001)
    // 1 & 1 only gives 1 any other combo gives 0
    /*int i = 3;
    if((n >> i) & 1){
        cout << "Yess" << endl;
    }
    else{
        cout << "No" << endl;
    }*/

    /* 
        How to check whether a number is Even or Odd -
        depends on last bit because only that bit contributes to odd number
        111001 -> last bit set (57), 111000 -> last bit not set (56)  
    */

    /* if(n & 1){
        cout << "Yess" << endl;
    }
    else{
        cout << "No" << endl;
    } */

    /* Count no of set bits in number fastest way to do is use popcount(n) time complexity is O(1) normal way takes O(k) 
       If n = 12 
       1) 1100 & 1011 becomes 1000 
       2) 1000 & 0111 becomes 0000
    */

    int cnt = 0;
    while(n){
        n = n & n-1;
        cnt++;
    }
    cout << cnt << endl;

    return 0;
}