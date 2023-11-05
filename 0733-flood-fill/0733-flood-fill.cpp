class Solution {
public:
    void solve(vector<vector<int>>& image, int sr, int sc, int m, int n, int color, int newcolor, int delRow[], int delCol[]) {
        
        image[sr][sc] = newcolor;
        
        for(int i = 0; i < 4; i++) {
            int nRow = sr + delRow[i];
            int nCol = sc + delCol[i];
            if(nRow >= 0 && nRow < m && nCol >= 0 && nCol < n && image[nRow][nCol] == color && image[nRow][nCol] != newcolor) {
                solve(image, nRow, nCol, m, n, color, newcolor, delRow, delCol);
            }
        }
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color){
            return image;
        }
        int m = image.size();
        int n = image[0].size();
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1}; 
        solve(image, sr, sc, m, n, image[sr][sc], color, delRow, delCol);
        
        return image;
    }
};