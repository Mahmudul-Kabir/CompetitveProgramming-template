/*
    
    Note        :     
                      * Find_mob_value() find the value of mobius function in range [1,100000]. 
                      *Pdi: Finds and stores the prime factors of a number with Pollard Rho factorization.
                      
*/



#include "bits/stdc++.h"

#define pb push_back
#define all(ar) ar.begin(),ar.end() 
  
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

//Finding Mobius Function value using Linear-sieve.

bitset<100005> com; 
int mo[100005];  

void Find_mob_value(){
    mo[1] = 1;
    int s = 0; 
    vector<int> pr;
    for(int i = 2; i <= 100000; i++){
        if(!com[i]){
            pr.pb(i); 
            s++; 
            mo[i] = -1; 
        }
        for(int j = 0; j < s && i * pr[j] <= 100000; j++){
            com[i * pr[j]] = 1; 
            if(i % pr[j] == 0){
                mo[i * pr[j]] = 0;
                break; 
            }
            else mo[i * pr[j]] = mo[i] * mo[pr[j]]; 
        }
    }
}


// Pollard-Rho Factorization
struct Pdi
{
    vector<ll> div,fin; 
    ll mul(ll a,ll b,ll md){
        return ((__int128_t) a * b) % md; 
    }
    ll binex(ll a,ll b,ll md){
        ll ans = 1; 
        while(b){
            if(b%2) ans = mul(ans,a,md); 
            a = mul(a,a,md); 
            b /= 2; 
        }
        return ans; 
    }
    bool is_com(ll a,ll d,ll md,ll s){
        ll x = binex(a,d,md); 
        if(x == 1 || x == md - 1) return 0; 
        for(int i = 1; i < s; i++){
            x = mul(x,x,md); 
            if(x == md - 1) return 0; 
        }
        return 1; 
    }
    bool MRbin(ll a){
        if(a < 2) return 0;
        if(a != 2 && a % 2 == 0) return 0;  
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
    ll f(ll a, ll c,ll md){
        return (mul(a,a,md) + c) % md; 
    }
    ll rho(ll n){
        if(n % 2 == 0) return 2; 
        ll x0 = (rand() % (n - 1)) + 1, c = (rand() % n) + 1; 
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
            div.pb(n); 
            return; 
        }
        ll d = rho(n); 
        factorize(d); 
        factorize(n/d); 
        return; 
    }
    void refine(){
        sort(all(div)); 
        fin.pb(div[0]); 
        ll sz = div.size(); 
        for(int i = 1; i < sz; i++){
            if(div[i] != div[i-1]) fin.pb(div[i]); 
        }
        return; 
    }
    Pdi(ll n){
        srand(time(0)); 
        factorize(n); 
        refine(); 
    }
    void reset(ll n){
        div.clear(); fin.clear(); 
        factorize(n); 
        refine(); 
    }
};



