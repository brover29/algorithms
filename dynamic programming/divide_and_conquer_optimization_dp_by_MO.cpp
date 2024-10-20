#include <bits/stdc++.h>
//qwerty47924692
using namespace std;
using ll = long long;
#define f first
#define s second
const ll N=2e5+29;
ll dp[N][30],n,K,cnt[N],a[N],st[4*N],L,R,sum;
void add(ll x){
	sum+=cnt[x];
	cnt[x]++;
}
void del(ll x ){
	cnt[x]--;
	sum-=cnt[x];
}
void solve(ll l,ll r,ll tl,ll tr,ll k){
    if(l>r)return;
    ll mid=(r+l)>>1;
    pair<ll,ll>cur{1e18,8};
    for(ll i=tl;i<=tr;i++){
        if(i>mid) break;

		while(L>i)add( a[--L]);
		while(R<mid)add( a[++R]);
		while(L<i)del(a[L++]);
		while(R>mid)del(a[R--]);
		cur=min(cur,{dp[i-1][k-1]+sum,i});
    }
    dp[mid][k]=cur.f;

    solve(l,mid-1,tl,cur.s,k);
    solve(mid+1,r,cur.s,tr,k);

}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>K;
    for(ll i=1;i<=n;i++)cin>>a[i],dp[i][0]=1e18;
    dp[0][0]=0;
    for(ll k=1;k<=K;k++){
        L=1,R=0;
        for(ll i=1;i<=n;i++)cnt[a[i]]=0;
        solve(k,n,k,n,k);
    }
    cout<<dp[n][K];
}

