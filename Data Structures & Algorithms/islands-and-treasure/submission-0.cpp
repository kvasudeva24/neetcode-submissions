#define LAND INT_MAX
#define TREASURE 0
#define WATER -1

class Solution {
public:
    int m;
    int n;
    vector<pair<int,int>> dir = {{0,1}, {1,0}, {0,-1}, {-1,0}};

    void islandsAndTreasure(vector<vector<int>>& grid) {
        this->m = grid.size();
        this->n = grid[0].size();

        queue<tuple<int,int, int>> q;
        set<pair<int,int>> seen;

        //add initial treasures and mark them as seen
        for(int r = 0; r<m; r++){
            for(int c = 0; c<n; c++){
                if(grid[r][c] == TREASURE){
                    q.push({r, c, 0});
                    seen.insert({r, c});
                }
            }
        }

        while(!q.empty()){
            int size = q.size();
            for(int _ = 0; _<size; _++){
                auto [row, col, steps] = q.front(); q.pop();
                grid[row][col] = steps;

                for(auto [dx, dy] : dir){
                    int nR = row + dy; 
                    int nC = col + dx;
                    if(inBounds(nR, nC) && !seen.count({nR, nC}) && grid[nR][nC] == LAND){
                        seen.insert({nR, nC});
                        q.push({nR, nC, steps+1});
                    }
                }
            }
        }
        
    }

    inline bool inBounds(const int& r, const int& c){
        return (r>=0 && r<m && c>=0 && c<n);
    }
};
