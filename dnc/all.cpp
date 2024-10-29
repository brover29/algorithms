#include <bits/stdc++.h>
//code by BROVER29
#pragma ("reroll")
#pragma GCC target( "sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
using namespace std;
using ll = long long;
const ll N=2e5+29;
const ll M=5e3+3;
const int MOD=998244353;
const int MOD1=1e9+7;
const int INF=1e9;
#define sz(a) a.size()
#define all(a) (a.begin(),a.end())
#define no {cout<<"NO"; return;}
#define yes {cout<<"YES"; return;}
#define f first
#define s second
#define pb push_back()
void dfs(ll v,ll p=0){
    sz[v]=1;
    for(ll to:g[v]){
        if(to==p||used[to])continue;
        dfs(to,v);
        sz[v]+=sz[to];
    }
}
ll centroedy(ll v,ll ssz,ll p=0){
    for(ll to:g[v]){
        if(to==p||used[to])continue;
        if(sz[to]>(ssz)/2){
            return centroedy(to,ssz,v);
        }
    }
    return v;
}
void add(ll v,ll p,ll d){
    if(k<d)return;
    ans+=cnt[k-d];
    for(ll to:g[v]){
        if(to==p||used[to])continue;
        add(to,v,d+1);
    }
}void upd(ll v,ll p,ll d){
    if(d>k)return;
    cnt[d]++;
    for(ll to:g[v]){
        if(to==p||used[to])continue;
        upd(to,v,d+1);
    }
}
void solve(ll v){
    dfs(v,0);
    ll ssz=sz[v];
    if(ssz<k)return;
    v=centroedy(v,ssz);
    used[v]=1;
    cnt[0]=1;
    for(ll to:g[v]){
        if(!used[to]){
            add(to,v,1);
            upd(to,v,1);
        }
    }
    for(ll i=0;i<=k;i++)cnt[i]=0;
    for(ll to:g[v]){
        if(!used[to])solve(to);
    }
}
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
}void dfs(ll v,ll p){
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

void solve(){


}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t;

    cin>>t;
    while(t--){
        solve();
        cout<<'\n';
    }
}
