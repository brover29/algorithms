#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define sz(a) a.size()
#define se second
#define fi first

const int N=5e5+5;
const int MOD=998244353;
const int MOD1=1e9+7;
const int INF=-1e5;

int n,m,used[N],rused[N];
vector<int>g[N],rg[N],topsort;

void rfs(int v){
    rused[v]=1;
    for(int to:rg[v]){
        if(!rused[to]){
            rfs(to);
        }
    }
    topsort.push_back(v);
}
void dfs(int v,int colour){
    used[v]=colour;
    for(int to:g[v]){
        if(!used[to]){
            dfs(to,colour);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    while(m--){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        rg[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
        if(!rused[i])rfs(i);
    int colour=0;
    reverse(topsort.begin(),topsort.end());
    for(int i:topsort){
        if(!used[i]){
            colour++;
            dfs(i,colour);
        }
    }
    for(int i=1;i<=n;i++)cout<<used[i]<<' ';


    return 0;
 }
