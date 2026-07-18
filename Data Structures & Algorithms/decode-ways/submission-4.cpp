class Solution {
public:
    string s;
    vector<int> totalWays;

    int numDecodings(string s) {
        this->s = s;
        totalWays = vector(s.size(), -2);


        int ways = numWays(0);
        return (ways == -1 ) ? 0 : ways;
    }


    int numWays(int i) {
        if ( i >= s.size() ) { return 0; }

        if ( s[i] == '0' ) { return -1; }

        if ( i == s.size() - 1 ) { return 1; }

        if ( totalWays[i] != -2 ) { return totalWays[i]; }

        int take1 = numWays(i+1);
        int take2 = -1;
        
        if ( firstValid(i) ) {
            if ( (s[i] == '2') && (!secondValid(i+1)) ) {
                take2 = -1;
            } else {
                take2 = numWays(i+2);
            }
        }
        cout << take2 << endl;

        int total = 0;
        if ( (take1 != -1) && (take2 != -1) ) {
            total =  take1 + take2;
            if ( (take1 == 0) || (take2 == 0) ) {
                total+=1;
            }

        } else {
            total = max(take1, take2);
            if ( (take1 == 0) || (take2 == 0) ) {
                total+=1;
            }
        }

        totalWays[i] = total;
        return total;

    }


    bool firstValid(int i) {
        return ((s[i] == '1') || (s[i] == '2'));
    }

    bool secondValid(int i) {
        return ((s[i] != '7') && (s[i] != '8') && (s[i] != '9'));
    }
};

