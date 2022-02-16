#include "bits/stdc++.h"

using namespace std;
using ll = long long; 

struct node{
    node *left, *right;
    ll val, lz;
    node(ll a = 0, node *b = NULL, node *c = NULL, ll lazy = 0) : val(a), left(b), right(c), lz(lazy) {}
    node(node *helo){
        val = helo -> val; 
        lz = helo -> lz; 
        left = helo -> left; 
        right = helo -> right; 
    }
    void build(ll l, ll r){ 
        if(l == r) return; 
        left = new node(); 
        right = new node();
        ll mid = l + r >> 1;
        left -> build(l, mid);
        right -> build(mid+1, r);
    }
    void push(ll l,ll r){
        val += (r - l + 1) * lz; 
        if(l != r){
            left = new node(left); 
            right = new node(right); 
            left -> lz += lz; 
            right -> lz += lz; 
        }
        lz = 0; 
        return;  
    }
    node *rupd(ll a, ll b, ll l, ll r,ll del){
        if(b < l || a > r || l > r) return this; 
        if(lz) push(a,b); 
        if(l <= a && b <= r){
            node *ret = new node(val,left,right,0); 
            if(lz != 0) push(a,b);
            else if(a != b){
                ret -> left = new node(left); 
                ret -> right = new node(right);
                ret -> left -> lz += del; 
                ret -> right -> lz += del; 
            }
            ret -> val += (b - a + 1) * del;
            return ret; 
        } 
        node *ret = new node(val,left,right,0);  
        ll mid = a + (b - a)/2;  
        ret -> left = left -> rupd(a,mid,l,r,del); 
        ret -> right = right -> rupd(mid+1,b,l,r,del); 
        ret -> val = ret -> left -> val + ret -> right -> val;
        return ret; 

    }  
    ll lque(ll a, ll b, ll l, ll r){
        //cout<<a sp<<b el; 
        if(b < l || a > r) return 0; 
        if(lz) push(a,b); 
        if(a >= l && b <= r) return val; 
        ll mid =  a + (b - a)/2; 
        return left -> lque(a,mid,l,r) + right -> lque(mid+1, b, l, r); 
    }
}*root[100005];

signed main(){
  ll n = 420; 
  root[0] = new node();
  root[0] -> build(0,n-1);
  root[0] = root[0] -> rupd(0, n - 1,l,r,val); // update a previous version
  root[1] = root[0] -> rupd(0, n - 1,l,r,val); // create a new version
  return 0;
}
