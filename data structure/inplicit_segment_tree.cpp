#include <bits/stdc++.h>
//problem https://codeforces.com/group/ttn3iaJrSd/contest/447648/submission/265751869
using namespace std;
using ll = int;
const ll N=3e6+13;
#define l first
#define r second
ll st[4*N],z[4*N],timer=1,lv[4*N],rv[4*N];
ll n,q,sta[N],sz;
vector<pair<ll,ll>>v(200100);
void push(ll v,ll l,ll r){
    if(!z[v])return;
    z[lv[v]]=z[rv[v]]=z[v];
    ll mid=(r+l)>>1;
    st[lv[v]]=(mid-l+1);
    st[rv[v]]=(r-mid);
    z[v]=0;
}
void upd(ll v,ll l,ll r,ll x,ll y,ll sum){
    if(l>y||x>r)return;
    if(x<=l&&r<=y){
        st[v]+=sum*(r-l+1);
        z[v]=sum;
        return;
    }
    if(!lv[v])lv[v]=++timer;
    if(!rv[v])rv[v]=++timer;
    push(v,l,r);
    ll mid=(r+l)>>1;
    upd(lv[v],l,mid,x,y,sum);
    upd(rv[v],mid+1,r,x,y,sum);
    st[v]=st[lv[v]]+st[rv[v]];
}
ll get(ll v,ll l,ll r,ll x,ll y){
    if(x>r||l>y)return 0;
    if(x<=l&&r<=y)return st[v];
    if(!rv[v])rv[v]=++timer;
    if(!lv[v])lv[v]=++timer;
    push(v,l,r);
    ll mid=(r+l)>>1;
    return get(lv[v],l,mid,x,y)+get(rv[v],mid+1,r,x,y);
}
ll intersection(ll l,ll r,ll x,ll y){
    return max(0,min(r,y)-max(x,l)+1);
}
bool merge(ll i,ll j){
    if(intersection(v[i].l,v[i].r,v[j].l,v[j].r)){
        v[i].l=min(v[i].l,v[j].l);
        v[i].r=max(v[i].r,v[j].r);
        v[j].r=-1;
        v[j].l=0;
        return 1;
    }
    return 0;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>q;
    for(ll i=1;i<=n;i++){
        cin>>v[i].r>>v[i].l;
    }
    sort(v.begin()+1,v.begin()+1+n);
    for(ll i=1;i<=n;i++){
        swap(v[i].l,v[i].r);
        //cout<<v[i].l<<' '<<v[i].r<<'\n';
        while(sz&&merge(i,sta[sz])){
            --sz;
        }
        sta[++sz]=i;
    }
    for(auto k:v){
        upd(1,1,1e9,k.l,k.r,1);
    }
    for(ll i=1;i<=q;i++){
        ll l,r;
        cin>>l>>r;
        cout<<get(1,1,1e9,l,r)<<'\n';
    }
}
