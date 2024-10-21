#include <bits/stdc++.h>
//qwerty47924692
using namespace std;
using ll = long long;
const ll N=1e6+29;
const string br="617283";

ll n,m,a[N];
deque<ll>d;
string s;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    cin>>m;
    while(m--){
        ll t;
        cin>>t;
        if(t==1){
            ll x;
            cin>>x;
            a[++n]=x;
            if(d.empty()||x<a[d.front()]){
                d.push_front(n);
                continue;
            }

            continue;
        }if(t==2){
            if(d.front()==n){
                d.pop_front();

            }
            n--;
            continue;
        }if(t==3){
            cout<<a[d.front()]<<'\n';
        }
    }
}
