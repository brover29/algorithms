#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[100100],st[400100];
ll merge(ll a,ll b){
    return a+b;
}
void build(ll v,ll l,ll r){
    if(l==r){
        st[v]=a[l];
        return;
    }
    ll mid=(r+l)/2;
    build(v*2,l,mid);
    build(v*2+1,mid+1,r);
    st[v]=merge(st[v*2],st[v*2+1]) ;
}
void upd(ll v,ll l,ll r,ll pos,ll x){
    if(l==r){
        st[v]=x;
        return;
    }
    ll mid=(r+l)/2;
    if(mid>=pos)upd(v*2,l,mid,pos,x);
    else upd(v*2+1,mid+1,r,pos,x);
    st[v]=merge(st[v*2],st[v*2+1]);
}
ll get(ll v,ll l,ll r,ll x,ll y){
    if(y<l||r<x)return 0;
    if(x<=l&&r<=y){
        return st[v];
    }
    ll mid=(r+l)/2;
    return merge(get(v*2,l,mid,x,y),get(v*2+1,mid+1,r,x,y));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    for(ll i=1;i<=n;i++)cin>>a[i];
    build(1,1,n);
    for(ll i=1;i<=m;i++){
        ll t,l,r;
        cin>>t>>l>>r;
        l++;
        if(t==1)upd(1,1,n,l,r);
        else cout<<get(1,1,n,l,r)<<'\n';
    }

}

