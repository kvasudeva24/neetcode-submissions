class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> t_map;
        unordered_map<char, int> window;
        for ( const auto& c : t ) {
            t_map[c]++;
        }
        int need = t.size();

        int have = 0;
        
        int left = 0;
        int l_ans = 0;
        int r_ans = 1001;


        for ( int right = 0; right < s.size(); right++ ) {
            if ( t_map.count(s[right]) == 0 && window.empty() ) { left++; continue; }


            if ( t_map.count(s[right]) == 1 ) {
                window[s[right]]++;
                if ( window[s[right]] == t_map[s[right]]) { have += t_map[s[right]]; }
                if ( have == need ) {
                    if ( r_ans == 1001 || (right - left + 1) < (r_ans - l_ans + 1) ) {
                        l_ans = left;
                        r_ans = right;
                    }

                    while ( have == need ) {
                        if ( (right - left + 1) < (r_ans - l_ans + 1) ) {
                            l_ans = left;
                            r_ans = right;
                        }
                        if ( t_map.count(s[left]) == 1) { 
                            window[s[left]]--;
                            if ( window[s[left]] < t_map[s[left]]) { have -= t_map[s[right]]; }
                        }
                        left++;
                    }
                }
            }
        }
        cout << l_ans << r_ans << endl;
        return ( r_ans == 1001 ) ? "" : s.substr(l_ans, r_ans - l_ans + 1);
    }
};
