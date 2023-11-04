class Solution {
public:
    void solve(vector<vector<char>>& grid, int i, int j, int m, int n){
        if(i >= m || i < 0 || j >= n || j < 0 || grid[i][j] == '0'){
            return;
        }
        
        grid[i][j] = '0';
        solve(grid, i, j + 1, m, n);
        solve(grid, i + 1, j, m, n);
        solve(grid, i - 1, j, m, n);
        solve(grid, i, j - 1, m, n);

        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int m = grid.size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == '1'){
                    solve(grid, i, j, m, grid[i].size());
                    ans++;
                }
            }
        }
        return ans;
    }
};