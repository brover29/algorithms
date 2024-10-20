#include <bits/stdc++.h>

using namespace std;
const int maxn = 1000100;
const long long inf = 1e18;
int n, m;

vector< pair<int, int> > g[maxn];
long long d[maxn];
int u[maxn];
int p[maxn];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    for(int i = 1; i <= n; i++) {
        d[i] = inf;
        p[i] = -1;
    }
    d[1] = 0;
    priority_queue< pair<long long, int> > s;

    /*for(int i = 1; i <= n; i++) {
        s.insert({d[i], i});
    }*/
    s.push({-d[1], 1});
    while(s.size() > 0) {
        int v = s.top().second;
        s.pop();
        if(u[v]) continue;
        u[v] = 1;

        for(int i = 0; i < g[v].size(); i++) {
            int to = g[v][i].first;
            int w = g[v][i].second;
            if(d[to] > d[v] + w) {
                //s.erase({d[to], to});
                p[to] = v;
                d[to] = d[v] + w;
                s.push({-d[to], to});
            }
        }
    }
    int v = n;
    vector<int> path;
    while(v != -1) {
        path.push_back(v);
        v = p[v];
    }
    reverse(path.begin(), path.end());
    if(path.front()!=1){
        cout<<-1;
        return 0;
    }
    for(auto i:path){
        cout<<i<< ' ';
    }
}


