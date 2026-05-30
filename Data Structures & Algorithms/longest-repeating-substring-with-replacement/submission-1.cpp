class Solution {
public:
    int characterReplacement(string s, int k) {
        map<int, int> count;
        int left = 0;
        int ans = 1;

        for(int right = 0; right<s.size(); right++){
            count[s[right]]++;

            int maxF = findMax(count);

            if(right - left + 1 > maxF + k){
                while(right - left + 1 > maxF + k){
                    count[s[left]]--;
                    left++;
                    // maxF = findMax(count);
                }
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }

    inline int findMax(const map<int, int>& count){
        int ans = INT_MIN;
        for(const auto [lett, freq] : count){
            ans = max(ans, freq);
        }
        return ans;
    }
};
