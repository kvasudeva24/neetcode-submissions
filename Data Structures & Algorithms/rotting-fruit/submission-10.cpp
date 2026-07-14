#define EMPTY 0
#define FRESH 1
#define ROTTEN 2


class Solution {
public:
    set<pair<int, int>> seen;
    vector<pair<int, int>> adj = {{0,1}, {1,0}, {0,-1}, {-1,0}};

    int m;
    int n;

    int orangesRotting(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int minutes = -1;
        queue<pair<int, int>> frontier;

        for ( int r = 0; r < m; r++ ) {
            for ( int c = 0; c < n; c++ ) {
                if ( grid[r][c] == ROTTEN ) {
                    seen.insert({r, c});
                    frontier.push({r, c});
                }
            }
        }
        
        while ( !frontier.empty() ) {
            minutes++;
            int size = frontier.size();

            for ( int s = 0; s < size; s++ ) {
                auto [row, col] = frontier.front();
                frontier.pop();

                for ( auto [dx, dy] : adj ) {
                    int nR = row + dy;
                    int nC = col + dx;

                    if ( isBounds(nR, nC) && !seen.count({nR, nC}) && (grid[nR][nC] == FRESH) ) {
                        grid[nR][nC] = ROTTEN;
                        seen.insert({nR, nC});
                        frontier.push({nR, nC});
                    } 
                }
                // cout << "-" << endl;
            }
            // cout << "\n" << endl;
        }

        for ( int r = 0; r < m; r++ ) {
            for ( int c = 0; c < n; c++ ) {
                if ( grid[r][c] == FRESH ) {
                    return -1;
                }
            }
        }
        return (minutes == -1) ? 0 : minutes;
    }

    bool isBounds(const int& r, const int& c) {
        return ((r>=0) && (r<m) && (c>=0) && (c<n));
    }
};
