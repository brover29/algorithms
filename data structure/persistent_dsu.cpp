#include <bits/stdc++.h>
//qwerty47924692
using namespace std;
using ll = long long;
const ll N=2e5+29;
ll n,m,q,pr[N],t[N],sz[N];
ll get(ll v,ll timer){
    if(v==pr[v]||t[v]>timer)return v;
    return get(pr[v],timer);
}
void uni(ll u,ll v,ll time){
    u=get(u,m+1);
    v=get(v,m+1);
    if(u==v)return;
    if(sz[v]>sz[u])swap(u,v);
    pr[v]=u;
    sz[u]=max(sz[u],sz[v]+1);
    t[v]=time;
}
ll check(ll k,ll u,ll v){
    u=get(u,k);
    v=get(v,k);
    return (u==v);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m>>q;
    for(ll i=1;i<=n;i++){
        pr[i]=i;
        sz[i]=1;
    }
    for(ll i=1;i<=m;i++){
        ll u,v;
        cin>>u>>v;
        uni(u,v,i);
    }
    while(q--){
        ll u,v;
        cin>>u>>v;
        ll l=0,r=m+1;
        while(l<r){
            ll mid=(r+l)>>1;
            if(check(mid,u,v))r=mid;
            else l=mid+1;
        }
        cout<<(l==m+1 ? -1 : l)<<'\n';

    }
}
