class Solution {
public:
    vector<pair<int, int>> adj = {{0,1}, {1,0}, {0, -1}, {-1, 0}};
    int m;
    int n;
    vector<vector<int>> paths;
    vector<vector<int>> matrix;


    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        paths = vector(m, vector(n, -1));
        this->matrix = matrix;

        int ans = 0;
        for ( int i = 0; i < m; i++ ) {
            for ( int j = 0; j < n; j++ ) {
                if ( paths[i][j] == -1 ) {
                    ans = max(ans, longestIncPath(i, j));
                }
            }
        }
        return ans;
    }

    int longestIncPath(int i, int j) {
        if ( paths[i][j] != -1 ) { return paths[i][j]; }

        int longestPath = 0;
        for ( auto [dx, dy] : adj ) {
            int nR = i + dy;
            int nC = j + dx;

            if ( (nR >= 0) && (nR < m) && (nC >= 0) && (nC < n) && (matrix[nR][nC] > matrix[i][j]) ) {
                int curPath = 1 + longestIncPath(nR, nC);
                longestPath = max(longestPath, curPath);
            }

        }

        longestPath = ( longestPath == 0 ) ? 1 : longestPath;
        paths[i][j] = longestPath;
        return longestPath;

    }




    /*
    longestIncPath(i, j) = length of the longest inc path starting from matrix[i][j] while only moving
                           horizontally or vertically

    Note: we cannot "revisit" a node since we are always stricly increasing

    base case:
        0 if i or j is OoB

        max(longestIncPath(from all valid neighbors))

    */
};
