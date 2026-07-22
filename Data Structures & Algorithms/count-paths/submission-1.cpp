class Solution {
public:
    vector<vector<int>> paths;

    int uniquePaths(int m, int n) {
        paths = vector(m, vector(n, -1));
        return numPaths(0, 0, m, n);
    }


    int numPaths(int i, int j, int maxR, int maxC) {
        if ( (i == maxR - 1) && (j == maxC -1) ) { return 1; }

        if ( (i == maxR) || (j == maxC) ) { return 0; }

        if ( paths[i][j] != -1 ) { return paths[i][j]; }

        int num = numPaths(i+1, j, maxR, maxC) + numPaths(i, j+1, maxR, maxC);
        paths[i][j] = num;
        return num;
    }

    /*
    numPaths(i, j) = the number of unique paths there is from (i, j) -> (n, n)

    base case: 
        if i == m - 1 and j == n - 1 return 1

        else
            numPaths(i+1, j) + numPaths(i, j+1);


    */
};
