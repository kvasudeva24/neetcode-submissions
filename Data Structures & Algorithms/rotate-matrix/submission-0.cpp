class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //transpose then reflect on y axis
        vector<vector<int>> copy = matrix;

        for(int i = 0; i<matrix.size(); i++){
            for(int j = 0; j<matrix.size(); j++){
                matrix[i][j] = copy[j][i];
            }
        }

        

        for(int i = 0; i<matrix.size(); i++){
            int left = 0;
            int right = matrix[i].size() - 1;
            vector<int>& row = matrix[i];
            while(left<right){
                swap(row[left], row[right]);
                left++;
                right--;
            }
        }
    }
};
