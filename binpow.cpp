#include <bits/stdc++.h>
//qwerty47924692
using namespace std;
using ll = long long;
const ll N=2e5+29;
const ll mod=1e9+7;
const string br="617283";
ll binmul(ll a,ll b){
    if(!b)return 0
    if(b&1)return (a+binmul(a,b-1))%mod;
    ll x=binmul(a,b/2);
    return (x+x)%mod;
}
ll binpow(ll a,ll b){
    if(!b)return 1;
    if(b&1)return binmul(a,binpow(a,b-1));
    ll x=binpow(a,b/2);
    return binmul(x,x);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);


}

