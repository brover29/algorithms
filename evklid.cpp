#include <bits/stdc++.h>
//qwerty47924692
using namespace std;
using ll = long long;
const ll N=2e5+29;
const string br="617283";
ll gcd(ll a,ll b){
    if(!b)return a;
    return gcd(b,a%b);
}
ll lcm(ll a,ll b){
    return a*b/gcd(a,b);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);


}

