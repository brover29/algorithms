#include <bits/stdc++.h>
//code by BROVER29
using namespace std;
using ll = int;
const ll N=2e5+29;
const ll M=1e3+3;
const ll mod=1e9+7;
#define no {cout<<"NO"; return;}
#define yes {cout<<"YES"; return;}
#define f first
#define s second
#define pb push_back()

ll n,m,dp[M][M],a[M],opt[M][M];
void solve(ll n,ll m){

   // cin>>n>>m;
    a[m+1]=n;
    a[0]=0;
    for(ll i=1;i<=m;i++){
        cin>>a[i];
        opt[i][i+1]=i;
     //   dp[i-1][i]=a[i]-a[i-1];
    }

   // dp[m][m+1]=a[m+1]-a[m];

    for(ll len=3;len<=m+2;len++){
        for(ll l=0;len+l-1<=m+1;l++){
            ll r=l+len-1;
            dp[l][r]=1e9;
            //ll tl,tr;
            ll tl=opt[l][r-1];
            ll tr=opt[l+1][r];
            if(len==3){
                tl=l+1;
                tr=r-1;
            }
            for(ll j=tl;j<=tr;j++){
                ll cur=dp[l][j]+dp[j][r]+a[r]-a[l];
                if(cur<dp[l][r]){
                    opt[l][r]=j;
                    dp[l][r]=cur;
                }
                //cout<<l<<' '<<r<<' '<<cur<<' ';
            }
           // cout<<'\n';

        }
    }
    cout<<dp[0][m+1];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin.eof();

    ll t=100;
    while(cin>>n>>m){
        solve(n,m);
        cout<<'\n';
    }
}


