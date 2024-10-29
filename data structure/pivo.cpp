#include <bits/stdc++.h>
//qwerty47924692
using namespace std;
using ll = long long;
const ll N=3e5+29;
const string br="617283";

ll n;
struct node{
    ll key,prior,pr,index;
    node *l=nullptr,*r=nullptr;
    node(int key) : key(key),prior(rand()){}
};
pair<node*,node*> split( node *p,ll x) {
    if(p==nullptr)return {nullptr,nullptr};
    if(p->key<=x){
        auto [l,r]=split(p->r,x);
        p->r=l;
        return {p,r};
    }else{
        auto [l,r]=split(p->l,x);
        p->l=r;
        return {l,p};
    }
}node* merge (node *l, node *r) {
    if (!l) return r;
    if (!r) return l;
    if (l->prior > r->prior) {
        l->r = merge(l->r, r);
        return l;
    }
    else {
        r->l = merge(l, r->l);
        return r;
    }
}
node *root=0;
bool contains(node *p,ll x) {
    if(p==nullptr)return false;
    if(p->key==x)return true;
    if(p->key>x)return contains(p->r,x);
    return contains(p->l,x);
}

void insert (ll x,ll pr) {
    auto q = split(root, x);
    node *t = new node(x);
    t->pr=pr;
    root = merge(q.first, merge(t, q.second));
}
ll l[N],r[N],pr[N];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    srand(time(0));



}
