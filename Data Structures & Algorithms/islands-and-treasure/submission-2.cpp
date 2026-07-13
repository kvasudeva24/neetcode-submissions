#define LAND 2147483647
#define TREASURE 0
#define WATER -1


class Solution {
public:
    vector<pair<int,int>> adj = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    int m;
    int n;



    void islandsAndTreasure(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        queue<tuple<int, int, int>> frontier;
        set<pair<int, int>> seen;

        for ( int r = 0; r < m; r++ ) {
            for ( int c = 0; c < n; c++ ) {
                if ( grid[r][c] == TREASURE ) {
                    seen.insert({r, c});
                    frontier.push({r, c, 0});
                }
            }
        }

        while ( !frontier.empty() ) {
            int level = frontier.size();

            for ( int l = 0; l < level; l++ ) {

                auto [row, col, dist] = frontier.front();
                cout << "Row: " << row << endl;
                cout << "Col: " << col << endl;
                cout << "Dist: " << dist << endl;
                frontier.pop();

                if ( grid[row][col] == LAND ) {
                    grid[row][col] = dist;
                }

                for ( auto [dx, dy] : adj ) {
                    int nR = row + dy;
                    int nC = col + dx;
                    if ( (isValid(nR, nC)) && !(seen.count({nR, nC})) && (grid[nR][nC] == LAND) ) {
                        cout << "New Row: " << nR << endl;
                        cout << "New Col: " << nC << endl;
                        seen.insert({nR, nC});
                        frontier.push({nR, nC, dist+1});
                        cout << "-" << endl;
                    }
                }
                cout << endl;
                cout << endl;
            } 
        }
    }


    bool isValid(const int& r, const int& c) {
        return ((r>=0) && (r<m) && (c>=0) && (c<n));
    }
};
