class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> counter;
        int len = 1;
        int left = 0; counter[s[left]] = 1;

        for(int right = 1; right<s.size(); right++){
            if(++counter[s[right]] > 1){
                while(counter[s[right]] > 1){
                    counter[s[left]]--;
                    left++;
                }
            }
            len = max(len, right - left + 1);
        }
        return (s.empty()) ? 0 : len;
    }
};
