class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int elements = rows * cols;
        int right = elements - 1;
        int left = 0;

        while ( left <= right ) {
            int mid = left + ( right - left )/2;

            int r = mid / cols;
            int c = mid % cols;

            if ( matrix[r][c] == target ) { return true; }
            else if ( matrix[r][c] > target ) { right = mid - 1; }
            else { left = mid + 1; }
        }
        return false;
    }
};


// 0 and 11 is 5 
//5 / 4 = 1
// 5 %4 =1 