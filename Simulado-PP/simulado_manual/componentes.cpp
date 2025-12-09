#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 105;
vector<int> adj[MAXN];
bool visited[MAXN];
void dfs(int u){
    visited[u] = true;
    for (int v : adj[u]){
        if (visited[v] == false){
            dfs(v);
        } 
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int u,v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int componentes = 0;
    for(int i = 1; i <= N; i++){
        if(visited[i] == false){
            componentes++;
            dfs(i);
        }

    }
    cout << componentes << "\n";
    return 0;
}