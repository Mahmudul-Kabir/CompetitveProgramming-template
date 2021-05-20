/*
 
    Note        :         *HASH, unordered set and map and their function, __int128_t are to show how to use them.
                          *BIT: Binary indexed tree/ Fenwick tree and related functions.
                          *Matrix: matrix and related functions.
    
//*/

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")

//*/


#include "bits/stdc++.h"

using namespace std;
using ll = long long;
 
const ll mod = 100000007; 
const ll si = 5000006;

struct HASH{
  size_t operator()(const pair<int,int>&x)const{
    return hash<long long>()(((long long)x.first)^(((long long)x.second)<<32));
  }
};

__int128_t some;

unordered_map<pair<int,int>,int,HASH> mbp;
unordered_map<int,int> rec; 

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//*
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
//*/    
    rec.max_load_factor(0.25);
    rec.reserve(1<<19);

    return 0;
}

// Matrix

const ll ms = 30;       //matrix size. 
struct Mat{
    ll a[ms][ms]; 
    Mat(){
        memset(a,0,sizeof(a)); 
    }
    Mat operator *(Mat other){     //ms^3 
        Mat res; 
        for(ll i = 0; i < ms; i++){
            for(ll j = 0; j < ms; j++){
                for(ll k = 0; k < ms; k++){
                    res.a[i][j] += (a[i][k] * other.a[k][j]);   
                }
            }
        }
        return res; 
    }
    Mat operator +(Mat other){   //ms^2 
        Mat res; 
        for(ll i = 0; i < ms; i++){
            for(ll j = 0; j < ms; j++){
                res.a[i][j] = (a[i][j] + other.a[i][j]); 
            }
        }
        return res;
    }
}; 

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
