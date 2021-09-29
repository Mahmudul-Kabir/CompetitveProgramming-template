/*
    
    Note        :           Finding MEX of an Array in log_n per query and nlogn preprocessing. 
 
    Link        :       
 
    Boka hoye gelum...
*/



#include "bits/stdc++.h"
 
#define sp <<" "
#define el <<"\n"
#define S second
#define F first
#define pb push_back
#define all(ar) ar.begin(),ar.end() 
#define pii pair<ll,ll> 

 
using namespace std;
using ll = long long;
using ld = long double;

ll const sz = 1005; // Highest Possible Value in Array. 
struct mex{
    ll oc[sz],str[4 * sz];  
    void upd(int a,int b,int x,int node,int val){
        if(a == b){
            str[node] += val; 
            return; 
        }
        int mid = a + (b - a)/2, lef = node * 2; 
        if(x <= mid) upd(a,mid,x,lef,val); 
        else upd(mid+1,b,x,lef+1,val); 
        str[node] = str[lef] + str[lef+1]; 
        return; 
    }
    int fmex(int a,int b,int node){
        if(a == b) return a; 
        int mid = a + (b - a)/2, lef = node * 2; 
        if(str[lef] < (mid - a + 1)) return fmex(a,mid,lef); 
        return fmex(mid+1,b,lef+1); 
    }
    void add(int x){
        if(oc[x] == 0) upd(0,sz,x,1,1); 
        oc[x] += 1; 
    }
    void erase(int x){
        oc[x] -= 1; 
        if(oc[x] == 0) upd(0,sz,x,1,-1);
    }
    int mx(){
        return fmex(0,sz,1); 
    }
    mex(vector<int> &ar){
        memset(str,0,sizeof(str)); 
        memset(oc,0,sizeof(oc)); 
        for(int r: ar) add(r); 
    }
}; 

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}
