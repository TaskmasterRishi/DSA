#include<bits/stdc++.h>
using namespace std;

void edge(vector<int> adj[], int u, int v) {
  adj[u].push_back(v);
}

void bfs(int s, vector<int> adj[], bool visit[]) {
  queue<int> q;
  q.push(s);
  visit[s] = true;
  while (!q.empty()) {
    int u = q.front();
    cout << u << " ";
    q.pop();
    for (int i = 0; i < adj[u].size(); i++) {
      if (!visit[adj[u][i]]) {
        q.push(adj[u][i]);
        visit[adj[u][i]] = true;
      }
    }
  }
}

void dfs(int s, vector<int> adj[], bool visit[]) {
  stack<int> stk;
  stk.push(s);
  visit[s] = true;
  while (!stk.empty()) {
    int u = stk.top();
    cout << u << " ";
    stk.pop();
    for (int i = 0; i < adj[u].size(); i++) {
      if (!visit[adj[u][i]]) {
        stk.push(adj[u][i]);
        visit[adj[u][i]] = true;
      }
    }
  }
}

int main() {
  int V, E;
  cout << "Enter the number of vertices and edges: ";
  cin >> V >> E;

  vector<int> adj[V]; 
  bool visit[V];

  for (int i = 0; i < V; i++) {
    visit[i] = false;
  }

  cout << "Enter edges (start end):" << endl;
  for (int i = 0; i < E; i++) {
    int u, v;
    cin >> u >> v;
    edge(adj, u, v);
  }

  int start_node;
  cout << "Enter the starting node for traversal: ";
  cin >> start_node;

  cout << "BFS traversal is: ";
  bfs(start_node, adj, visit);
  cout << endl;

  for (int i = 0; i < V; i++) {
    visit[i] = false;
  }

  cout << "DFS traversal is: ";
  dfs(start_node, adj, visit);

  return 0;
}
