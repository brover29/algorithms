#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
using ll = long long;
vector<pair<ll,ll>>g[100100];
ll n,m,tin[100100],fup[100100],used[100100],timer;
set<ll>b;
void dfs(ll v,ll p){
    used[v]=1;
    tin[v]=++timer;
    fup[v]=tin[v];
    ll children=0;
    for(auto to:g[v]){
        if( to.s != p ) {
            if(!used[to.f]){
                dfs(to.f,to.s);
                fup[v] = min(fup[to.f],fup[v]);
                if( tin[v] <= fup[to.f] &&p!=-1) {
                    b.insert(v);
                }
                children++;
            }
            else{
                fup[v]=min(fup[v],tin[to.f]);
            }
        }

    }
    if(p==-1&&children>1){
        b.insert(v);
    }
    //cout<<v<<' '<<tin[v]<<' '<<fup[v]<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    for(ll i=1;i<=m;i++){
        ll u,v;
        cin>>u>>v;
        g[u].push_back({v,i});
        g[v].push_back({u,i});
    }
    for(ll i=1;i<=n;i++){
        if(!used[i]){
            dfs(i,-1);
        }
    }
    cout<<b.size()<<'\n';
    for(auto e:b){
        cout<<e<<'\n';
    }
}
