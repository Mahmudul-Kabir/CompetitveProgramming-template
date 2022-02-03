#include "bits/stdc++.h"

using namespace std;
using ll = long long; 

struct seg{
    vector<ll> str; 
    ll n; 
    ll fun(ll a,ll b){
        return a | b; 
    }
    void bld(ll a,ll b,ll node, ll *id){
        //cout<<a sp<<b el; 
        if(a == b){
            str[node] = id[a]; 
            return; 
        }
        ll lef = node * 2, mid = a + (b - a)/2;
        bld(a,mid,lef,id); 
        bld(mid+1,b,lef+1,id); 
        str[node] = fun(str[lef],str[lef+1]); 
        return; 
    }
    ll que(ll a,ll b,ll l,ll r,ll node){
        if(b < l || r < a) return 0; 
        if(a >= l && b <= r) return str[node]; 
        ll lef = node * 2, mid = a + (b - a)/2; 
        return fun(que(a,mid,l,r,lef),que(mid+1,b,l,r,lef+1)); 
    }
    seg(){
        str.resize(1,0); 
        return; 
    }
    seg(int x): n(x){
        str.resize(n,0); 
        return; 
    } 
    void clr(ll x, ll *hehe){
        ll n = x;
        str.resize(4 * n,0); 
        bld(0,n - 1,1,hehe);  
        return; 
    }
}; 
