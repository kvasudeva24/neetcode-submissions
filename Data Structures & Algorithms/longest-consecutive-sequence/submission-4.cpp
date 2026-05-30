class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> nums_set(nums.begin(), nums.end());

        int ans = 0;

        for ( int num : nums_set ) {
            int cur = 1;
            if ( nums_set.count(num+1) ) {
                int iter = num+2;
                cur = 2;
                while( nums_set.count(iter) ) {
                    iter++;
                    cur++;
                }
            }
            ans = max(ans, cur);
        }
        return ans;    
    }
};
