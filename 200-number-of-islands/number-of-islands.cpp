class Solution {
public:
    void dfs(int row, int col, vector<vector<char>> &grid, vector<vector<int>> &vis){

        int m = grid.size();
        int n = grid[0].size();
        
        vector<int> delRow = {-1,0,1,0};
        vector<int> delCol = {0,-1,0,1};

        for (int i=0; i<4; i++){
            int newRow = row + delRow[i];
            int newCol = col + delCol[i];

            if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && grid[newRow][newCol] == '1' && vis[newRow][newCol] == 0){
                vis[newRow][newCol] = 1;
                dfs(newRow, newCol, grid, vis);
            }
        } 
        
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m,vector<int>(n,0));

        int cnt=0;

        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (!vis[i][j] && grid[i][j] == '1'){       // char 1 here
                    vis[i][j] = 1;
                    dfs(i, j, grid, vis);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};