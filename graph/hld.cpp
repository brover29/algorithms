#include <bits/stdc++.h>
//qwerty47924692
using namespace std;
using ll = int;
const ll N=2e5+29;
ll n,q,tin[N],st[(1<<20)],h[N],d[N],sz[N],p[N],a[N],timer,pos[N],mx[N];
vector<ll>g[N];

void dfs1(ll v,ll pr=1){
    sz[v]=1;
    p[v]=pr;
    for(ll to:g[v]){
        if(to==pr)continue;
        d[to]=d[v]+1;
        dfs1(to,v);
        sz[v]+=sz[to];
        if(sz[to]>sz[mx[v]])mx[v]=to;
    }
}
void dfs2(ll v,ll head=0){
    if(!head)head=v;
    h[v]=head;
    tin[v]=++timer;
    pos[tin[v]]=v;
    for(ll to:g[v]){

        if(mx[v]==to){
           // cout<<v<<' '<<to<<'\n';
            dfs2(to,head);
        }
    }
    for(ll to:g[v]){
        if(mx[v]!=to&&to!=p[v]){
            dfs2(to);
        }
    }
}
void update(int pos, int val) {
    st[pos += n] = val;
    for (pos /= 2; pos; pos /= 2) {
        st[pos] = max(st[pos + pos], st[pos + pos + 1]);
    }
}

int get(int lo, int hi) {
  int ra = 0, rb = 0;
  for (lo += n, hi += n + 1; lo < hi; lo /= 2, hi /= 2) {
    if (lo & 1) ra = max(ra, st[lo++]);
    if (hi & 1) rb = max(rb, st[--hi]);
  }
  return max(ra, rb);
}
ll query(ll a,ll b){
    ll res=0;
    for(;h[a]!=h[b];b=p[h[b]]){
        if(d[h[a]]>d[h[b]])swap(a,b);
        res=max(res,get(tin[h[b]],tin[b]));
     //   cout<<tin[h[b]]<<' '<<tin[b]<<' '<<get(1,1,n,tin[h[b]],tin[b])<<'\n';
    }
    if(d[a]>d[b])swap(a,b);
    return max(res,get(tin[a],tin[b]));
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>q;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    for(ll i=1;i<n;i++){
        ll u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs1(1);
    dfs2(1);
    for(ll i=1;i<=n;i++){
        update(tin[i],a[i]);
    }
   /* for(ll i=1;i<=n;i++){
        cout<<h[i]<<' ';
    }*/
    while(q--){
        ll t,l,r;
        cin>>t>>l>>r;
        if(t==1){
            update(tin[l],r);
        }
        else{
            cout<<query(l,r)<<' ';
        }
    }
}

