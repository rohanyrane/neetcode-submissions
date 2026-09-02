class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        vector<bool> visit(n,false);
        for(const auto& edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int res = 0;
        for(int node = 0; node<n; node++){
            if(!visit[node]){
                bfs(adj, visit, node);
                res++;
            }
        }
        return res;
    }

    void bfs(vector<vector<int>> &adj, vector<bool> &visited, int node){
        queue<int> q;
        q.push(node);
        visited[node] = true;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(int neigh : adj[curr]){
                if(!visited[neigh]){
                    visited[neigh] = true;
                    q.push(neigh);
                }
            }
        }
    }
};
