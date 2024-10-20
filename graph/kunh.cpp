#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n,m,l[100100],used[100100],mu[100100],go[100100],ans;
vector<ll>g[100100];
bool try_kunh(ll v){
    if(w[v])return 0;
    w[v]=1;
    for(ll to:g[v]) {
        if(!l[to]||try_kunh(l[to])){
            l[to]=v;
            //cout<<v<<' '<<l[to]<<'\n';
            return 1;
        }
    }
    return 0;
}
void kunh(){
    for(ll i:r){
        for(ll j=1;j<=n;j++){
            w[j]=0;
        }
        ans+=try_kunh(i);
    }
}
bool try_fast(ll x){
    if (w[x])
		return 0;
	w[x] = 1;
	for (ll to : v[x])
		if (!mu[to])
		{
			mu[to] = x;
			go[x] = to;
			return 1;
		}
	for (ll to : v[x])
		if (try_kuhn(mu[to]))
		{
			mu[to] = x;
			go[x] = to;
			return 1;
		}
	return 0;
}
void fast(){
    for(ll ch;ch;){
        ch=0;
        for(ll i=1;i<=n;i++)w[i]=0;
        for(ll i=1;i<=n;i++){
            if(go[i])continue;
            if(try_fast(i)){
                ans++;
                ch=1;
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);



    return 0;
}
