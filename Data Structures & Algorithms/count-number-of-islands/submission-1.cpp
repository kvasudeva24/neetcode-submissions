class Solution {
public:
    vector<pair<int, int>> adj = {{0,1}, {1,0}, {0,-1}, {-1, 0}};
    vector<vector<char>> board;

    int numIslands(vector<vector<char>>& grid) { 
        board = grid;
        int islands = 0;

        for ( int r = 0; r < grid.size(); r++ ) {
            for ( int c = 0; c < grid[0].size(); c++ ) {

                if ( board[r][c] == '1' ) {
                    islands++;
                    board[r][c] = '2';
                    clearIsland(r, c);
                }

            }
        }
        return islands;
    }

    void clearIsland(const int& r, const int& c) {

        for ( auto [dx, dy] : adj ) {
            int nR = r + dy;
            int nC = c + dx;
            if ( isValid(nR, nC) && board[nR][nC] == '1' ) {
                board[nR][nC] = '2';
                clearIsland(nR, nC);
            }
        }

    }

    bool isValid (const int& r, const int& c) {
        return ( (r>=0) && (r<board.size()) && (c>=0) && (c<board[0].size()) );
    }
};
