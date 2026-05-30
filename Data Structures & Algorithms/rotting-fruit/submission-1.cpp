class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        set<pair<int, int>> seen;
        vector<pair<int, int>> dir = {{0,1}, {1,0}, {0,-1}, {-1, 0}};

        //mark initial rotten
        for(int r = 0; r<grid.size(); r++){
            for(int c = 0; c<grid[0].size(); c++){
                if(grid[r][c] == 2){
                    q.push({r,c});
                    seen.insert({r,c});
                }
            }
        }

        //isvalid lambda
        function<bool(int, int)> isValid = [&](int r, int c){
            return (r>=0 && r<grid.size() && c>=0 && c<grid[0].size() && grid[r][c] == 1 && !seen.count({r,c}));
        };


        int time = -1;
        //now bfs
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i<size; i++){
                auto [row, col] = q.front();
                q.pop();

                for(auto [dy, dx] : dir){
                    int nR = row + dy;
                    int nC = col + dx;

                    if(isValid(nR, nC)){
                        grid[nR][nC] = 2;
                        q.push({nR, nC});
                        seen.insert({nR, nC});
                    }
                }
            }
            time++;
        }

        bool remain = false;
        for(int r = 0; r<grid.size(); r++){
            for(int c = 0; c<grid[0].size(); c++){
                if(grid[r][c] == 1) remain = true;
            }
        }

        return (remain) ? -1 : (time == -1) ? 0 : time;

    }
};
