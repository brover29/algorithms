#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N=1e5+29;
ll n,m,a[N],ans,ANS[N],k;
struct que{
    ll l,r,id;
};
que q[N];
map<ll,ll>cnt;
bool cmp(que a,que b){
    if((ll)a.l/k==(ll)b.l/k){
        return a.r<b.r;
    }
    return a.l<b.l;
}
void add(ll x){
    ++cnt[x];
    if(cnt[x]==1)ans++;

}
void del(ll x){
    --cnt[x];
    if(!cnt[x])ans--;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    k=sqrt(n);
    for(ll i=1;i<=n;i++)cin>>a[i];
    for(ll i=1;i<=m;i++){
        cin>>q[i].l>>q[i].r;
        q[i].id=i;
    }
    sort(q+1,q+1+m,&cmp);

    ll l1,r1,l2=1,r2=0;
    for(ll i=1;i<=m;i++){
        l1 = q[i].l, r1 = q[i].r;
        while (r2 < r1) {
            add(a[++r2]);
        }
        while (l2> l1) {
            add(a[--l2]);
        }
        while (r2 > r1) {
            del(a[r2--]);
        }
        while (l2 < l1) {
            del(a[l2++]);
        }
        ANS[q[i].id] = ans;
    }
    for(ll i=1;i<=m;i++){
        cout<<ANS[i]<<'\n';
    }

}
