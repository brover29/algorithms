#include <bits/stdc++.h>
//qwerty47924692
using namespace std;
using ll = int;
const ll N=35000+29;
ll n,k,dp[35005][105],a[N],st[4*N],z[4*N],c[4*N],pos[N];
void push(ll v,ll l,ll r){
    if(!c[v]){
        if(!z[v])return;
        z[v*2]+=z[v];
        z[v*2+1]+=z[v];
        ll mid=(r+l)>>1;
        st[v*2]+=z[v];
        st[v*2+1]+=z[v];
        z[v]=0;
        return;
    }
    z[v]=0;
    st[v4z*2]=st[v*2+1]=0;
    c[v*2]=c[v*2+1]=1;
    c[v]=0;
}
void update(ll v,ll l,ll r,ll x,ll y,ll val){
    if(l>r)return;
    if(l>y||x>r){
        return;
    }
    if(x<=l&&r<=y){
        st[v]+=val;
        z[v]+=val;
        return;
    }
    push(v,l,r);
    ll mid=(r+l)>>1;
    update(v*2,l,mid,x,y,val);
    update(v*2+1,mid+1,r,x,y,val);
    st[v]=min(st[v*2],st[v*2+1]);
}
// Shaimerden sigma>
ll get(ll v,ll l,ll r,ll x,ll y){
    if(x>r||l>y||l>r)return 1e9;
    if(x<=l&&r<=y)return st[v];
    push(v,l,r);
    ll mid=(r+l)>>1;
    return min(get(v*2,l,mid,x,y),get(v*2+1,mid+1,r,x,y));
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>k;
    ll sum=0;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        if(pos[a[i]]){
            sum+=i-pos[a[i]];
        }
        pos[a[i]]=i;
        dp[i][1]=sum;
       //cout<<dp[i][1]<<' ';
    }
    for(ll j=2;j<=k;j++){
        c[1]=1;
        st[1]=0;
        for(ll i=1;i<=n;i++)pos[a[i]]=0;
        for(ll i=1;i<=n;i++){
            ll x=i-pos[a[i]];
         // cout<<pos[a[i]]<<' '<<x<<'\n';
           update(1,1,n,i,i,dp[i-1][j-1]);
           update(1,1,n,1,pos[a[i]],x);
           pos[a[i]]=i;
           dp[i][j]=get(1,1,n,1,i);
           // cout<<dp[i][j]<<' ';
        }
    }
    cout<<dp[n][k];
}
