#include <bits/stdc++.h>
//qwerty47924692
using namespace std;
using ll = long long;
#define l first
#define r second
const ll N=2e5+29;
ll n,m,t,tin[N],fup[N],timer,used[N],sz[N];
set<ll>b;
struct edge{
    ll u,w,i;
};
vector<edge>g[N];
map<ll,ll>mp;
void dfs_find_bridge(ll v,ll p=0){
    used[v]=1;
    tin[v]=fup[v]=++timer;
    for(auto [to,w,i]:g[v]){
        if(to==p)continue;
        if(used[to]){
            fup[v]=min(fup[v],tin[to]);
            continue;
        }
        dfs_find_bridge(to,v);
        fup[v]=min(fup[v],fup[to]);
        if(tin[v]<fup[to]){
          //  cout<<v<<' ' <<to<<'\n';
            b.insert(i);
        }
    }
}
vector<pair<ll,ll>>gr[N];
void dfs_compress(ll v,ll color){
    used[v]=color;
    sz[color]++;
    for(auto [to,w,i]:g[v]){
        if(used[to]&&used[to]!=used[v]){
            gr[color].push_back({used[to],w});
            gr[used[to]].push_back({color,w});
            continue;
        }
        if(used[to]||mp[i])continue;
        dfs_compress(to,color);
    }

}

ll d[N];

void dfs(ll v,ll p=0){
    for(auto [to,w]:gr[v]){
        if(to==p)continue;
        d[to]=d[v]+w;
        dfs(to,v);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m>>t;
    for(ll i=1;i<=m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        u++;
        v++;
        g[u].push_back({v,w,i});
        g[v].push_back({u,w,i});
    }
    dfs_find_bridge(1);
    for(ll i:b){
        mp[i]=1;
    }
    ll c=0;
    ll ans=0;
    for(ll i=1;i<=n;i++)used[i]=0;
    for(ll i=1;i<=n;i++){
        if(!used[i]){
            dfs_compress(i,++c);
        }
    }
    for(ll i=1;i<=c;i++){
        for(ll i=1;i<=c;i++)d[i]=0;
        ans+=(sz[i]*(sz[i]-1)/2);
       // cout<<(sz[i]*(sz[i]-1)/2)<<' ';
        dfs(i);
        for(ll j=1;j<i;j++){
            if(i==j||d[j]>t)continue;
           // cout<<'\n'<<i<<' '<<d[j]<<'\n';
            ans+=sz[i]*sz[j];
        }
    }
    cout<<ans;

}
