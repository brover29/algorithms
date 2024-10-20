using ll = long long;
const ll N=1e5;
ll v[N],h[N],n,x,f[N];
vector<ll>g[N];
void dfs(ll v,ll p,ll hi=1){
    for(ll to:g[v]){
        if(to!=p){
            v[++x]=to;
            f[to]=x;
            h[x]=hi;
            dfs(to,v,hi+1);
        }
    }
    v[++x]=p;
    h[x]=hi-1;
}
ll get_lca(ll x,ll y){
    return min_high(f[x],f[y]);
}
