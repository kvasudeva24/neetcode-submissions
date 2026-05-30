class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0; int ans = 0;
        map<char, int> count;
        for(int right = 0; right<s.size(); right++){
            count[s[right]]++;


            if(count[s[right]] > 1){
                while(count[s[right]] > 1){
                    count[s[left]]--;
                    left++;
                }
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
