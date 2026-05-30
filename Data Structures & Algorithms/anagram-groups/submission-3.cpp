class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<vector<string>> ans;
        map<vector<int>, vector<string>> anagram_map;

        for ( const auto& str : strs ) {
            vector<int> char_count(26,0);
            for ( char c : str ){
                char_count[c - 97]++;
            } 
            anagram_map[char_count].push_back(str);
        }

        for ( const auto& [key, value] : anagram_map) ans.push_back(value);
        return ans;

    }
};
