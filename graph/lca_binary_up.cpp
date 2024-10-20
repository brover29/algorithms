#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n,m,tin[200100],tout[200100],p[30][200100],ans,cnt[200100];
vector<ll>g[200100];
ll timer=0;
void dfs(ll v,ll pr){
    p[0][v]=pr;
    if(!pr){
        p[0][v]=v;
    }
    for(ll i=1;i<=29;i++){
        p[i][v]=p[i-1][p[i-1][v]];
    }
    tin[v]=++timer;
    for(ll to:g[v]){
        if(to!=pr){
            dfs(to,v);
        }
    }
    tout[v]=timer;
}
bool is_parent(ll x,ll y){
    return (tin[x]<=tin[y]&&tout[y]<=tout[x]);
}
ll get_lca(ll x,ll y){
    ll lca=x;
    for(ll i=29;i>=0;i--){
        if(!is_parent(p[i][lca],y)){
            lca=p[i][lca];
        }
    }
    if(!is_parent(x,y)){
        return p[0][lca];
    }
    return lca;
}
void get_ans(ll v,ll pr){
    for(ll to:g[v]){
        if(to!=pr){
            get_ans(to,v);
        }
    }
    if(cnt[v]>1)cnt[pr]+=cnt[v]-1;
    if(cnt[v]>=1)ans++;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    for(ll i=1;i<n;i++){
        ll u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    cin>>m;
    for(ll i=1;i<=m;i++){
        ll x,y;
        cin>>x>>y;
        ll lca=get_lca(x,y);
        cnt[lca]++;
        //cout<<lca<<' ';
    }
    get_ans(1,0);
    cout<<ans;
}
