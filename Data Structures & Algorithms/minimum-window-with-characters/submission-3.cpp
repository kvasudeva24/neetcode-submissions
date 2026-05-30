class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> t_map;
        for ( char c : t ) {
            t_map[c]++;
        }

        unordered_map<char, int> window;

        int needed = t_map.size();
        int have = 0;
        int left = 0;
        int right = 0;
        int l_temp = 0;
        int r_temp = INT_MAX;
        
        for ( ; right < s.size(); right++ ) {
            if ( t_map.count(s[right]) == 1 ) {
                if ( ++window[s[right]] == t_map[s[right]] ) have++;
                if ( have == needed ) {

                    if ( r_temp == INT_MAX || r_temp - l_temp > right - left ) {
                        r_temp = right;
                        l_temp = left;
                    }


                    while ( have == needed ) {
                        if ( r_temp == INT_MAX || r_temp - l_temp > right - left ) {
                            r_temp = right;
                            l_temp = left;
                        }
                        if ( t_map.count(s[left]) == 1 ) {
                            window[s[left]]--;
                            //"ADOBECODEBANC"
                            if ( window[s[left]] < t_map[s[left]]) have--;
                        }
                        left++;
                    }
                }
            }
        }
        return (r_temp == INT_MAX) ? "" : s.substr(l_temp, r_temp - l_temp + 1);
    }
};
