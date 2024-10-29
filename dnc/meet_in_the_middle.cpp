#include <bits/stdc++.h>
//qwerty47924692
using namespace std;
using ll = int;
const ll N=42;
ll n,a[N],s;
long long ans;
map<ll,long long>mp;
void f1(ll x,ll sum=0){
    if(x==n/2){
        mp[sum]++;
        return;
    }
    x++;
    if(sum+a[x]<=s)f1(x,sum+a[x]);
    f1(x,sum);
}
void f2(ll x,ll sum=0){
    if(x==n){
        ans+=mp[s-sum];
        return;
    }
    x++;
    if(sum+a[x]<=s)f2(x,sum+a[x]);
    f2(x,sum);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>s;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    f1(0);
    f2(n/2);
    cout<<ans;
}
