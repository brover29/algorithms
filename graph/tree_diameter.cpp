#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n,dist[300100];
vector<ll>g[300100];
pair<ll,ll> dfs(ll v,ll h=0,ll p=0){
    ll mx=h;
    dist[v]=max(dist[v],h);
    ll mxn=v;
    for(ll to:g[v]){
        if(to!=p){
            pair<ll,ll> m=dfs(to,h+1,v);
            if(m.first>mx){
                mx=m.first;
                mxn=m.second;
            }
        }
    }
    return {mx,mxn};
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
    ll m=dfs(dfs(dfs(1).second).second).first;
    for(ll i=1;i<=n;i++){
        cout<<max(m,dist[i]+1)<<'\n';
    }
}
