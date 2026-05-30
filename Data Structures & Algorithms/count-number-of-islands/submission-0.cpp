class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;

        vector<pair<int, int>> dir = {{0,1}, {1,0}, {0,-1}, {-1,0}};

        function<void(int, int)> dfs = [&](int r, int c){
            for(auto [dy, dx] : dir){
                int nR = r + dy;
                int nC = c + dx;
                if(nR >= 0 && nR<grid.size() && nC>=0 && nC<grid[0].size() && grid[nR][nC] == '1'){
                    grid[nR][nC] = '2';
                    dfs(nR, nC);
                }
            }
        };

        for(int r = 0; r<grid.size(); r++){
            for(int c = 0; c<grid[0].size(); c++){
                if(grid[r][c] == '1'){
                    grid[r][c] = '2';
                    islands++;
                    cout << islands << endl;
                    cout << r << c << endl;
                    dfs(r, c);
                }
            }
        }
        return islands;
    }
};
