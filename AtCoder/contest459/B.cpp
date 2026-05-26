#include <bits/stdc++.h>>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<string> words;
    for(int i=0;i<N;i++){
        string str;
        cin >> str;
        words.push_back(str);
    }
    vector<char> st;
    for(auto it : words){
        st.push_back(it[0]);
    }
    vector<int> mpp(26,0);
    mpp['p'-'a'] = 7;
    mpp['q'-'a'] = 7;
    mpp['r'-'a'] = 7;
    mpp['s'-'a'] = 7;
    mpp['w'-'a'] = 9;
    mpp['x'-'a'] = 9;
    mpp['y'-'a'] = 9;
    mpp['z'-'a'] = 9;
    int val = 2;
    int cnt = 0;
    for(int i=0;i<26;i++){
        if(mpp[i] != 0){
            // val = mpp[i];
            continue;
        }
        else{
            if(mpp[i-1] == 7){
                val++;
            }
            if(cnt <= 3){
                mpp[i] = val;
                cnt++;
            }
            if(cnt >= 3){
                val++;
                cnt = 0;
            }
        }
    }
    string num;
    for(auto it : st){
        num += (mpp[it-'a']+'0');
    }
    cout << num << " ";
    return 0;
}