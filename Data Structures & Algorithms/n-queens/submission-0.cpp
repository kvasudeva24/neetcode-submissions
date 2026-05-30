class Solution {
public:
        int n;

    vector<vector<string>> solveNQueens(int n) {
        this->n = n;

        int row = 0;
        vector<vector<string>> ans;
        set<int> diag;
        set<int> anti_diag;
        set<int> cols;

        string blank = string(n, '.');
        vector<string> board = vector(n, blank);
        int r = 0;

        backtrack(row, board, ans, diag, cols, anti_diag, r);
        cout << r << endl;
        return ans;
    }

    void backtrack(int row, vector<string>& board, vector<vector<string>>& ans, set<int>& diag, set<int>& cols, set<int>& anti_diag, int& r){
        if(row == n){
            ans.push_back(board);
            r++;
            return;
        }

        for(int col = 0; col<n; col++){
            int d = row - col;
            int a = row + col;
            if(!cols.count(col) && !diag.count(d) && !anti_diag.count(a)){
                cols.insert(col); diag.insert(d); anti_diag.insert(a);
                board[row][col] = 'Q';
                backtrack(row+1, board, ans, diag, cols, anti_diag, r);
                board[row][col] = '.';
                cols.erase(col); diag.erase(d); anti_diag.erase(a);
            }
        }
    }
};
