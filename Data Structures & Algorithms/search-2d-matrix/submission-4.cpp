class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int lo = 0;
        int hi = rows * cols - 1;

        if(hi == 0) return (target == matrix[0][0]);

        while (lo < hi){
            int mid = lo + (hi - lo)/2;

            int r = mid/cols;
            int c = mid%cols;

            cout << "Hi :" << hi << " | Lo: " << lo << " | Mid: " << mid << " | Row: " << r << " | Col: "<< c << " | Matrix: " << matrix[r][c] << endl;

            if(matrix[r][c] == target){
                return true;
            } else if (matrix[r][c] > target){
                hi = mid;
            } else {
                lo = mid+1;
            }
        }
        int r = lo/cols;
        int c = lo%cols;

        return (matrix[r][c] == target);
    }
};
