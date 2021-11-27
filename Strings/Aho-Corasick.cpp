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

struct ver{
    int nx[26], go[26]; 
    bool lf = false; 
    int p = -1, link = -1; 
    char pch = "$"; 
    ver(int pa, char dc): p(pa), dc(pch){
        memset(nx,sizeof(nx),-1); 
        memset(go,sizeof(go),-1); 
    }
}; 

int papa = 0; 
vector<ver> maz(1); 

void add(string &s){
    int v = 0; 
    for(char ch: s){
        int c = ch - 'a'; 
        if(maz[v].nx[c] == -1){
            maz[v].nx[c] = ++papa; 
            maz[v].emplace_back(v,ch); 
        }
        v = maz[v].nx[c]; 
    }
    maz[v].lf = 1; 
    return; 
}

int go(int v,char ch); 

int get_link(int v){
    if(maz[v].link == -1){
        if(v == 0 || maz[v].p == 0) maz[v].link = 0; 
        else maz[v].link = go(get_link(maz[v].p), maz[v].pch); 
    }
    return maz[v].link; 
}

int go(int v,char ch){
    int c = ch - 'a'; 
    if(maz[v].go[c] == -1){
        if(maz[v].next[c] != -1) maz[v].go[c] = maz[v].nx[c]; 
        else maz[v].go[c] = v == 0 ? 0 : go(get_link(v),ch); 
    }
    return maz[v].go; 
}
