
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll mod=1e9+7;

ll dp[200][200];
string s;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>s;
    ll n = s.size();
    s = ' ' + s;
    for(ll i = 1; i <= n ; i++ )
    {
        dp[i][i]=1;
    }
    for(ll len = 1; len <= n ; len++ )
    {
        for(ll l = 1 ; l + len - 1 <= n ; len++ )
        {
            ll r = l + len - 1; // r-l+1==len
            dp[l][r] = max( { dp[l][r-1] , dp[l+1][r] , dp[l+1][r-1] } ) ;
            if( s[l] == s[r] && dp[l+1][r-1] == ( r - l - 1 ) )
            {
                dp[l][r] = max( dp[l][r] , dp[l+1][r-1] + 1 );
            }
        }
    }
    cout<<dp[1][n] ;

    return 0;
}
