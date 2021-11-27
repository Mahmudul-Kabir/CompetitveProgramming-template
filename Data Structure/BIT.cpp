#include "bits/stdc++.h"

using namespace std;
using ll = long long;
 
const ll mod = 100000007; 
const ll si = 5000006;

// Binary Indexed Tree


const ll bsi = 100005; // array size
class BIT{
private: 
    ll n = 100000,ftr[bsi]; 

public: 
    BIT(){
        memset(ftr,0,sizeof(ftr)); 
    }
    void add(int x,int val){
        while(x <= n){
            ftr[x] += val; 
            x += x & (-x); 
        }
    }
    ll get(int x){
        if(x <= 0) return 0; 
        ll ans = 0; 
        while(x){
            ans += ftr[x]; 
            x -= x & (-x); 
        }
        return ans; 
    }
    ll get(int a,int b){
        return get(b) - get(a-1); 
    }
}; 
