#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
vector<int> g[N], par(N);

void dfs(int v, int p = -1){
    par[v] = p;
    for(int child:g[v]){
        if(child != p) dfs(child, v);
    }
}
vector<int> path(int v){
    vector<int> ans;
    while(v != -1){
        ans.push_back(v);
        v = par[v];
    }
}
int32_t main(){
    int n; cin>>n;
    for(int i = 1; i <= n-1; i++){
        int x, y; cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1);
    int x, y, lca = -1; cin>>x>>y;
    vector<int> a = path(x), b = path(y);
    for(int i = 0; i < min(a.size(), b.size()); i++){
        if(a[i] == b[i]) lca = a[i];
        else break;
    }
    cout<<lca;
}
