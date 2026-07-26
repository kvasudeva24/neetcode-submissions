class Solution {
public:
    string S;
    string P;
    
    vector<vector<int>> matches;

    bool isMatch(string s, string p) {
        matches = vector(s.size(), vector(p.size(), -1));
        this->S = s;
        this->P = p;

        return RegExMatch(0, 0);
    }

    int RegExMatch(int i, int j) {

        if ( i == S.size() && j >= P.size() ) { return 1; }
        if ( i == S.size() && j + 2 == P.size() && P[j+1] == '*' ) { return 1; }
        if ( i == S.size() || j == P.size() ) { return 0; }

        if ( matches[i][j] != -1 ) { return matches[i][j]; }

        int match = 0;

        if ( !isSpecial(P, j) ) {

            if (P[j] == S[i]) {
                cout << "Matched " << i << " and " << j << endl;
                match = RegExMatch(i+1, j+1);
            }

            if ( j + 1 != P.size() && P[j+1] == '*') {
                match = max(match, RegExMatch(i, j+2));
            }

            matches[i][j] = match;
            return match;
        }

        if ( isSpecial(P, j) ) {
            
            if (P[j] == '.') {
                match = RegExMatch(i+1, j+1);
            } else {

                if ( (S[i] == P[j-1]) || (P[j-1] == '.') ) {
                    match = RegExMatch(i+1, j+1) || RegExMatch(i+1, j) || RegExMatch(i, j+1);
                } else {
                    match = RegExMatch(i, j+1);
                }
            }

            matches[i][j] = match;
            return match;
        }
    }

    bool isSpecial(string s, int i) {
        return ( (s[i] == '.') || (s[i] == '*') );
    }
};
