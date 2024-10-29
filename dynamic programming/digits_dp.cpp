#include <bits/stdc++.h>
//code by BROVER29

using namespace std;
using ll = long long;
#define f first
#define s second
const ll N=1e5+29;
const ll M=5e3+3;
ll dp[20];
string s;
bool in(set<char> a,string b){
    for(auto i:b){
        if(a.find(i)==a.end())return 0;
    }
    return 1;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string x;
    string s;
    set<char>st;
    cin>>x>>s;
    s+='0';
    for(auto i:s){
        st.insert(i);
    }
    bool ok=1;
    for(ll i=0;i<x.size();i++){
        if(i==0){

            for(auto j:s){
                if(j<x[i]){
                    dp[i]++;
                }
            }
            continue;
        }
        dp[i]=dp[i-1]*((ll)s.size());
        ok=in(st,x.substr(0,i));
        if(!ok)continue;
        for(auto j:s){
            if(j<x[i]){
                dp[i]++;
            }
        }
    }
    cout<<dp[x.size()-1]+in(st,x);
}
