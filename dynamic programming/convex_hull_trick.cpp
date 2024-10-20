#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define f first
#define s second
const ll N=1e6+29;
ll n,sz,dp[N];
pair<ll,ll> a[N],b[N];
struct line{
    ll k,b;
    ll get(ll x){
        return k*x+b;
    }
}st[N];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>a[i].f>>a[i].s;
        dp[i]=1e18;
    }
    sort(a+1,a+1+n);
    set<ll> s;
    for(ll i=n;i>=1;i--){
        if(s.empty()){
            b[++sz]={a[i].f,a[i].s};
            s.insert(a[i].s);
            continue;
        }
        auto x=*(--s.end());
        if(x<a[i].s){
            b[++sz]={a[i].f,a[i].s};
            s.insert(a[i].s);
        }
    }
    n=sz;
    sz=0;
    ll r=1;
    sort(b+1,b+1+n);
    for(ll i=1;i<=n;i++) a[i]=b[i];
    for(ll i=1;i<=n;i++){
        ll k=a[i].s;
        ll b=dp[i-1];
        while(sz>1&&(b-st[sz-1].b)*(st[sz-1].k-st[sz].k)<=(st[sz].b-st[sz-1].b)*(st[sz-1].k-k))sz--;
        st[++sz]={k,b};
        r=min(r,sz);
        while(r<sz&&st[r].get(a[i].f)>=st[r+1].get(a[i].f))r++;
        dp[i]=st[r].get(a[i].f);
    }
    cout<<dp[n]<<'\n';
    return 0;
}

