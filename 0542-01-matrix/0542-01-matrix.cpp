class Solution {
public:
//     void dfs(int sr, int sc, vector<vector<int>>& mat, int n, int m, vector<vector<int>>& vis) {
//         queue<pair<int, int>> q;
        
//         q.push({sr, sc});
//         vis[sr][sc] = 1;
        
//         int delRow[] = {-1, 0, +1, 0};        
//         int delCol[] = {0, +1, 0, -1};

//         while(!q.empty()) {
//             int row = q.front().first;
//             int col = q.front().second;
//             q.pop();
            
//             for(int i = 0; i < 4; i++) {
//                 int nRow = row + delRow[i];
//                 int nCol = col + delCol[i];
//                 if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m) {
//                     if(vis[nRow][nCol] == 0) {
//                         if(mat[nRow][nCol] == 0) {
//                             mat[sr][sc] = abs(sr - nRow) + abs(sc - nCol);
//                             vis[nRow][nCol] = 1;
//                             return;
//                         } else {
//                             q.push({nRow, nCol});
//                         }
//                     }
//                 } 
//             }
//         }
//     }
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        
//         int n = mat.size();
//         int m = mat[0].size();
        
//         vector<vector<int>> vis(n + 1, vector<int> (m + 1, 0));
//         for(int i = 0; i < n; i++) {
//             for(int j = 0; j < m; j++) {
//                 if(mat[i][j] == 1 && vis[i][j] == 0) {
//                     dfs(i, j, mat, n, m, vis);
//                 }
//             }
//         }
//         return mat;
    
	    int n = grid.size(); 
	    int m = grid[0].size(); 
	    // visited and distance matrix
	    vector<vector<int>> vis(n, vector<int>(m, 0)); 
	    vector<vector<int>> dist(n, vector<int>(m, 0)); 
	    // <coordinates, steps>
	    queue<pair<pair<int,int>, int>> q; 
	    // traverse the matrix
	    for(int i = 0;i<n;i++) {
	        for(int j = 0;j<m;j++) {
	            // start BFS if cell contains 1
	            if(grid[i][j] == 0) {
	                q.push({{i,j}, 0}); 
	                vis[i][j] = 1; 
	            }
	            else {
	                // mark unvisited 
	                vis[i][j] = 0; 
	            }
	        }
	    }
	    
	    int delrow[] = {-1, 0, +1, 0}; 
	    int delcol[] = {0, +1, 0, -1}; 
	    
	    // traverse till queue becomes empty
	    while(!q.empty()) {
	        int row = q.front().first.first; 
	        int col = q.front().first.second; 
	        int steps = q.front().second; 
	        q.pop(); 
	        dist[row][col] = steps; 
	        // for all 4 neighbours
	        for(int i = 0;i<4;i++) {
	            int nrow = row + delrow[i]; 
	            int ncol = col + delcol[i]; 
	            // check for valid unvisited cell
	            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m 
	            && vis[nrow][ncol] == 0) {
	                vis[nrow][ncol] = 1; 
	                q.push({{nrow, ncol}, steps+1});  
	            }
	        }
	    }
	    // return distance matrix
	    return dist; 
    }
};