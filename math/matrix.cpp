#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define sz(a) a.size()
#define se second
#define fi first

const int N=5e5+5;
const int MOD1=998244353;
const int MOD2=1e9+7;
const int INF=1e9;

ll a[5][7],n,ans[7][5],MOD,A;
ll b[5][5];
ll res[5][5];

void bin(){
    while(n){
        if(n & 1){
            for(int i=1;i<=2;i++){
                for(int j=1;j<=2;j++){
                    for(int k=1;k<=2;k++){
                        res[i][j]+=ans[i][k]*a[k][j];
                        res[i][j]%=MOD;

                    }
                }
            }
            for(int i=1;i<=2;i++){
                for(int j=1;j<=2;j++){
                    ans[i][j]=res[i][j];
                    res[i][j]=0;
                }
            }
            n--;
        }
        for(int i=1;i<=2;i++){
            for(int j=1;j<=2;j++){
                for(int k=1;k<=2;k++){
                    b[i][j]+=a[i][k]*a[k][j];
                    b[i][j]%=MOD;
                }
            }
        }
        for(int i=1;i<=2;i++){
            for(int j=1;j<=2;j++){
                a[i][j]=b[i][j];
                b[i][j]=0;
            }
        }
        n/=2;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>A>>n>>MOD;
    if(n==1){
        cout<<1;
        return 0;
    }
    n-=2;
    a[1][1]=A;
    a[2][1]=a[2][2]=ans[1][1]=ans[1][2]=ans[2][1]=ans[2][2]=1;
    bin();
    cout<<(ans[2][1]*A+ans[2][2])%MOD;

    return 0;
 }
