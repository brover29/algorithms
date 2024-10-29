#include <bits/stdc++.h>
//qwerty47924692
using namespace std;

using ll =int;
const ll N=1e5+29;
string add(string &a,string &b){
    while(a.size()<b.size())a='0'+a;
    while(b.size()<a.size())b='0'+b;
    string res;
    ll add=0;
    for(ll i=a.size()-1;i>=0;i--){
        ll cur=(a[i]-'0')+(b[i]-'0')+add;
        add=0;
        if(cur>=10){
            add=cur/10;
            cur%=10;
        }
        res+=cur+'0';
    }
    if(add)res+=add+'0';
    reverse(res.begin(),res.end());
    return res;
}
string del(string &a,string &b){
    while(a.size()<b.size())a='0'+a;
    while(b.size()<a.size())b='0'+b;
    string res;
    ll add=0;
    for(ll i=a.size()-1;i>=0;i--){
        ll cur=(a[i]-'0')+add-(b[i]-'0');
        add=0;
        if(cur<0){
            add=-1;
            cur+=10;
        }
        res+=cur+'0';
    }
    if(add)res+=add+'0';
    reverse(res.begin(),res.end());
    return res;
}
string karatsuba(string &x,string &y){

    while(x.size()<y.size())x='0'+x;
    while(y.size()<x.size())y='0'+y;
    ll n=x.size();
    if(n==1){
        ll a=x[0]-'0';
        ll b=y[0]-'0';
        return to_string(a*b);
    }
    string a=x.substr(0,(n)/2);
    string b=x.substr((n)/2);
    string c=y.substr(0,(n)/2);
    string d=y.substr((n)/2);


    string ac=karatsuba(a,c);
    string bd=karatsuba(b,d);

    string ab=add(a,b);
    string cd=add(c,d);
    string abcd=karatsuba(ab,cd);
    cd=del(abcd,ac);
    abcd=del(cd,bd);
    for(ll i=1;i<=(n+1)/2;i++)abcd+='0';
    for(ll i=1;i<=(n+1)/2*2;i++)ac+='0';
    cd=add(abcd,bd);
    return add(ac,cd);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string a,b;
    cin>>a>>b;
    while(a.size()<b.size())a='0'+a;
    while(b.size()<a.size())b='0'+b;
    string s=karatsuba(a,b);
    ll x=0;

    while(s[x]=='0'&&x+1<s.size()) {
        x++;

    }

    cout<<s.substr(x,s.size()-x+1);
}

