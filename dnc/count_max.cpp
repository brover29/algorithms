#include <bits/stdc++.h>
//qwerty47924692
using namespace std;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using ll = long long;
const ll N=1e6+29;

ll n,pref[N],suff[N],a[N],sum[N];
ll mxx(ll l,ll r){
    if(l==r){
        return a[l];
    }
    ll mid=(r+l)>>1;
    ll ans=0;
    ans+=mxx(l,mid);
    ans+=mxx(mid+1,r);
    suff[mid+1]=-1e18;
    for(ll i=mid;i>=l;i--)suff[i]=max(suff[i+1] ,a[i]);
    sum[l-1]=0;
    for(ll i=l;i<=mid;i++)sum[i]=sum[i-1]+suff[i];
    pref[mid]=-1e18;
    for(ll i=mid+1;i<=r;i++)pref[i]=max(pref[i-1],a[i]);
    ll j=mid;
    for(ll i=mid+1;i<=r;i++){
        while(j>=l&&suff[j]<=pref[i])j--;
        ans+=sum[j];
        ans+=(mid-j)*pref[i];
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }ll ans=0;
    ans+=mxx(1,n);
    for(ll i=1;i<=n;i++){
        a[i]*=-1;
    }
    ans+=mxx(1,n);
    cout<<ans;

}
