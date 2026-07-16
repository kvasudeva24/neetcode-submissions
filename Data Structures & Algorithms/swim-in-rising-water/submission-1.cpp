class Solution {
public:
    vector<pair<int, int>> adj = {{0,1}, {1,0}, {0, -1}, {-1, 0}};
    int n;

    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();
        priority_queue<tuple<int, int, int>,
                       vector<tuple<int, int, int>>,
                       greater<tuple<int, int, int>>> pq;

        vector<vector<int>> trackedGrid(n, vector(n, -1));
        trackedGrid[0][0] = grid[0][0];

        pq.push({grid[0][0], 0, 0});

        while ( !pq.empty() ) {
            auto [time, i, j] = pq.top();
            pq.pop();

            if ( i == n-1 && j == n-1 ) {
                return time;
            }

            for ( auto [dx, dy] : adj ) {
                int nR = i + dy;
                int nC = j + dx;

                if ( inBounds(nR, nC) ) {
                    int nextTime = ( grid[nR][nC] > time ) ? grid[nR][nC] : time;
                    if ( trackedGrid[nR][nC] == -1 || nextTime < trackedGrid[nR][nC] ) {
                        trackedGrid[nR][nC] = nextTime;
                        pq.push({nextTime, nR, nC});
                    }
                }
            }
        }
        return -1;
    }

    bool inBounds(const int& i, const int& j) {
        return ((i>=0) && (i<n) && (j>=0) && (j<n));
    }
};
