#include <bits/stdc++.h>
#define ll long long
using namespace std;
class DynamicSet{
    public:
    ll lazyAdd = 0;
    multiset<ll> st;
    void addToAll(ll val){
        lazyAdd += val;
    }
    void insert(ll x){
        st.insert(x-lazyAdd);
    }
    void resetLazyAdd(ll x){
        lazyAdd = x;
    }
    ll getSmallest(){
        if(st.empty()){
            return -1;
        }
        return *st.begin() + lazyAdd;
    }
    ll getLargest(){
        if(st.empty()){
            return -1;
        }
        return *st.rbegin() + lazyAdd;
    }
    void eraseFirst(){
        if(!st.empty()){
            auto find = st.find(*st.begin());
            st.erase(find);
        }
    }
    void eraseLast(){
        if(!st.empty()){
            auto find = st.find(*st.rbegin());
            st.erase(find);
        }
    }
    void erase(ll x){
        auto find = st.find(x);
        // If we want to delete original value just do find(x-lazyAdd)
        if(!st.empty()){
            st.erase(find);
        }
    }
};