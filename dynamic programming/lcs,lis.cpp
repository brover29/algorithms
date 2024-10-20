#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n,m,a[100100],b[100100];
ll dp[3000][3000];
ll lcs(){
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            dp[i][j]=0;

            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            if(a[i]==b[j]){
                dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
            }
        }
    }
    return dp[n][m];
}
ll lis(){
    ll dp[3000];
    dp[1]=1;
    for(ll i=2;i<=n;i++){
        dp[i]=1;
        for(ll j=1;j<i;j++){
            if(a[i]>a[j]){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
    }
    return dp[n];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(ll i=1;i<=n;i++)cin>>a[i];
    cin>>m;
    for(ll i=1;i<=m;i++) cin>>b[i];
    cout<<lcs()<<lis();
}
