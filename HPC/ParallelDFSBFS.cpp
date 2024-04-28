#include<bits/stdc++.h>
using namespace std;



vector<int> bfs(int n , vector<int> adj[]){
    vector<int> vis(n + 1 , 0);
    queue<int> q;
    vector<int> ans;
    q.push(1);
    vis[1] = 1;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for(auto it : adj[node]){
            if(!vis[it]){
                q.push(it);
                vis[it] = 1;
            }
        }
    }
    return ans;
}

void dfs1(int i , vector<int> &vis , vector<int> adj[] , vector<int> &ans){
    ans.push_back(i);
    vis[i] = 1;
    for(auto it : adj[i]){
        if(!vis[it]){
            dfs1(it , vis , adj , ans);
        }
    }
}

vector<int> dfs(int n , vector<int> adj[]){
    vector<int> ans;
    vector<int> vis(n + 1 , 0);
    #pragma omp parallel for
    for(int i = 1 ; i <= n ; i++){
        if(!vis[i]){
            dfs1(i , vis , adj , ans);
        }
    }
    return ans;
}

int main(){
    int n , e;
    cin >> n >> e;
    vector<int> adj[n + 1];
    for(int i = 0 ; i < n ; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> df;
    df = dfs(n , adj);
    for(auto it : df) cout << it << ' ';
    cout << endl;

    df = bfs(n , adj);
    for(auto it : df) cout << it << ' ';
    cout << endl;


    return 0;
}