#include <bits/stdc++.h>
//problem https://codeforces.com/problemset/problem/940/F
//qwerty47924692
using namespace std;
using ll = int;
#define l first
#define r second
const ll N=2e5+29;
ll n,q,a[N],cnt[N],sz[N],type[N],p,ANS[N],ans,nxt[N],lst[N],pos[N];
map<ll,ll>mp;
struct que{
    ll t,l,r;
};
vector<que>v;
bool cmp(que x,que y){
    if(x.l/p<y.l/p) return 1;
	if(x.l/p>y.l/p) return 0;
	if(x.r/p<y.r/p) return 1;
	if(x.r/p>y.r/p) return 0;
	if((x.l/p+x.r/p)&1) return x.t<y.t;
	return x.t>y.t;
}
void add(ll x){
    sz[cnt[x]]--;
    cnt[x]++;
    sz[cnt[x]]++;
}
void del(ll x){
    sz[cnt[x]]--;
    cnt[x]--;
    sz[cnt[x]]++;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>q;
    sz[0]=1e9;
    ll timer=0;
    for(ll i=1;i<=n;i++){
        ll x;
        cin>>x;
        if(!mp[x])mp[x]=++timer;
        a[i]=mp[x];

    }
    p=2345;
    for(ll i=1;i<=q;i++){
        ll t,l,r;
        cin>>t>>l>>r;
        type[i]=(t==2);
        if(t==2){
            if(!mp[r])mp[r]=++timer;
            r=mp[r];
            nxt[i]=r;
            lst[i]=a[l];
            pos[i]=l;
            a[l]=r;
        }
        if(t==1)v.push_back({i,l,r});
    }
    ll t1=q,l1=1,r1=0;
   // cout<<'\n';
   sort(v.begin(),v.end(),&cmp);
    for(auto i:v){
        ll t2=i.t,l2=i.l,r2=i.r;

     //  cout<<t2<<' '<<l2<<' '<<r2<<'\n';
        while(l1>l2){
            add(a[--l1]);

        }
        while(r1<r2){
            add(a[++r1]);
        }
        while(l1<l2){
            del(a[l1++]);
        }
        while(r1>r2){
            del(a[r1--]);
        }
        while(t1<t2){
            t1++;
            if(type[t1]){
                ll ps=pos[t1];
                a[ps]=nxt[t1];
                if(l1<=ps&&ps<=r1){
        // if(cnt[lst[ps]]==0){cout<<a[r1]<<' '<<r1<<'\n';}
                    del(lst[t1]);

                    add(nxt[t1]);
                }
            }
        }
        while(t1>t2){
            if(type[t1]){
                ll ps=pos[t1];
                a[ps]=lst[t1];
                if(l1<=ps&&ps<=r1){
                    add(lst[t1]);

                    del(nxt[t1]);
                }

            }
            t1--;
        }
        for(ll i=1;i<=2e5;i++){
            if(!sz[i]){
                ans=i;
                break;
            }
        }
       //cout<<'\n';
        ANS[t2]=ans;
    }
    for(ll i=1;i<=q;i++){
        if(!type[i])cout<<ANS[i]<<'\n';
    }
}
