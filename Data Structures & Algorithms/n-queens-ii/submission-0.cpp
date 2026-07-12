class Solution {
public:
    unordered_set<int> columns;
    unordered_set<int> diag;
    unordered_set<int> antiDiag;


    int totalNQueens(int n) {
        int ans = 0;
        findValidPlacements(ans, 0, n);
        return ans;
    }

    void findValidPlacements(int& num, int row, const int& n) {
        if ( row == n ) {
            num++;
            return;
        }

        for ( int col = 0; col < n; col++ ) {
            if ( isValidPlacement(row, col) ) {
                columns.insert(col);
                diag.insert(row-col);
                antiDiag.insert(row+col);

                findValidPlacements(num, row+1, n);

                columns.erase(col);
                diag.erase(row-col);
                antiDiag.erase(row+col);
            }
        }


    }

    bool isValidPlacement(const int& r, const int& c) {
        return ( !(columns.count(c)) && !(diag.count(r-c)) && !(antiDiag.count(r+c)) );
    }
};
