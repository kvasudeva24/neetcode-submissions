class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if ( k == 1 ) return nums;

        vector<int> ans;
        deque<pair<int,int>> window;

        for ( int i = 0; i < k; i++ ) {
            while ( !window.empty() && nums[i] > window.back().first ){
                window.pop_back();
            }
            window.push_back({nums[i], i});
        }

        ans.push_back(window.front().first);

        for ( int i = k; i < nums.size(); i++ ) {
            if ( window.front().second + k == i ) { window.pop_front(); }

            while ( !window.empty() && nums[i] > window.back().first ){
                    window.pop_back();
                }
            window.push_back({nums[i], i});
            ans.push_back(window.front().first);
        }

        return ans;



    }
};
