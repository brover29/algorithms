#include <bits/stdc++.h>

using ll = long long;
const int N=1e6;
using namespace std;
ll n,m,pr[N],ra[N];
ll fin(ll x){
    if(pr[x]==x)return x;
    return pr[x]=fin(pr[x]);
}
void uni(ll u,ll v){
    u=fin(u);
    v=fin(v);
    if(ra[u]>ra[v])swap(u,v);
    pr[u]=v;
    ra[v]+=ra[u];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;i++)pr[i]=i,ra[i]=1;
    while(m--){
        string t;
        ll u,v;
        cin>>t>>u>>v;
        if(t=="union")uni(u,v);
        else{
            if(fin(u)==fin(v))cout<<"YES";
            else cout<<"NO";
            cout<<'\n';
        }
    }
}
