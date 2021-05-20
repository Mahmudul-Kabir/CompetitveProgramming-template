/*
    
    Note        :          This template has: 
                                *Pdi : saves prime divisors of a number with Pollard's Rho factorization. 
    
*/


#include "bits/stdc++.h"
 
#define sp <<" "
#define el <<"\n"
 
using namespace std;
using ll = long long; 

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//*
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
//*/
    
    return 0;
}

// Stores the prime divisors of a number.

struct Pdi
{
    unordered_set<ll> div; 
    ll binex(ll a,ll b,ll md){
        ll ans = 1; 
        while(b){
            if(b%2) ans = (ans * a) % md; 
            a = (a * a) % md; 
            b /= 2; 
        }
        return ans; 
    }
    bool is_com(ll a,ll d,ll md,ll s){
        ll x = binex(a,d,md); 
        if(x == 1 || x == md - 1) return 0; 
        for(int i = 1; i < s; i++){
            x = ((__int128_t) x * x) % md; 
            if(x == md - 1) return 0; 
        }
        return 1; 
    }
    bool MRbin(ll a){
        if(a < 2) return 0; 
        ll s = 0, d = a - 1; 
        while(!(d&1)){
            d >>= 1; 
            s += 1; 
        }
        for(ll r: {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}){
            if(a == r) return 1; 
            if(is_com(r,d,a,s)) return 0; 
        }
        return 1; 
    }
    ll mul(ll a,ll md){
        return ((__int128_t) a * a) % md; 
    }
    ll f(ll a, ll c,ll md){
        return (mul(a,md) + c) % md; 
    }
    ll rho(ll n){
        ll x0 = (rand() % n) + 1, c = (rand() % n) + 1; 
        ll x = x0, y = x0,g = 1; 
        while(g == 1){
            x = f(x,c,n); 
            y = f(y,c,n); 
            y = f(y,c,n); 
            g =  __gcd(abs(x-y),n); 
        }
        return g; 
    }
    void factorize(ll n){
        if(n == 1) return; 
        if(MRbin(n)){
            div.insert(n); 
            return; 
        }
        ll d = rho(n); 
        factorize(d); 
        factorize(n/d); 
        return; 
    }
    Pdi(ll n){
        srand(time(0)); 
        factorize(n); 
    }
    void reset(ll n){
        div.clear(); 
        factorize(n); 
    }
    void show(){
        for(ll r: div) cout<<r sp; cout el; 
    }
};

