#include <bits/stdc++.h>
//qwerty47924692
using namespace std;
using ll = long long;
const ll N=2e5+29;
ll n,k,used[N],sz[N],ans,cnt[N];
vector<ll>g[N];
void dfs(ll v,ll p=0){
    sz[v]=1;
    for(ll to:g[v]){
        if(to==p||used[to])continue;
        dfs(to,v);
        sz[v]+=sz[to];
    }
}
ll centroedy(ll v,ll ssz,ll p=0){
    for(ll to:g[v]){
        if(to==p||used[to])continue;
        if(sz[to]>(ssz)/2){
            return centroedy(to,ssz,v);
        }
    }
    return v;
}
void add(ll v,ll p,ll d){
    if(k<d)return;
    ans+=cnt[k-d];
    for(ll to:g[v]){
        if(to==p||used[to])continue;
        add(to,v,d+1);
    }
}void upd(ll v,ll p,ll d){
    if(d>k)return;
    cnt[d]++;
    for(ll to:g[v]){
        if(to==p||used[to])continue;
        upd(to,v,d+1);
    }
}
void solve(ll v){
    dfs(v,0);
    ll ssz=sz[v];
    if(ssz<k)return;
    v=centroedy(v,ssz);
    used[v]=1;
    cnt[0]=1;
    for(ll to:g[v]){
        if(!used[to]){
            add(to,v,1);
            upd(to,v,1);
        }
    }
    for(ll i=0;i<=k;i++)cnt[i]=0;
    for(ll to:g[v]){
        if(!used[to])solve(to);
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>k;
    for(ll i=1;i<n;i++){
        ll u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    solve(1);
    cout<<ans;
}
