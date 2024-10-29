#include <bits/stdc++.h>
//code by BROVER29

using namespace std;
using ll = long long;
#define f first
#define s second
const ll N=1e5+29;
const ll M=5e3+3;
ll n,a[N],dp[N],ans,st[4*N];
void update(ll v,ll l,ll r,ll pos,ll val){
    if(l==r){
        st[v]=max(st[v],val);
        return;
    }
    ll mid=(r+l)>>1;
    if(pos<=mid)update(v*2,l,mid,pos,val);
    else update(v*2+1,mid+1,r,pos,val);
    st[v]=max(st[v*2+1],st[v*2]);
}
ll get(ll v,ll l,ll r,ll x,ll y){
    if(l>y||x>r)return 0;
    if(x<=l&&r<=y){

        return st[v];
    }
    ll mid=(r+l)>>1;


    return max(get(v*2,l,mid,x,y),get(v*2+1,mid+1,r,x,y));
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        dp[i]=get(1,1,N-20,1,a[i]-1)+1;
        ans=max(ans,dp[i]);
        update(1,1,N-20,a[i],dp[i]);
    }
    cout<<ans;
}
