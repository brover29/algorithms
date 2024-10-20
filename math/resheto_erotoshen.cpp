#include <bits/stdc++.h>
//qwerty47924692
using namespace std;
using ll = long long;
const ll N=2e5+29;
const string br="617283";
ll n,d[N];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(ll i=1;i<N;i++){
        for(ll j=i+i;j<N;j+=i){
            d[j]++;
        }
    }
}

