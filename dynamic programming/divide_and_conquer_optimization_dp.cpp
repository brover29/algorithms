#include <bits/stdc++.h>
//code by BROVER29
using namespace std;
using ll = int;
const ll N=4004;



ll n,u[N][N],ans,k,sum[N][N],dp[N][N];
void solve(ll l,ll r,ll tl,ll tr,ll k){
    if(l>r) return;
    ll mid=(r+l)>>1;
    pair<ll,ll>cur={1e8,1e8};

    for(ll j=tl;j<=tr;j++){
        if(j>mid)break;
        cur=min(cur,{dp[j-1][k-1]+sum[j][mid],j});
    }
    dp[mid][k]=cur.first;
    solve(l,mid-1,tl,cur.second,k);
    solve(mid+1,r,cur.second,tr,k);

}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //cin.eof();

    cin>>n>>k;
    string sm;
    getline(cin,sm);
    for(ll i=1;i<=n;i++){
        string s;
        getline(cin,s);
        ll k=0;
        for(char c:s){
            if(c==' ')continue;
            u[i][++k]=c-'0';
        }
    }
    for(ll len=2;len<=n;len++){
        for(ll l=1;l+len-1<=n;l++){
            ll r=l+len-1;
            sum[l][r]=sum[l+1][r]+sum[l][r-1]-sum[l+1][r-1]+u[l][r];
        }
        dp[len][1]=sum[1][len];
    }
    //for(ll i=1;i<=n;i++)dp[i][1]=sum[1][i];
    for(ll i=2;i<=k;i++){
        solve(i,n,i,n,i);
        //break;
    }
    //cout<<dp[3][1]<<' '<<dp[6][2]<<' '<<dp[8][3];
    cout<<dp[n][k];
}

