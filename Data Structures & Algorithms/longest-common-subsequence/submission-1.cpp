class Solution {
public:
    vector<vector<int>> subsequences;
    int m;
    int n;
    string s;
    string t;

    int longestCommonSubsequence(string text1, string text2) {
        m = text1.size();
        s = text1;
        n = text2.size();
        t = text2;

        subsequences = vector(m, vector(n, -1));
        return longestSub(0, 0);
    }

    int longestSub(int i, int j) {
        if ( (i == m) || (j == n) ) { return 0; }

        if ( subsequences[i][j] != -1 ) { return subsequences[i][j]; }

        int ans = 0;
        if ( s[i] == t[j] ) {
            ans += longestSub(i+1, j+1);
            ans += 1;
        } else {
            ans += max(longestSub(i+1, j), longestSub(i, j+1));
        }

        subsequences[i][j] = ans;
        return ans;
    }



    /*
    longestSubsequence(i, j) = the longest common subsequence between strings s[i...n] and t[j...m]

    base case:
        if i > n and j > m return 0

        else 
            1 + longestSubsequence(i+1, j+1)

        else 
            max(longest(i+1, j), longest(i, j+1))

    */
};
