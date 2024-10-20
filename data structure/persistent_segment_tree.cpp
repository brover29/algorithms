#include <bits/stdc++.h>
//qwerty47924692
using namespace std;
using ll = long long;
const ll N=2e5+29;
ll n,a[N],root[N],q,timer,cnt;
struct node{
    ll val,lv,rv;
}st[40*N];
void build(ll &v,ll l,ll r){
    if(!v)v=++timer;
    if(l==r){
        st[v].val=a[l];
        return;
    }
    ll mid=(r+l)>>1;
    build(st[v].lv,l,mid);
    build(st[v].rv,mid+1,r);
    st[v].val=st[st[v].lv].val + st[st[v].rv].val;
}
void upd(ll &v,ll last,ll l,ll r,ll pos,ll x){
    if(!v)v=++timer;
    if(l==r){
        st[v].val=val;
        return;
    }
    ll mid=(r+l)>>1;
    if(pos<=mid){
        st[v].rv=st[last].rv;
        update(st[v].lv,st[last].lv,l,mid,pos,x);
    }
    else{
        st[v].lv=st[last].lv;
        update(st[v].rv,st[last].rv,mid+1,r,pos,x);
    }
    st[v].val=st[st[v].lv].val + st[st[v].rv].val;

}
ll get(ll &v,ll l,ll r,ll x,ll y){
    if(l>y||x>r)return 0;
    if(x<=l&&r<=y)return st[v].val;
    ll mid=(r+l)>>1;
    return get(st[v].lv,l,mid,x,y,get(st[v].rv,mid+1,r,x,y);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    for(ll i=1;i<=n;i++)cin>>a[i];
    build(root[0],1,n);
    cin>>q;
    while(q--){
        ll type;
        cin>>type;
        if(type==1){
            ll k,l,r;
            cin>>k>>l>>r;
            cout<<get(root[k],1,n,l,r)<<'\n';
        }
        else{
            ll pos,val;
            cin>>pos>>val;
            cnt++;
            upd(root[cnt],root[cnt-1],1,n,pos,val);
        }
    }

}

