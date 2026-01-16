#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    /*
    Q. Traverse the entire graph using BFS, including disconnected components
    */

    vector<int> bfsTraversal(int V, vector<int> adj[]) {
        vector<int> bfs;
        vector<int> vis(V, 0);
        
        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                queue<int> q;
                q.push(i);
                vis[i] = 1;
                
                while(!q.empty()) {
                    int node = q.front();
                    q.pop();
                    bfs.push_back(node);
                    
                    for(auto it : adj[node]) {
                        if(!vis[it]) {
                            q.push(it);
                            vis[it] = 1;
                        }
                    }
                }
            }
        }
        
        return bfs;
    }

    /*
    Q. Perform a Breadth-First Search (BFS) traversal on a graph starting from a given source node.
    */

    vector<int> bfs(int V, int S, vector<int> adj[]) {
        vector<int> bfs;
        vector<int> vis(V, 0);
        
        queue<int> q;
        q.push(S);
        vis[S] = 1;
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            bfs.push_back(node);
            
            for(auto it : adj[node]) {
                if(!vis[it]) {
                    q.push(it);
                    vis[it] = 1;
                }
            }
        }
        
        return bfs;
    }

    /*
    Q. Traverse the entire graph using DFS, including disconnected components.
    */

    vector<int> dfsTraversal(int V, vector<int> adj[]) {
        vector<int> dfs;
        vector<int> vis(V, 0);
        
        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                stack<int> s;
                s.push(i);
                vis[i] = 1;
                
                while(!s.empty()) {
                    int node = s.top();
                    s.pop();
                    dfs.push_back(node);
                    
                    for(auto it : adj[node]) {
                        if(!vis[it]) {
                            s.push(it);
                            vis[it] = 1;
                        }
                    }
                }
            }
        }
        
        return dfs;
    }

    /*
    Q. Perform a Depth-First Search (DFS) traversal on a graph starting from a given source node.
    */

    vector<int> dfs(int V, int S, vector<int> adj[]) {
        vector<int> dfs;
        vector<int> vis(V, 0);
        
        stack<int> s;
        s.push(S);
        vis[S] = 1;
        
        while(!s.empty()) {
            int node = s.top();
            s.pop();
            dfs.push_back(node);
            
            for(auto it : adj[node]) {
                if(!vis[it]) {
                    s.push(it);
                    vis[it] = 1;
                }
            }
        }
        
        return dfs;
    }
};
