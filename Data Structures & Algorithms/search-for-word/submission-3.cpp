class Solution {
public:
    int m;
    int n;
    vector<vector<char>> board;
    string target;
    vector<pair<int, int>> nextMoves = {{0,1}, {1,0}, {0, -1}, {-1, 0}};

    bool exist(vector<vector<char>>& board, string word) {
        //initialize globals
        m = board.size();
        n = board[0].size();
        this->board = board;
        target = word;

        //start board search 
        for ( int r = 0; r < m; r++ ) {
            for ( int c = 0; c < n; c++ ) {

                //now walk 
                if ( board[r][c] == word[0] ) {
                    bool found = false;
                    set<pair<int, int>> seen;
                    seen.insert({r, c});
                    findWord(1, r, c, seen, found);
                    if ( found ) { return found; }
                }

            }   
        }
        return false;
    }

    void findWord(int i, int row, int col, set<pair<int, int>>& seen, bool& found) {
        // if i == size, we have found the word
        if ( i == target.size() ) {
            found = true;
            return;
        }

        //go thru the next 4 moves we can make
        for ( auto [dx, dy] : nextMoves ) {
            int nR = row + dy;
            int nC = col + dx;

            //if it is in bounds and the corr char is the next letter, GO
            if ( (inBounds(nR, nC)) && (board[nR][nC] == target[i]) && (!seen.count({nR, nC})) ) {
                seen.insert({nR, nC});
                findWord(i+1, nR, nC, seen, found);
                seen.erase({nR, nC});
            }

        }

    }


    inline bool inBounds(const int& r, const int& c) {
        return ((r >= 0) && (r < m) && (c >= 0) && (c < n));
    }
};
