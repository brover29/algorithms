ll n,m,used[N];
vector<ll>g[N];
void dfs(ll v){
    used[v]=1;
    for(ll to:g[v]){
        if(used[to])continue;
        dfs(to);
    }
}
ll d[N];
void bfs(ll s){
    queue<ll>q;
    q.push(s);
    d[s]=1;
    while(q.size()){
        ll v=q.front();
        q.pop();
        for(ll to:g[v]){
            if(!d[to]){
                d[to]=d[v]+1;
                q.push(to);
            }
        }
    }
}
