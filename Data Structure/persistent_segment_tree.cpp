#include "bits/stdc++.h"

using namespace std;
using ll = long long; 

struct node{
  node *left, *right;
  ll val;
  node(ll a = 0, node *b = NULL, node *c = NULL) : val(a), left(b), right(c) {}
  void build(ll l, ll r){ 
    if(l == r) return; 
    left = new node(); 
    right = new node();
    ll mid = l + r >> 1;
    left -> build(l, mid);
    right -> build(mid+1, r);
    }
   node *update(ll l, ll r, ll idx, ll v) {    
    if(r < idx || l > idx) return this; 
    if(l == r) { 
      node *ret = new node(val, left, right);     
      ret -> val += v;
      return ret;
    }
    ll mid = l + r >> 1;
    node *ret = new node(val);  
    ret -> left = left -> update(l, mid, idx, v);
    ret -> right = right -> update(mid+1, r, idx, v);
    ret -> val = ret -> left -> val + ret -> right -> val;
    return ret; 
  }
  ll query(ll l, ll r, ll i, ll j) {
    if(r < i || l > j) return 0; 
    if(i <= l && r <= j) return val; 
    ll mid = l + r >> 1;
    return left -> query(l, mid,i,j) + right -> query(mid+1, r,i,j);
  }
} *root[35005];

signed main(){
  ll n = 420; 
  root[0] = new node();
  root[0] -> build(0,n-1);
  root[0] = root[0] -> update(0, n - 1,1,1); // update a previous version
  root[1] = root[0] -> update(0, n - 1,1,1); // create a new version
  return 0;
}
