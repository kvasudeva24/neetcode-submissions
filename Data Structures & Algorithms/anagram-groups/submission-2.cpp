class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> anagrams;

        for(string s : strs){
            vector<int> freq(26, 0);
            for(char c : s){
                freq[c-97]++;
            }
            anagrams[freq].push_back(s);
        }

        vector<vector<string>> ans;
        for(const auto [v, words] : anagrams){
            cout << words.size() << endl;
            ans.push_back(words);
        }
        return ans;
    }
};
