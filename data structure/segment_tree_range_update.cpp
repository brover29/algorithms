#include <bits/stdc++.h>
using namespace std;
using ll =long long;
const ll N=1e6+10;
ll n,m,a[N],st[4*N],z[4*N];
void push(ll v,ll l,ll r){
    if(!z[v])return;
    ll mid=(r+l)/2;
    st[v*2]=z[v]*(mid-l+1);
    st[v*2+1]=z[v]*(r-mid);
    z[v*2]=z[v];
    z[v*2+1]=z[v];
    z[v]=0;
    return;
}
void build(ll v,ll l,ll r){
    if(l==r){
        st[v]=a[l];
        return;
    }
    ll mid=(r+l)/2;
    build(v*2,l,mid);
    build(v*2+1,mid+1,r);
    st[v]=st[v*2]+st[v*2+1];
}
void upd(ll v,ll l,ll r,ll x,ll y,ll value){
    if(l>y||x>r)return;
    if(x<=l&&r<=y){
        st[v]=value*(r-l+1);
        z[v]=value;
        return;
    }
    push(v,l,r);
    ll mid=(r+l)/2;
    upd(v*2,l,mid,x,y,value);
    upd(v*2+1,mid+1,r,x,y,value);
    st[v]=st[v*2]+st[v*2+1];
    return;
}
ll get(ll v,ll l,ll r,ll x,ll y){
    if(l>y||x>r)  {
        return 0;
    }
    if(x<=l&&r<=y){
        return st[v];
    }
    push(v,l,r);
    ll mid=(r+l)/2;
    return get(v*2,l,mid,x,y)+get(v*2+1,mid+1,r,x,y);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;i++)cin>>a[i];
    build(1,1,n);
    while(m--){
        ll t,l,r,x;
        cin>>t>>l>>r;
        if(t==1){
            cout<<get(1,1,n,l,r)<<'\n';
            continue;
        }
        cin>>x;
        upd(1,1,n,l,r,x);
    }
}
