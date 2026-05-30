class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> bank(26,0);
        for ( const char& c : s1 ) {
            bank[c - 97]++;
        }

        vector<int> counter(26,0);
        int left = 0;

        for ( int right = 0; right < s2.size(); right++ ) {
            char c = s2[right];



            //it is not in the bank
            if ( bank[c-97] == 0 ) {
                counter = vector(26,0);
                left = right;
                continue;
            }

            counter[c-97]++;
            cout << right << endl;

            if ( counter[c-97] == bank[c-97] ) {
                if ( bank == counter ) { return true; }
            } else {
                cout << "while" << endl;
                while ( counter[c-97] > bank[c-97] ) {
                    cout << counter[s2[left] - 97] << endl;
                    counter[s2[left] - 97]--;
                    cout << counter[s2[left] - 97] << endl;
                    left++;
                }
            }

        }

        return false;
    }
};
