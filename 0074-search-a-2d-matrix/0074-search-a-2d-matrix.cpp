class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // for(int i = 0; i < matrix.size(); i++){
        //     for(int j = 0;  j < matrix[i].size(); j++){
        //         if(matrix[i][j] == target){
        //             return true;
        //         }
        //     }
        // }
        // return false;
        int n = matrix.size(); // rows
        int m = matrix[0].size(); // columns
        int l = 0;
        int r = n * m - 1;
        while(l <= r){
            int mid = l + r >> 1;
            if(matrix[mid / m][mid % m] > target){//gives the index of element in 2d array
                r = mid - 1;
            }else if(matrix[mid / m][mid % m] < target){
                l = mid + 1;
            }else{
                return true;
            }
        }
        return false;
    }
};