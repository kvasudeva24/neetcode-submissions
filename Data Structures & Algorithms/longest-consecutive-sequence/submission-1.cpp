class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int max_seq = 0;
        set<int> set_nums = {nums.begin(), nums.end()};

        for ( int num : nums ) {
            int cur = 1;
            if ( !set_nums.count(num-1) ) {
                while ( set_nums.count(num+1) ) { num++; cur++; }
                max_seq = max(max_seq, cur);
            }
        }

        return max_seq;

    }
};
