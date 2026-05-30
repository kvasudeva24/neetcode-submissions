class Solution {
public:
    vector<vector<int>> memo;
    string ss; 
    string tt;

    int numDistinct(string s, string t) {
        this->ss = s;
        this->tt = t;

        memo = vector(s.size(), vector(t.size(), -1));

        return dp(0,0);
    }

    int dp(int i, int j){
        if(j == tt.size()) return 1;
        if(i == ss.size()) return 0;

        if(memo[i][j] != -1) return memo[i][j];

        int ans = dp(i+1, j);

        if(ss[i] == tt[j]){
            ans += dp(i+1, j+1);
        }

        memo[i][j] = ans;
        return ans;

    }
};
