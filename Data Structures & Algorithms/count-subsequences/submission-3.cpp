class Solution {
public:
    string s;
    string t;
    vector<vector<int>> numSequences;

    int numDistinct(string s, string t) {
        this->s = s;
        this->t = t;
        numSequences = vector(s.size(), vector(t.size(), -1));

        return distinctSubsequences(0, 0);
    }

    int distinctSubsequences(int i, int j) {
        if ( j >= t.size() ) { return 1; }

        if ( i >= s.size() ) { return 0; }

        if ( numSequences[i][j] != -1 ) { return numSequences[i][j]; }

        int skip = distinctSubsequences(i+1, j);
        int ans = skip;

        if ( s[i] == t[j] ) {
            ans = distinctSubsequences(i+1, j+1) + skip;
        } 

        numSequences[i][j] = ans;
        return ans;
    }


    /*
    distinctSubsequences(i, j) = the number of distinct subsequences in s[i...n] which 
                                 are equal to t[j...m]


        1      if j is OoB
        0      if i is OoB

        1 + distinctSubsequences(i+1, j+1)      if chars match
        1 + distinctSubsequences(i+1, j)        if we want to skip
        distinctSubsequences(i+1, j)            if they do not match




    */
};
