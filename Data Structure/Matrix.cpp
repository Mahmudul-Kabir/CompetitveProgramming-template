#include "bits/stdc++.h"

using namespace std;
using ll = long long;
 
const ll mod = 100000007; 
const ll si = 5000006;

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
