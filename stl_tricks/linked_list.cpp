#include <bits/stdc++.h>
//qwerty47924692
using namespace std;
using ll = long long;
const ll N=1e6+29;
const string br="617283";

ll n,m,nxt[N],prv[N],ans;
string s;
vector<ll>v;
ll last=0;
void del(ll x,ll y){
    nxt[x]=y;
    prv[y]=x;

}
void upd(ll pos){
    ll len=0,x=pos;


    while(s[x]==s[pos]&&last!=0){
        len++;
        x=prv[x];
        if(prv[x]==x){
            break;
        }
    }
    if(len>=3){
        del(x,nxt[pos]);

        ans+=len;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    char c;
    s=" ";
    ll n;
    cin>>n;
    while(cin>>c){

        s+=c;
        ll i=s.size()-1;

        prv[i]=last;
        nxt[last]=i;
        ll nw=last;
        if(s[i]!=s[nw]){
//            if(s[nw]=='2'){
//                cout<<'g';
//            }
            upd(nw);
//            if(s[nw]=='2'){
//                cout<<  'g';
//            }
        }
        last=i;

    }
    upd(s.size()-1);
    cout<<ans;

    return 0;
}
