#include <bits/stdc++.h>
//qwerty47924692
using namespace std;
using ll = long long;
const ll N=2e5+4;
ll n,sz[N];
vector<ll>g[N];
void dfs(ll v,ll p=0){
    for(ll to:g[v]){
        if(to==p)continue;
        dfs(to,v);
        sz[v]+=sz[to];
    }
    sz[v]++;
}
ll centroedy(ll v){
    for(ll to:g[v]){
        if(sz[to]>sz[v])continue;
        if(sz[to]>(n)/2){
            return centroedy(to);
        }
    }
    return v;
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
    dfs(1);
    /*for(ll i=1;i<=n;i++){
        cout<<sz[i]<<' ';
    }*/
    cout<<centroedy(1);

}
