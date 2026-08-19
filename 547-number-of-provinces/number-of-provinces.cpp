class Solution {
public:

    void dfs(int node, vector<vector<int>> &adj, vector<int> &vis){
        vis[node] = 1;

        for (auto neigh : adj[node]){
            if (!vis[neigh]){
                dfs(neigh, adj, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        vector<vector<int>> adj(n+1,vector<int>(n+1));

        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                if (isConnected[i][j] == 1){
                    adj[i+1].push_back(j+1);
                    adj[j+1].push_back(i+1);
                }
            }
        }

        vector<int> vis(n+1,0);
        int cnt=0;
        
        for (int i=1; i<=n; i++){
            if (!vis[i]){
                dfs(i, adj, vis);
                cnt++;
            }
        }

        return cnt;
    }
};