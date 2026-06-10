#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll atMost(vector<int>& a,int K){
    if(K<0) return 0;

    ll ans=0,sum=0;
    int l=0,n=a.size();

    for(int r=0;r<n;r++){
        sum+=a[r];

        while(sum>K){
            sum-=a[l];
            l++;
        }

        ans+=r-l+1;
    }

    return ans;
}

int main(){
    int H,W,K;
    cin>>H>>W>>K;

    vector<string> S(H);
    for(int i=0;i<H;i++) cin>>S[i];

    if(H>W){
        vector<string> T(W,string(H,'0'));
        for(int i=0;i<H;i++)
            for(int j=0;j<W;j++)
                T[j][i]=S[i][j];
        swap(H,W);
        S=T;
    }

    ll ans=0;
    vector<int> col(W);

    for(int top=0;top<H;top++){

        fill(col.begin(),col.end(),0);

        for(int bottom=top;bottom<H;bottom++){

            for(int j=0;j<W;j++)
                col[j]+=S[bottom][j]-'0';

            ans+=atMost(col,K)-atMost(col,K-1);
        }
    }

    cout<<ans<<"\n";
}