#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N,W,w[1001],dp[1010];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>N>>W;
    dp[0]=1;
    dp[1]=0;
    for(ll i=1;i<=N;i++)cin>>w[i];
    for(ll i=1;i<=N;i++){
        for(ll j=W;j>=w[i];j--){
            dp[j]|=dp[j-w[i]];
        }
    }
    for(ll j=W;j>=0;j--){
        if(dp[j]){cout<<j;return 0;}
    }
}
