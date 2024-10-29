#include <bits/stdc++.h>
//code by BROVER29

using namespace std;
using ll = int;
#define f first
#define s second
const ll N=1e6+29;
const ll M=5e3+3;
ll n,a[20][20];
pair<ll,ll>dp[20][N];
void solve(){
    cin>>n;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            cin>>a[i][j];
        }
        for(ll mask=0;mask<(1ll<<n);mask++){
            dp[i-1][mask]={1e18,-1};
        }
        dp[i-1][(1ll<<(i-1))]={0,-1};
    }

    for(ll mask=0;mask<(1ll<<n);mask++){
        for(ll i=0;i<n;i++){
            if(!((mask>>i)&1)){
                continue;
            }
            for(ll j=0;j<n;j++){
                if(!((mask>>j)&1)){
                    if(dp[j][mask+(1ll<<j)].f>a[i+1][j+1]+dp[i][mask].f){
                        dp[j][mask+(1ll<<j)].f=a[i+1][j+1]+dp[i][mask].f;
                        dp[j][mask+(1ll<<j)].s=i;
                    }
                }
            }
        }
    }
    ll ans=1e18,x=-1;;
    for(ll i=1;i<=n;i++){
        if(ans>dp[i-1][(1ll<<(n))-1].f){
            ans=dp[i-1][(1ll<<(n))-1].f;
            x=i-1;
        }
    }
    cout<<ans<<'\n';
    ll mask=((1ll<<n)-1);
    for(ll i=1;i<=n;i++){
        cout<<x+1<<' ';
        ll old=x;
        x=dp[x][mask].s;
        mask-=(1ll<<old);
    }

}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("aquarium.in","r",stdin);
    freopen("aquarium.out","w",stdout);

    solve();
}
