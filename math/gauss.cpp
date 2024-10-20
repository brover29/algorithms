#include <bits/stdc++.h>
//qwerty47924692
using namespace std;
using ll = long long;
const ll N=2e5+29;
ll n,m;
long double a[1000][1000];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m+1;j++){
            cin>>a[i][j];
        }
    }
    for(ll i=1;i<=m;i++){
        for(ll j=i;j<=n;j++){
            if(a[j][i]){
                for(ll x=1;x<=m;++){
                    swap(a[i][x],a[j][x]);
                }
            }

        }
        for(ll j=1;j<=n;j++){
            if(j!=i){
                long double x=a[j][i]/a[i][i];
                for(ll k=1;k<=m;k++){
                    a[j][k]-=a[i][k]*x;
                }
            }
        }
    }

}
