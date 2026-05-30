class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<string, vector<string>> result;
        for(const auto& s: strs){
            vector<int> count(26, 0);
            for(char c : s){
                count[c-'a']++;
            }
            string key = to_string(count[0]);
            for(int i = 1; i<26; i++){
                key += ',' + to_string(count[i]);
            }
            result[key].push_back(s);
        }
        vector<vector<string>> out;
        for(const auto& pair : result){
            out.push_back(pair.second);
        }
        return out;
    }
};
