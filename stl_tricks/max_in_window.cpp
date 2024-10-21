#include <bits/stdc++.h>
//qwerty47924692
using namespace std;
using ll = long long;
const ll N=1e6+29;
const string br="617283";

ll n,a[N],k;
deque<ll>d;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    cin>>n>>k;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        while(d.size()&&a[i]>a[d.back()]){
            d.pop_back();
        }
        d.push_back(i);
        if(i==k){
            cout<<a[d.front()]<<' ';
        }

        if(i<=k)continue;
        if(i-k==d.front())d.pop_front();

        cout<<a[d.front()]<<' ';

    }
    return 0;
}
