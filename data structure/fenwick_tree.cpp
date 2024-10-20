#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n,m,a[200100],f[200100];
ll pref(ll r){
    if(r<=0)return 0;
    return f[r]+pref((r&(r+1))-1);
}
void upd(ll pos,ll x,ll y){
    if(pos>n)return;
    f[pos]+=x;
    f[pos]-=y;
    pos|=pos+1;
    upd(pos,x,y);
}
ll get(ll l,ll r){
    if(l)return pref(r)-pref(l-1);
    return pref(r);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        upd(i,a[i],0);
    }
    while(m--){
        ll t,l,r;
        cin>>t>>l>>r;
        if(t==1){
            upd(l,r,a[l]);
            a[l]=r;
        }
        else{
            cout<<get(l,r)<<'\n';
        }
    }
}
