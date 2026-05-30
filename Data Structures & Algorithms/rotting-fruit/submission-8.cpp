#define ROTTEN 2
#define EMPTY 0
#define FRESH 1

class Solution {
public:
    int m;
    int n;

    vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1,0}, {-1,  0}};

    int orangesRotting(vector<vector<int>>& grid) {
        this->m = grid.size();
        this->n = grid[0].size();

        queue<pair<int, int>> q;

        for(int r = 0; r<grid.size(); r++){
            for(int c = 0; c<grid[0].size(); c++){
                if(grid[r][c] == ROTTEN){
                    q.push({r,c});
                }
            }
        }

        int minutes = -1;

        std::function<bool(int,  int)> isValid = [&](int r,  int c){
            return (r>=0 && r<m && c>=0 && c<n && grid[r][c] == FRESH);
        };

        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                auto [row, col] = q.front(); q.pop();

                for(auto [dy, dx] : dir){
                    int nR = row + dy;
                    int nC = col + dx;
                    if(isValid(nR, nC)){
                        grid[nR][nC] = ROTTEN;
                        q.push({nR, nC});
                    }
                }
            }
            minutes++;
        }


        for(int r = 0; r<grid.size(); r++){
            for(int c = 0; c<grid[0].size(); c++){
                if(grid[r][c] == FRESH){
                    return -1;
                }
            }
        }

        return (minutes == -1) ? 0 : minutes;

    }
};
