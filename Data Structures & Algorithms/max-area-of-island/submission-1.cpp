class Solution {
public:
    vector<pair<int, int>> adj = {{0,1}, {1,0}, {0,-1}, {-1, 0}};
    vector<vector<int>> board;

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        board = grid;
        int maxIsland = 0;

        for ( int r = 0; r < grid.size(); r++ ) {
            for ( int c = 0; c < grid[0].size(); c++ ) {

                if ( board[r][c] == 1 ) {
                    board[r][c] = 2;
                    int size = 1;
                    clearIsland(r, c, size);
                    maxIsland = max(maxIsland, size);
                }

            }
        }
        return maxIsland;
    }

    void clearIsland(const int& r, const int& c, int& size) {

        for ( auto [dx, dy] : adj ) {
            int nR = r + dy;
            int nC = c + dx;
            if ( isValid(nR, nC) && board[nR][nC] == 1 ) {
                size++;
                board[nR][nC] = 2;
                clearIsland(nR, nC, size);
            }
        }

    }

    bool isValid (const int& r, const int& c) {
        return ( (r>=0) && (r<board.size()) && (c>=0) && (c<board[0].size()) );
    }
};
