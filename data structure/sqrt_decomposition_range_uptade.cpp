#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N=1e5;
ll a[N],n,m,b[N],z[N],k;
void push(ll bl){
    if(!z[bl])return;
    for(ll i=bl*k;i<bl*(k+1);i++)a[i]=z[bl];
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    k=sqrt(n)+1;
    for(ll i=1;i<=n;i++)cin>>a[i],b[i/k]+=a[i];
    while(m--){
        ll t,l,r,x;
        cin>>t>>l>>r;
        ll bl=l/k;
        ll br=r/k;
        push(bl);
        push(br);
        if(t==1){
            ll sum=0;
            if(bl==br){
                for(ll i=l;i<=r;i++)sum+=a[i];
            }
            else{
                for(ll i=l;i<bl*(k+1);i++)sum+=a[i];
                for(ll i=bl+1;i<br;i++)sum+=b[i];
                for(ll i=br*k;i<=r;i++)sum+=a[i];
            }
            cout<<sum<<'\n';
            continue;
        }
        cin>>x;
        if(bl==br){

            for(ll i=l;i<=r;i++){
                b[bl]-=a[i];
                a[i]=x;
                b[bl]+=a[i];
            }
        }
    }
}
