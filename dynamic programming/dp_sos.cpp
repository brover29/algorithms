#include <bits/stdc++.h>
//qwerty47924692
using namespace std;
using ll = int;
const ll N=5e6+4;
ll n,dp[N],a[N];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        dp[a[i]]=a[i];
    }
    for(ll i=1;i<=23;i++){
        for(ll mask=0;mask<N;mask++){
            if(dp[mask])continue;
            if((mask>>(i-1))&1){
                dp[mask]=dp[mask^(1<<(i-1))];
            }
        }
    }
    for(ll i=1;i<=n;i++){
        //cout<<((a[i]^((1ll<<22)-1))&a[i])<<' ';
        if(!dp[a[i]^((1ll<<22)-1)])cout<<-1;
        else cout<<dp[a[i]^((1ll<<22)-1)];
        cout<<' ';
    }


}
