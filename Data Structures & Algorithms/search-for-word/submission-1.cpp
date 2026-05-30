class Solution {
public:
    vector<pair<int, int>> dir = {{0,1}, {1,0}, {0,-1}, {-1, 0}};
    string trgt;
    vector<vector<char>> board;
    int m;
    int n;

    bool exist(vector<vector<char>>& board, string word) {
        this->trgt = word;
        this->board = board;
        this->m = board.size();
        this->n = board[0].size();


        for(int i = 0; i<board.size(); i++){
            for(int j = 0; j<board[0].size(); j++){
                if(board[i][j] == word[0]){
                    bool found = false;
                    set<pair<int,int>> seen = {{i, j}};
                    backtrack(i, j, 1, found, seen);
                    if(found) return true;
                }
            }
        }
        return false;
    }

    void backtrack(int row, int col, int i, bool& found, set<pair<int,int>>& seen){
        if(i == trgt.size()){
            found = true;
            return;
        }

        for(auto [dy, dx] : dir){
            int nR = row + dy;
            int nC = col + dx;
            if(isValid(nR, nC) && board[nR][nC] == trgt[i] && !seen.count({nR, nC})){
                seen.insert({nR, nC});
                backtrack(nR, nC, i+1, found, seen);
                seen.erase({nR, nC});
            }
        }
    }

    bool isValid(int r, int c){
        return (r>=0 && r<m && c>=0 && c<n);
    }
};
