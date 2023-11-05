class Solution {
public:

    int orangesRotting(vector<vector<int>>& grid) {
        int count = 0;
        int fresh = 0;
        int n = grid.size();
        int m = grid[0].size();
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, -1, 0, +1};
        
        queue<pair<pair<int, int>, int>> q;
        
        vector<vector<bool>> visited(n + 1, vector<bool> (m + 1, false));
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2 && visited[i][j] == false) {
                    q.push({{i, j}, count});
                }
                
                if(grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
        
        int tm = 0;
        while(!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int count = q.front().second;
            q.pop();
            
            tm = max(tm, count);
            for(int i = 0; i < 4; i++) {
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];
                
                if(nRow >= 0 && nRow < n && nCol >=0 && nCol < m && grid[nRow][nCol] == 1 && visited[nRow][nCol] == false)                 {
                    q.push({{nRow, nCol}, count + 1});
                    visited[nRow][nCol] = true;
                    fresh--;
                }
            }
        }
        
        return fresh == 0 ? tm : -1;
    }
};