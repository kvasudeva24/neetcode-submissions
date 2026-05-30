class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = 0;
        int left = 0;
        unordered_map<char, int> char_map;

        for ( int right = 0; right < s.size(); right++ ) {
            char_map[s[right]]++;

            if ( char_map[s[right]] > 1 ) {
                cout << s[right] << "triggered" << endl;
                while ( char_map[s[right]] > 1 ) {
                    char_map[s[left]]--;
                    left++;
                }
            }
            len = max(len, right - left + 1);
            cout << len << endl;
        }
        return len;
    }
};
