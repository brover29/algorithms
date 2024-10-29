#include <bits/stdc++.h>
//qwerty47924692
using namespace std;
using ll = long long;
const ll N=1e5;

ll n,a[N],pref[N],q;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    srand(time(0));

    cin>>n>>q;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        pref[i]=pref[i-1]+a[i];
    }
    while(q--){
        ll l,r;
        cin>>l>>r;
        cout<<pref[r]-pref[l-1]<<'\n';
    }

}
