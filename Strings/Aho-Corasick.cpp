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

const int al = 26;

struct ver {
    int nx[al];
    bool lf = false;
    int p = 0;
    char pch;
    int link = 0;
    int go[al];
    int exit = 0; 
    int dep = 0; 
    ver(int p=-1, char ch='$',int fak = 0) : p(p), pch(ch), dep(fak){
        fill(begin(nx), end(nx), 0);
        fill(begin(go), end(go), 0);
    }
};

vector<ver> maz(1); 
int papa = 1; 

void add(string &s,int id){ // id is the index of the string 
    int v = 0; 
    for(char ch: s){
        int c = ch - 'a'; 
        if(!maz[v].nx[c]){
            maz[v].nx[c] = papa++; 
            maz.emplace_back(v,ch,maz[v].dep+1); 
        }
        v = maz[v].nx[c]; 
    }
    maz[v].lf = 1; 
    return; 
}

void con_aho(){      // this uses bfs to do the processing of each level. 
    queue<int> q; 
    q.push(0); 
    while(!q.empty()){
        int c = q.front(); 
        auto &v = maz[c]; 
        auto &li = maz[v.link]; 
        if(c != 0){
            v.exit = li.lf ? v.link : li.exit; 
        }
        q.pop();
        for(int i = 0; i < al; i++){
            v.go[i] = v.nx[i] ? v.nx[i] : li.nx[i];  
            if(v.nx[i]){
                maz[v.nx[i]].link = c ? li.nx[i] : 0; 
                q.push(v.nx[i]); 
            }else v.nx[i] = li.nx[i]; 
        }
    } 
}

int go(int v,char c){
    return maz[v].go[c - 'a']; 
}
