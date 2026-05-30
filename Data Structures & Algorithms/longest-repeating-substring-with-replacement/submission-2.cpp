class Solution {
public:
    unordered_map<char, int> char_map;

    int characterReplacement(string s, int k) {
        
        int len = 0;
        int left = 0;

        int x = k;

        for ( int right = 0; right < s.size(); right++ ) {
            char_map[s[right]]++;

            int maxF = findMax();

            if ( maxF + k < right - left + 1) {
                while ( maxF + k < right - left + 1 ) {
                    char_map[s[left]]--;
                    left++;
                }
            }
            len = max(len, right - left + 1);
        }
        return len;
    }

    int findMax() {
        int maxF = 0;

        for ( const auto [_, f] : char_map ) {
            maxF = max(maxF, f);
        }

        return maxF;
    }
};
