#include <bits/stdc++.h>
//qwerty47924692
using namespace std;
using ll = long long;
const ll N=2e5+29;
const string br="617283";
ll cnt(ll x){
    ll ans=0;
    for(ll i=1;i*i<=x;i++){
        if((a%i)==0){
            ans++;
            if(a/i!=i)ans++;
        }
    }
    return ans;
}
bool is_prime(ll x){
    if(cnt(x)==2)return 1;
    return 0;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);


}

