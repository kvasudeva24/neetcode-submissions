class Solution {
public:
    vector<vector<int>> memo;
    string w1;
    string w2;

    int minDistance(string word1, string word2) {
        this->memo = vector(word1.size()+1, vector(word2.size() + 1, 201));
        this->w1 = word1;
        this->w2 = word2;
        
        return dp(0,0);
    }

    int dp(int i, int j){
        if(i == w1.size() && j == w2.size()) return 0;
        if(i == w1.size()) return w2.size() - j;
        if(j == w2.size()) return w1.size() - i;

        if(memo[i][j] != 201) return memo[i][j];

        int ans = 0;
        //min of insert, delete, and next(if equal)
        int insert = 1 + dp(i, j+1);
        int del = 1 + dp(i+1, j);
        int replace = 1 + dp(i+1, j+1);

        int skip = INT_MAX;
        if(w1[i] == w2[j]) skip = dp(i+1, j+1);
        

        ans = min(min(insert, del), min(skip, replace));

        memo[i][j] = ans;
        return ans;
    }
};
