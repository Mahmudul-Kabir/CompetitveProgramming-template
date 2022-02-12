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
    node *push(int l,int r){
        node *ret = new node(val,left,right,0);
        ret -> val += (r - l + 1) * lz; 
        if(l != r){
            ret -> left = new node(left); 
            ret -> right = new node(right); 
            ret -> left -> lz += lz; 
            ret -> right -> lz += lz; 
        }
        return ret;  
    }
    node *rupd(ll a, ll b, ll l, ll r,ll del){
        if(b < l || a > r) return this; 
        if(l <= a && b <= r){
            node *ret; 
            if(lz != 0) ret = push(a,b), lz = 0;
            else if(a != b){
                ret = new node(val,left,right,0);
                ret -> left = new node(left); 
                ret -> right = new node(right);
            }else ret = new node(val);
            ret -> val += (b - a + 1) * del;
            if(a != b){
                ret -> left -> lz += del; 
                ret -> right -> lz += del; 
            }
            return ret; 
        } 
        node *ret;  
        if(lz != 0) ret = push(a,b); 
        else ret = new node(val,left,right,0);
        ll mid = a + (b - a)/2;  
        ret -> left = left -> rupd(a,mid,l,r,del); 
        ret -> right = right -> rupd(mid+1,b,l,r,del); 
        ret -> val = ret -> left -> val + ret -> right -> val;
        return ret; 

    }  
    ll lque(ll a, ll b, ll l, ll r, ll lazy){
        //cout<<a sp<<b el; 
        if(b < l || a > r) return 0; 
        if(a >= l && b <= r) return val + ((b - a + 1) * lazy); 
        ll mid =  a + (b - a)/2, nlz = lazy + lz; 
        return left -> lque(a,mid,l,r,nlz) + right -> lque(mid+1, b, l, r, nlz); 
    }
}*root[100005];
