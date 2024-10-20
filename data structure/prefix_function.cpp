#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n,p[100100];
string s;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>s;
    for (int i=1; i<n; ++i) {
		int j = p[i-1];
		while (j > 0 && s[i] != s[j])
			j = p[j-1];
		if (s[i] == s[j])  ++j;
		p[i] = j;
	}
    cout<<p[n-1];

    return 0;
}
