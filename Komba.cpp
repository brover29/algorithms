#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9+7;
const ll N=1e6+3;
ll n,f[N],rf[N];
ll binpow(ll a,ll b){
    if(b==1)return a;
    if(b&1)return a*binpow(a,b-1)%mod;
    ll x=binpow(a,b/2);
    return x*x%mod;
}
ll C(ll n,ll k){
    if(n<k||k<0)return 0;
    return ((f[n]*rf[n-k]%mod)*rf[k]%mod);
}
int main(){
    f[1]=1;
    for(ll i=2;i<N;i++){
        f[i]=f[i-1]*i%mod;
    }
    rf[N-2]=binpow(f[N-2],mod-2);
    for(ll i=N-3;i>=0;i--){
        rf[i]=rf[i+1]*(i+1)%mod;

    }
    cout<<C(6,2);
}
