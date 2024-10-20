#include <bits/stdc++.h>
//qwerty47924692
using namespace std;
using ll = long long;
const ll N=2e5+29;
ll n,m,used[N],type[N],colour[N],comp[N];
vector<ll>g[N],topsort,add,gg[N];
void dfs(ll v){
    used[v]=1;
    for(ll to:g[v]){
        if(!used[to])dfs(to);
    }
    topsort.push_back(v);
}
void paint(ll v,ll k){
    comp[v]=k;
    for(ll to:g[v]){
        if(!comp[to])paint(to,k);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    for(ll i=1;i<=m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        if(w==0){
            g[u].push_back(v+n);
            g[v].push_back(u+n);
            g[u+n].push_back(v);
            g[v+n].push_back(u);
        }
        else{
            g[u].push_back(v);
            g[v].push_back(u);
            g[u+n].push_back(v+n);
            g[v+n].push_back(u+n);
        }
    }
    for(ll i=1;i<=n+n;i++){
        if(!used[i])dfs(i);
    }
    reverse(topsort.begin(),topsort.end());
   // for(ll i=1;i<=n;i++)used[i]=0;
   ll k=0;
    for(ll i:topsort){
        if(!comp[i])paint(i,++k);
    }
    for(ll i=1;i<=n;i++){


        if(comp[i]>comp[i+n]){
            add.push_back(i);
        }
        if(comp[i]==comp[i+n]){
            cout<<"Impossible";
            return 0;
        }
    }
    if(add.size()>n)cout<<"Impossible";
    else{
        cout<<add.size()<<'\n';
        for(ll i:add){
            cout<<i<<' ';
        }
    }

}
