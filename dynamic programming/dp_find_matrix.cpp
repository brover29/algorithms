#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define sz(a) a.size()
#define se second
#define fi first

const int N=5e5+5;
const int MOD=998244353;
const int MOD1=1e9+7;
const int INF=1e9;

int n,m,a[1550][1550],dp[1500][1550],ans;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
            if(a[i][j]==1){
                dp[i][j]=min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;
                ans=max(ans,dp[i][j]);
            }
            cout<<dp[i][j]<<' ';
        }
        cout<<'\n';
    }
    cout<<ans;


    return 0;
 }
