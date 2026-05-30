class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        //rows
        set<int> checker;
        for ( int i = 0; i < 9; i++ ) {
            for ( int j = 0; j < 9; j++ ) {
                if ( board[i][j] == '.' ) continue;
                if ( checker.count(board[i][j]) ) return false;
                checker.insert(board[i][j]);
            }
            checker.clear();
        }

        for ( int i = 0; i < 9; i++ ) {
            for ( int j = 0; j < 9; j++ ) {
                if ( board[j][i] == '.' ) continue;
                if ( checker.count(board[j][i]) ) return false;
                checker.insert(board[j][i]);
            }
            checker.clear();
        }

        vector<pair<int,int>> squares = { {0,0}, {0,3}, {0, 6}, 
                                          {3,0}, {3,3}, {3, 6},
                                          {6,0}, {6,3}, {6, 6}};

        for ( auto [i, j] : squares ) {
            for ( int ii = i; ii < i + 3; ii++) {
                for ( int jj = j; jj < j + 3; jj++) {
                    if ( board[ii][jj] == '.' ) continue;
                    if ( checker.count(board[ii][jj]) ) return false;
                    checker.insert(board[ii][jj]);
                }
            }
            checker.clear();
        }
        return true;


    }
};
