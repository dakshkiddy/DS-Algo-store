// C++ program to implement BFS and DFS
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n=6;
    vector<vector<int>> g(n);
    auto add=[&](int u,int v){ g[u].push_back(v); g[v].push_back(u); };
    add(0,1); add(0,2); add(1,3); add(2,3); add(3,4); add(4,5);

    // BFS from 0
    vector<int> dist(n,-1); queue<int> q; dist[0]=0; q.push(0);
    while(!q.empty()){
        int u=q.front(); q.pop();
        for(int v: g[u]) if(dist[v]==-1){ dist[v]=dist[u]+1; q.push(v); }
    }
    cout<<"BFS dist: "; for(int d:dist) cout<<d<<" "; cout<<"\n";

    // DFS from 0
    vector<int> vis(n,0), order;
    function<void(int)> dfs=[&](int u){
        vis[u]=1; order.push_back(u);
        for(int v: g[u]) if(!vis[v]) dfs(v);
    };
    dfs(0);
    cout<<"DFS order: "; for(int x:order) cout<<x<<" "; cout<<"\n";
    return 0;
}
