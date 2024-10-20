#include <bits/stdc++.h>
//qwerty47924692
using namespace std;
using ll = long long;
const ll N=3e5+29;
ll n,a[N],lg[N],ans;
pair<ll,ll>mx[N][20],mn[N][20];
void build(){
    lg[1]=0;
    for(ll i=2;i<=n;i++){
        lg[i]=lg[i/2]+1;
        //cout<<lg[i]<<' ';
    }
    for(ll j=1;j<=19;j++){
        ll k(1ll<<j);
        for(ll i=k-1;i<=n;i++){
            mn[i][j]=min(mn[i][j-1],mn[i-k/2][j-1]);
            mx[i][j]=max(mx[i][j-1],mx[i-k/2][j-1]);
        }
    }
}
pair<ll,ll> get(ll l,ll r,ll t){
    ll j=lg[r-l+1];
    ll k=(1ll<<j);
    auto minn=min(mn[r][j],mn[l+k-1][j]);
    auto maxx=max(mx[r][j],mx[l+k-1][j]);
    return (t == 1? minn : maxx);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        mn[i][0]={a[i],i};
        mx[i][0]={a[i],i};
    }
    build();
    for(ll i=1;i<=n;i++){
        ll l=i,r=n;
        while(l<r){
            ll mid=(r+l+1)>>1;
            if(get(i,mid,1).first!=a[i])r=mid-1;
            else l=mid;
        }
        auto maxx=get(i,l,0);
      //  cout<<mx[6][lg[6-3+1]].first<<'\n';
        ans++;
        i=maxx.second;
       // cout<<get(1,n,1).first <<' ';
    }
    cout<<ans;
}
