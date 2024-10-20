#include <bits/stdc++.h>
//qwerty47924692
using namespace std;
using ll = long long;
const ll N=1e5+4;
const ll inf=1e18;
ll n,q;
struct line{
    ll a0,a1,a2,a3;
};
line st[4*N];
ll calc(line a,ll x){
    return a.a0+a.a1*x+a.a2*x*x+a.a3*x*x*x;
}
void build(ll v,ll l,ll r){
    if(l==r){
        st[v]={inf,inf};
        return;
    }
    ll mid=(r+l)>>1;
    build(v*2,l,mid);
    build(v*2+1,mid+1,r);
    st[v]={inf,inf};
}
void update(ll v,ll l,ll r,line x){
    if(l==r){
        if(calc(x,l)<=calc(st[v],l)){
            st[v]=x;
        }
        return;
    }
    ll mid=(r+l)>>1;
    bool left=(calc(x,l)<=calc(st[v],l));
    bool middle=(calc(x,mid)<=calc(st[v],mid));
    if(middle){
        swap(st[v],x);
    }
    if(left==middle){
        update(v*2,l,mid,x);
    }
    else{
        update(v*2+1,mid+1,r,x);
    }
}
line get(ll v,ll l,ll r,ll x){
    if(l==r){
        return st[v];
    }
    ll mid=(r+l)>>1;
    if(x<=mid){
       line ans=get(v*2,l,mid,x);
       if(calc(ans,x)<=calc(st[v],x))return ans;
       return st[v];
    }
    line ans=get(v*2+1,mid+1,r,x);
    if(calc(ans,x)<=calc(st[v],x))return ans;
    return st[v];

}
void solve(){
    cin>>n;
    build(1,0,1e5);
    for(ll i=1;i<=n;i++){
        ll a0,a1,a2,a3;
        cin>>a0>>a1>>a2>>a3;
        update(1,0,1e5,{a0,a1,a2,a3});
    }
    cin>>q;
    while(q--){
        ll t;
        cin>>t;
        cout<<calc(get(1,0,1e5,t),t)<<'\n';
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t;
    cin>>t;
    while(t--){
        solve();

    }

}
